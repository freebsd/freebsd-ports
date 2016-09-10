--- main/crypt.c.orig	2016-07-21 14:54:02 UTC
+++ main/crypt.c
@@ -31,7 +31,7 @@
 ASTERISK_FILE_VERSION(__FILE__, "$Revision$")
 
 #include <unistd.h>
-#if defined(HAVE_CRYPT_R)
+#if defined(HAVE_CRYPT_R) && !defined(__FreeBSD__)
 #include <crypt.h>
 #endif
 
