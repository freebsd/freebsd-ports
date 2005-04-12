#!/bin/sh
if [ "$1" = "-m" ]; then
	shift;
	CODES="4:7:1:1"
else
	CODES="1:34:31:35"
fi
(if [ "$1" != "" ]; then
    while [ "$1" != "" ]; do
    	case $1 in
    	http:*|https:*|ftp:*|file:*)
            fetch -q -o - $1
	    ;;
    	*)
            zcat -f $1
	    ;;
        esac
	shift;
    done
else
	cat
fi) | perl -p -mconstant=CODES,${CODES} -e '
($at, $m, $p, $c) = split /:/, CODES;
while (s/\t/" " x (8 - ((length($`)-1) % 8))/e) {}
s/^(\+.*)$/\033[${p}m$1\033[0m/o;
s/^(-.*)$/\033[${m}m$1\033[0m/o
	if !s/^(--- \d+,\d+ ----.*)$/\033[1m$1\033[0m/o;
s/^(\*\*\* \d+,\d+ *\*\*\*.*)$/\033[1m$1\033[0m/o;
s/^(\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*)$/\033[1m$1\033[0m/o;
s/^(!.*)$/\033[${c}m$1\033[0m/o;
s/^(@@.*$)/\033[${at}m$1\033[0m/o;
if (/^1.(\d+)(\s+\(\w+\s+\d{2}-\w{3}-\d{2}\):\s)(.*)/) {
	$lastcol = $lastcol || 0;
	$lastcol++ if defined($lastrev) && $lastrev != $1;
	$lastrev = $1;
	$lastcol %= 6;
	$_ = "\033[3" . ($lastcol + 1) . "m1.$1$2\033[0m$3\n";
}
' | less -R
