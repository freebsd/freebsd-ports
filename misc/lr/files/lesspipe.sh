#! /bin/sh
# ex:ts=8

# $FreeBSD: /tmp/pcvs/ports/misc/lr/files/lesspipe.sh,v 1.1 2003-04-13 10:43:20 edwin Exp $

case "$1" in
	*.Z)	uncompress -c $1	2>/dev/null
		;;
	*.gz)	gzip -d -c $1		2>/dev/null
		;;
	*.bz2)	bzip2 -d -c $1		2>/dev/null
		;;
esac
