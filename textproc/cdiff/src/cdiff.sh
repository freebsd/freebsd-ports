#!/bin/sh
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
fi) | perl -pe '
while (s/\t/" " x (8 - ((length($`)-1) % 8))/e) {}
s/^(\+.*)$/\033[31m$1\033[m/o;
s/^(-.*)$/\033[34m$1\033[m/o
	if !s/^(--- \d+,\d+ ----.*)$/\033[1m$1\033[m/o;
s/^(\*\*\* \d+,\d+ *\*\*\*.*)$/\033[1m$1\033[m/o;
s/^(\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*)$/\033[1m$1\033[m/o;
s/^(!.*)$/\033[35m$1\033[m/o;
s/^(@@.*$)/\033[1m$1\033[m/o;
if (/^1.(\d+)(\s+\(\w+\s+\d{2}-\w{3}-\d{2}\):\s)(.*)/) {
	$lastcol = $lastcol || 0;
	$lastcol++ if defined($lastrev) && $lastrev != $1;
	$lastrev = $1;
	$lastcol %= 6;
	$_ = "\033[3" . ($lastcol + 1) . "m1.$1$2\033[m$3\n";
}
' | less -R
