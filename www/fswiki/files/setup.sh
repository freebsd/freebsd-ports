#!/bin/sh
#
# setup_fswiki: a script for setup the current directory for fswiki
#
# Stolen from: FreeBSD: ports/www/aswiki/files/setup.sh,v 1.2 2003/06/20 10:46:30 matusita Exp
#
# $FreeBSD$

ask_noyes()
{
	local key

	echo -n "$1 [y/N]: "
	read key
	case "$key" in
	[Yy]*)
		return 0;;
	*)
		return 1;;
	esac
} 

ask_copy()
{
	local file ans
	file=$1

	if [ -f ./$file ]; then
		if ask_noyes "Overwrite $file?"; then
			ans=YES
		else
			ans=NO
		fi
	else
		ans=YES
	fi
	if [ $ans = "YES" ]; then
		install -m 644 __DATADIR__/$file $file
	else
		echo "$file is untouched; you may update with __DATADIR__/$file."
	fi
}

echo "This script will setup current directory for fswiki."
if ask_noyes "Are you ready?"; then
	echo -n "Creating directories..."
	mkdir backup config data log
	echo "done."
	echo -n "Copying files..."
	ask_copy config/config.dat
	ask_copy config/farmconf.dat
	ask_copy config/mime.dat
	ask_copy config/plugin.dat
	ask_copy config/user.dat
	ask_copy config/usercss.dat
	ask_copy data/FrontPage.wiki
	ask_copy data/Help%2FFSWiki.wiki
	ask_copy data/Help%2FHiki.wiki
	ask_copy data/Help%2FYukiWiki.wiki
	ask_copy data/Help.wiki
	ask_copy setup.dat
	ask_copy wiki.cgi
	chmod +x wiki.cgi
	ln -sf __DATADIR__/docs
	ln -sf __DATADIR__/lib
	ln -sf __DATADIR__/plugin
	ln -sf __DATADIR__/theme
	ln -sf __DATADIR__/tmpl
	echo "done."
else
	echo "Stopped."
	exit 1
fi
