--- include/apc.h.orig	2015-02-17 20:18:17 UTC
+++ include/apc.h
@@ -148,13 +148,7 @@
 /* System includes conditionally included */
 
 #ifdef HAVE_LIBWRAP
-# ifdef __cplusplus
-   extern "C" {
-# endif
-# include <tcpd.h>
-# ifdef __cplusplus
-   };
-# endif
+# include "tcpd.h"
 #endif
 
 #endif
