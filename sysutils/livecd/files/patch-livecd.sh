--- livecd.sh.orig	Fri Dec 17 20:02:55 2004
+++ livecd.sh	Fri Dec 17 20:03:21 2004
@@ -302,7 +302,7 @@
         /usr/local/bin/mkisofs -b boot/cdboot -no-emul-boot -c boot/boot.catalog  -r -l -L -V LiveCD -o $LIVEISODIR/LiveCD.iso . >> $LIVEDIR/log || aviso
 	dialog --title "FreeBSD LiveCD" --msgbox "$i_dialogo_1" 5 60
 
-elif then
+else
         
 	dialog --title "FreeBSD LiveCD" --msgbox "$i_dialogo_2" 5 75
 	#
@@ -578,7 +578,7 @@
 do
 if [ -f ./config.ok ] ; then
 	main_dialog
-elif then
+else
 	idioma
 fi
 done
