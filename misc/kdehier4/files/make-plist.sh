#!/bin/sh
if [ ! -e dirlist -o ! -e ../Makefile ]; then
	echo "Wrong directory; this script needs to be called from"
	echo "/usr/ports/misc/kde4hier/files !"
	exit 1
fi

(
grep -v "^@comment" dirlist | sed -e "s,$,/.keep_me," ;
grep -v "^@comment" mtree-dirlist | sed -e "s,$,/.keep_me,; s,^,%%MTREE%%,"
)| sort | uniq > ../pkg-plist
(
grep -v "^@comment" dirlist | sed -e "s,^,@dirrmtry ," ;
grep -v "^@comment" mtree-dirlist | sed -e "s,^,%%MTREE%%@dirrm ,"
)| sort -r | uniq >> ../pkg-plist
