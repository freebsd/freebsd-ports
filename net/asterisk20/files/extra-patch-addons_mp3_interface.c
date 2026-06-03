--- addons/mp3/interface.c.orig	2014-09-26 15:56:47 UTC
+++ addons/mp3/interface.c
@@ -1,4 +1,5 @@
 #define WRAP_LIBC_MALLOC
+#define ASTMM_LIBC ASTMM_REDIRECT
 #include "asterisk.h"
 #include "asterisk/logger.h"
 
