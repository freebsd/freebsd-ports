--- tests/test.h.orig	2026-11-01 09:42:15 UTC
+++ tests/test.h
@@ -61,6 +61,9 @@
 #define sscanf(...) sscanf_s(__VA_ARGS__)
 #endif
 
+#include <netinet/in.h>
+#include <sys/wait.h>
+
 /**
  * Test output is controlled through "TEST_LEVEL=N" environemnt variable.
  * N < 2: TEST_SAY() is quiet.
