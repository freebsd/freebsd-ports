--- src/madness/world/worldmem.h.orig	2018-08-27 07:36:33 UTC
+++ src/madness/world/worldmem.h
@@ -49,7 +49,7 @@
 #elif defined(ON_A_MAC)
 #include <malloc/malloc.h>
 #elif defined(X86_32)
-#include <malloc.h>
+#include <stdlib.h>
 #elif defined(X86_64)
 #include <sys/types.h>
 #include <unistd.h>
