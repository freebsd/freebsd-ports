--- licence.c.orig	2004-07-31 17:07:41.000000000 +0400
+++ licence.c	2004-12-15 10:19:42.000000000 +0300
@@ -21,7 +21,7 @@
 #include "rdesktop.h"
 #include <openssl/rc4.h>
 
-extern char g_username[16];
+extern char g_username[64];
 extern char g_hostname[16];
 
 static uint8 g_licence_key[16];
diff -uNr rdesktop.c.orig rdesktop.c
