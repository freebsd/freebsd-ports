--- ./lib/granite.pc.cmake.orig	2013-08-10 02:01:58.000000000 +0000
+++ ./lib/granite.pc.cmake	2013-11-20 23:13:44.000000000 +0000
@@ -8,5 +8,5 @@
 Version: @PKG_VERSION@
 Libs: -L@DOLLAR@{libdir} -l@PKG_NAME@
 Cflags: -I@DOLLAR@{includedir}/@PKG_NAME@
-Requires: cairo gee-1.0 glib-2.0 gio-unix-2.0 gobject-2.0 gthread-2.0 gdk-3.0 gdk-pixbuf-2.0 gtk+-3.0
+Requires: cairo @GEE_PACKAGE@ glib-2.0 gio-unix-2.0 gobject-2.0 gthread-2.0 gdk-3.0 gdk-pixbuf-2.0 gtk+-3.0
 
