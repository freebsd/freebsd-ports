# Yabb port maintener script
# This script was designed to be executed by the port maintainer to generate
# the yabb port pkg_plist and checksum.sha256 files when updating the port
#######

rm files/ checksum.sha256
rm pkg-plist

YABB_DIR="/usr/local/www/yabb/"

for file in `cd ${YABB_DIR} ; find Members Messages Templates  Variables  -type f | egrep -v "(gif|png)" ; echo Paths.pl `
do
	echo -n "@unexec i='" >> pkg-plist
	echo -n $file >> pkg-plist
	echo -n "'" >> pkg-plist
	echo -n '; cd %D/%%YABBDIR%% && if [ k`sha256 -q $i` = k`grep ' >> pkg-plist
	echo '"$i\$" checksum.sha256 | cut -c-64` ]; then rm -f $i; fi' >> pkg-plist
	
	(cd ${YABB_DIR}  ; sha256 -r $file ) >> files/checksum.sha256 
done

for file in `cd ${YABB_DIR} ; find Admin Attachments Backups Boards Buttons Help Languages ModImages Smilies Sources avatars googiespell greybox shjs -type f`
do
	echo "%%YABBDIR%%/${file}" >> pkg-plist
done 

for file in `cd ${YABB_DIR} ; find Members Messages Templates  Variables  -type f | egrep "(gif|png)" `
do
	echo "%%YABBDIR%%/${file}" >> pkg-plist
done

for file in `cd ${YABB_DIR} ; find . -depth 1 -type f | grep -v Paths.pl | sed 's/^\.\///'`
do
	echo "%%YABBDIR%%/${file}" >> pkg-plist
done

for file in `cd ${YABB_DIR} ; find .  -type d | sed 's/^\.//' | sort -r`
do
	echo "@dirrmtry %%YABBDIR%%${file}" >> pkg-plist
done



echo "@dirrmtry %%YABBDIR%%" >> pkg-plist


echo '@unexec if [ -d %D/%%YABBDIR%% ]; then echo "================================================"; fi' >> pkg-plist
echo '@unexec if [ -d %D/%%YABBDIR%% ]; then echo "Note: %D/%%YABBDIR%% was not deleted." ; fi'           >> pkg-plist
echo '@unexec if [ -d %D/%%YABBDIR%% ]; then echo "Backup your data and remove it yourself, please."; fi' >> pkg-plist
echo '@unexec if [ -d %D/%%YABBDIR%% ]; then echo "================================================"; fi' >> pkg-plist




