--- libexslt/crypto.c.orig	Wed May  3 20:42:12 2006
+++ libexslt/crypto.c	Wed May  3 20:42:41 2006
@@ -318,6 +318,7 @@ exsltCryptoCryptoApiRc4Decrypt (xmlXPath
 #define PLATFORM_SHA1 GCRY_MD_SHA1
 
 #ifdef HAVE_SYS_SELECT_H
+#include <sys/types.h>
 #include <sys/select.h>		/* needed by gcrypt.h 4 Jul 04 */
 #endif
 #include <gcrypt.h>
