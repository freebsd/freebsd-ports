--- libexslt/crypto.c.orig	Mon Jul  5 19:33:58 2004
+++ libexslt/crypto.c	Mon Jul  5 19:35:25 2004
@@ -315,6 +315,8 @@
 #define PLATFORM_MD5 GCRY_MD_MD5
 #define PLATFORM_SHA1 GCRY_MD_SHA1
 
+#include <sys/types.h>
+#include <sys/time.h>
 #include <sys/select.h>		/* needed by gcrypt.h 4 Jul 04 */
 #include <gcrypt.h>
 
