diff -urN src/system.h.orig src/system.h
--- src/system.h.orig	2008-06-28 17:38:35.000000000 +0100
+++ src/system.h	2008-06-29 16:17:48.000000000 +0100
@@ -191,6 +191,8 @@
     })
 #endif
 
+#define offsetof(TYPE, MEMBER) ((int)&((TYPE *)0)->MEMBER)
+
 #include "bstrlib.h"
 
 #endif

