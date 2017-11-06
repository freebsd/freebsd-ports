--- tests.c.orig	2017-10-26 09:00:30 UTC
+++ tests.c
@@ -17,7 +17,7 @@ main(void)
 }
 #endif /* TEST_ARC4RANDOM */
 #if TEST_CAPSICUM
-#include <sys/capability.h>
+#include <sys/capsicum.h>
 
 int
 main(void)
