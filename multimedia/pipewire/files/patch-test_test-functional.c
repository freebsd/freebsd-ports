--- test/test-functional.c.orig	2023-10-06 09:37:06 UTC
+++ test/test-functional.c
@@ -4,6 +4,8 @@
 
 #include "config.h"
 
+#include <sys/wait.h>
+
 #include "pwtest.h"
 
 PWTEST(openal_info_test)
