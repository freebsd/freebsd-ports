#!/bin/sh
if [ ! -e dirlist -o ! -e ../Makefile ]; then
	echo "Wrong directory; this script needs to be called from"
	echo "/usr/ports/misc/kdehier/files !"
	exit 1
fi

grep -v "^@comment" dirlist | sed -e "s,$,/.keep_me," | sort | uniq > ../pkg-plist
grep -v "^@comment" dirlist | sed -e "s,^,@dirrm ," | sort -r | uniq >> ../pkg-plist
