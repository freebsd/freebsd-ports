#!/bin/sh
if [ ! -e dirlist -o ! -e ../Makefile ]; then
	echo "Wrong directory; this script needs to be called from"
	echo "/usr/ports/misc/kde4hier/files !"
	exit 1
fi


echo "%%MTREE%%%%LDCONFIG_DIR%%
%%MTREE%%%%LDCONFIG32_DIR%%
%%MTREE%%libdata/pkgconfig" > ../pkg-plist

(
grep -v "^@comment" dirlist | sed -e "s,^,@exec mkdir -p %D/," ;
grep -v "^@comment" mtree-dirlist | sed -e "s,^,%%MTREE%%@exec mkdir -p %D/,"
)| sort | uniq >> ../pkg-plist

(
grep -v "^@comment" dirlist | sed -e "s,^,@dirrmtry ," ;
grep -v "^@comment" mtree-dirlist | sed -e "s,^,%%MTREE%%@dirrm ,"
)| sort -r | uniq >> ../pkg-plist

echo "%%MTREE%%@exec echo %D/lib > %%LOCALBASE%%/%%LDCONFIG_DIR%%/kdehier4
%%MTREE%%@unexec [ -f %%LOCALBASE%%/%%LDCONFIG_DIR%%/kdehier4 ] && rm -f %%LOCALBASE%%/%%LDCONFIG_DIR%%/kdehier4  || true" >> ../pkg-plist
