--- ntlm/ntlmstruct.c.orig	Tue Jan 29 13:05:13 2002
+++ ntlm/ntlmstruct.c	Tue Jan 29 13:06:02 2002
@@ -25,7 +25,11 @@
 #include <config.h>
 #endif
 
+#ifdef __FreeBSD__
+#include <inttypes.h>
+#else
 #include <stdint.h>
+#endif
 #include <stdlib.h>
 #include <string.h>
 #include <assert.h>
