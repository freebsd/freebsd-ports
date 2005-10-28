#!/bin/sh

if [ -z "$1" ]; then
	echo 'Usage: s5-blank dirname'
	exit 1
fi
if [ -e "$1" ] && ! [ -d "$1/" ]; then
	echo "Not a directory: $1"
	exit 1
fi

[ ! -e "$1" ] && mkdir -p "$1"
cp -Rpv /usr/local/share/s5/s5-blank/ "$1"/
