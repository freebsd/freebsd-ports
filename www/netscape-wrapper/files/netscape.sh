#!/bin/sh
#
# Netscape Wrapper
#     (c) 1998,1999 Dave Cinege, H. Peter Anvin, and Red Hat, Inc.
#         2000 Akinori MUSHA <knu@FreeBSD.org>, modified for FreeBSD.
# 
# $FreeBSD$
#

prefix='%%PREFIX%%'

lockfile=$HOME/.netscape/lock
defs="-irix-session-management"
defsrem="-irix-session-management -noraise -remote"
b_opt="openBrowser"

netscape=$prefix/bin/netscape.run

if [ -x $prefix/bin/netscape-remote ]; then
	netscape_remote=$prefix/bin/netscape-remote
else
	netscape_remote=$netscape
fi

netscape_bin=""

for f in $prefix/lib/netscape*/*.bin
do
    if [ -x $f ]; then
	netscape_bin=$f
	break
    fi
done

if [ "$netscape_bin" = "" ]; then
    echo "You don't seem to have netscape installed."
    exit 1
fi

export TZ=:/etc/localtime

# Exterminate zombie netscapes, and wipe stale lock file.
killstale () {
    whoami=`whoami`

    ps uw | while read user pid pcpu pmem vsz rss tt stat started time command args
    do
	[ "$user" != "$whoami" -o "$command" != "$netscape_bin" ] && continue

	{ kill -INT $pid && kill -QUIT $pid && kill -TERM $pid && \
	    sleep 2 && kill -KILL $pid ; } >/dev/null 2>&1
    done

    [ -L $lockfile ] && rm $lockfile

    return 0
}

# Try calling existing netscape process with functions, else start one.
newbrowser () {
    [ $# -gt 0 ] && url=`echo $@ | sed 's/\ -[^ ]*//g; s/\( |	\)*//; s/,/%2C/g; s/(/%28/g; s/)/%29/g;'`
    if [ -L $lockfile ]; then
	if [ "$url" = "" ]; then
	    $netscape_remote $defsrem "xfeDoCommand($b_opt)" "$@" 2>/dev/null || \
		{ killstale && exec $netscape $defs $cl_opt "$@" ; }
	else
	    $netscape_remote $defsrem "openURL($url, new-window)"  2>/dev/null || \
		{ killstale && exec $netscape $defs "$@" ; }
	fi
    else
	if [ "$url" = "" ]; then
	    [ ${rerun:=0} -eq 1 ] && { sleep 3; $netscape_remote $defsrem "xfeDoCommand($b_opt)" '$@' 2>/dev/null ; } &
	    exec $netscape $defs $cl_opt "$@"
	else
	    exec $netscape $defs "$@"
	fi
    fi
}

newopt () {
    opt="$1"
    shift

    case "$opt" in
	"+news"|"+discussions") b_opt="openNewsgroups"	; cl_opt="-discussions" ;;
	"+mail"|"+messenger")	b_opt="openInbox"	; cl_opt="-messenger"	;;
	"+edit"|"+composer")	b_opt="openEditor"	; cl_opt="-composer"	;;
	"+addr"|"+addresses")	b_opt="openAddrBook"	; cl_opt="-messenger -iconic"	; rerun=1	;;
	"+hist"|"+history")	b_opt="openHistory"	; cl_opt="-iconic"		; rerun=1	;;
	"+book"|"+bookmarks")	b_opt="openBookmarks"	; cl_opt="-iconic"		; rerun=1	;;
	"+mailto")		b_opt="composeMessage"	; cl_opt="-messenger -iconic"	; rerun=1	;;
	"+component-bar")	b_opt="toggleTaskbar"	; cl_opt="-component-bar";;
    esac

    newbrowser "$@"
}

oldopt () {
    exec $netscape $defs "$@"
}

usage () {
    echo ""
    echo "Netscape Wrapper"
    echo "        (c) 1998,1999 Dave Cinege, H. Peter Anvin, and Red Hat, Inc."
    echo "            2000 Akinori MUSHA <knu@FreeBSD.org>, modified for FreeBSD."
    echo ""
    echo "usage: netscape [ option ]"
    echo "  options:"
    echo ""
    echo "    [none]                Open new browser"
    echo "    [URL]                 Open new browser with URL"
    echo "    +news | +discussions  Show Collabra Discussions"
    echo "    +mail | +messenger    Show Messenger Mailbox (INBOX)"
    echo "    +edit | +composer     Open Composer"
    echo "    +addr | +addresses    Show Address Book"
    echo "    +hist | +history      Open History window"
    echo "    +book | +bookmarks    Open Bookmarks windowsBook"
    echo "    +mailto               Open New Message window"
    echo "    +component-bar        Show (detach) Component Lauch Bar"
    echo "    -[option]             Passed directly to Netscape binary"
    echo ""
    echo "The wrapper first attempts to open the option in a running"
    echo "netscape. If no netscape is running, one is executed with"
    echo "the option as the starting window."
    echo ""
    echo "Edit the top of this file to set default paths."
    echo ""
    echo ""
    echo "Netscape binary help:"
    echo ""
    exec $netscape "-help"
}

#
# Fix "locale" problems when printing to postscript
#
# If the locale uses a decimal separator other than a point printf
# will return something other than 1.0
#

pnt=`printf "%1.1f" 1 2>/dev/null`
if [ "$pnt" != "1.0" ]; then
    export LC_NUMERIC=C		# Try a "safe" value for LC_NUMERIC.

    pnt=`printf "%1.1f" 1 2>/dev/null`
    if [ "$pnt" != "1.0" ]; then	#  LC_ALL is bad.
	LC_COLLATE=$LC_ALL	#  Set $LC_ALL for every category except
	LC_CTYPE=$LC_ALL	#  LC_NUMERIC, and then unset LC_ALL.
	LC_MESSAGES=$LC_ALL
	LC_MONETARY=$LC_ALL
	LC_TIME=$LC_ALL
	unset LC_ALL
	export LC_ALL LC_COLLATE LC_CTYPE LC_MESSAGES LC_MONETARY LC_CTIME
    fi
fi


# main

case "$1" in
    -h|-help|--help) usage;	exit	;;
    +*)	newopt "$@";		exit	;;
    -*)	oldopt "$@";		exit	;;
    *)	newbrowser "$@";	exit	;;
esac

echo "An error occurred running $netscape."
