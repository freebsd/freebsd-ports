--- headers.h.orig	2022-07-30 04:07:13 UTC
+++ headers.h
@@ -32,6 +32,7 @@
 #define	__need_sig_atomic_t	1
 #endif
 
+#include <stddef.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
