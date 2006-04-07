--- misc/libmap.conf-FreeBSD4.x.old	Fri Apr  7 15:52:30 2006
+++ misc/libmap.conf-FreeBSD4.x	Fri Apr  7 15:52:56 2006
@@ -33,7 +33,7 @@
 
 #######################################################
 # Acrobat7 with Mozilla/Firebird/Galeon/Epiphany/Konqueror/Kazehakase
-[/usr/compat/linux/usr/local/Adobe/Acrobat7.0/Browser/intellinux/nppdf.so]
+[/usr/X11R6/Adobe/Acrobat7.0/ENU/Browser/intellinux/nppdf.so]
 libc.so.6			pluginwrapper/acrobat.so
 
 # Japanese Acrobat7 with Mozilla/Firebird/Galeon/Epiphany/Konqueror/Kazehakase
@@ -46,6 +46,8 @@
 [/usr/X11R6/lib/linux-mozilla/plugins/nphelix.so]
 libstdc++.so.5			libstdc++.so.3
 libc.so.6			pluginwrapper/realplayer.so
+libm.so.6			libm.so.2
+libgcc_s.so.1			pluginwrapper/realplayer.so
 
 
 #######################################################
