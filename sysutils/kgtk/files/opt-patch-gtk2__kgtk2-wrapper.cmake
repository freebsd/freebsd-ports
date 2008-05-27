--- ../gtk2/kgtk2-wrapper.cmake.orig	2007-10-31 22:33:19.000000000 +0200
+++ ../gtk2/kgtk2-wrapper.cmake	2008-05-04 22:49:28.000000000 +0300
@@ -11,6 +11,7 @@
 # Released under the GPL v2 or later
 # --
 #
+export G_BROKEN_FILENAMES=1
 
 app=`basename $0`
 
