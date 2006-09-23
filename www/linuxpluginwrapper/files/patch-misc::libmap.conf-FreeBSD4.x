--- misc/libmap.conf-FreeBSD4.x.orig	Thu Sep 15 00:44:51 2005
+++ misc/libmap.conf-FreeBSD4.x	Sat Sep 23 22:35:19 2006
@@ -2,14 +2,22 @@
 # $Id: libmap.conf-FreeBSD4.x,v 1.18 2005/09/14 15:44:51 nork Exp $
 
 #######################################################
-# Flash6 with Opera
-[/usr/X11R6/lib/browser_plugins/libflashplayer.so]
-libpthread.so.0			libc_r.so.4
-libdl.so.2			pluginwrapper/flash6.so
+# Flash7 with Mozilla
+[/usr/local/lib/npapi/linux-flashplugin/libflashplayer.so]
+libpthread.so.0			pluginwrapper/flash7.so
+libdl.so.2			pluginwrapper/flash7.so
 libz.so.1			libz.so.2
-libstdc++-libc6.2-2.so.3	libstdc++.so.3
 libm.so.6			libm.so.2
-libc.so.6			pluginwrapper/flash6.so
+libc.so.6			pluginwrapper/flash7.so
+
+#######################################################
+# Flash7 with Opera
+[/usr/local/lib/npapi/linux-flashplugin/libflashplayer.so]
+libpthread.so.0			pluginwrapper/flash7.so
+libdl.so.2			pluginwrapper/flash7.so
+libz.so.1			libz.so.2
+libm.so.6			libm.so.2
+libc.so.6			pluginwrapper/flash7.so
 [/usr/X11R6/share/opera/plugins/operamotifwrapper]
 libXm.so.1			libXm.so.3
 [/usr/X11R6/share/opera/plugins/operamotifwrapper-1]
@@ -17,23 +25,10 @@
 [/usr/X11R6/share/opera/plugins/operamotifwrapper-2]
 libXm.so.2			libXm.so.3
 
-# Flash6 with Konqueror
-# SEE ALSO: http://freebsd.kde.org/howtos/konqueror-flash.php
-# This configuration was integrated to following one.
-
-# Flash6 with Mozilla/Firebird/Galeon/Epiphany/Konqueror/Kazehakase
-[/usr/X11R6/lib/linux-flashplugin6/libflashplayer.so]
-libpthread.so.0			pluginwrapper/flash6.so
-libdl.so.2			pluginwrapper/flash6.so
-libz.so.1			libz.so.2
-libstdc++-libc6.2-2.so.3	libstdc++.so.3
-libm.so.6			libm.so.2
-libc.so.6			pluginwrapper/flash6.so
-
 
 #######################################################
 # Acrobat7 with Mozilla/Firebird/Galeon/Epiphany/Konqueror/Kazehakase
-[/usr/compat/linux/usr/local/Adobe/Acrobat7.0/Browser/intellinux/nppdf.so]
+[/usr/X11R6/Adobe/Acrobat7.0/ENU/Browser/intellinux/nppdf.so]
 libc.so.6			pluginwrapper/acrobat.so
 
 # Japanese Acrobat7 with Mozilla/Firebird/Galeon/Epiphany/Konqueror/Kazehakase
@@ -46,6 +41,8 @@
 [/usr/X11R6/lib/linux-mozilla/plugins/nphelix.so]
 libstdc++.so.5			libstdc++.so.3
 libc.so.6			pluginwrapper/realplayer.so
+libm.so.6			libm.so.2
+libgcc_s.so.1			pluginwrapper/realplayer.so
 
 
 #######################################################
