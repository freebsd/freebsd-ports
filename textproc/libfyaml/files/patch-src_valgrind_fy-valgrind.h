--- src/valgrind/fy-valgrind.h.orig	2022-11-03 06:38:06 UTC
+++ src/valgrind/fy-valgrind.h
@@ -19,7 +19,7 @@
 #include <getopt.h>
 #include <unistd.h>
 #include <limits.h>
-#include <alloca.h>
+#include <stdlib.h>
 #include <stdio.h>
 
 enum fy_valgrind_tool {
