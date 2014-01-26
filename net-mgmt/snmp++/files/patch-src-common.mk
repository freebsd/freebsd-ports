--- ./common.mk.orig	2011-05-26 22:23:19.000000000 -0400
+++ common.mk	2011-05-26 22:23:37.000000000 -0400
@@ -65,7 +65,7 @@
 # Installation directories
 #
 ifndef INSTPREFIX
-INSTPREFIX	= /usr/local
+INSTPREFIX	= $(PREFIX)
 endif

 ifndef INSTLIBPATH
