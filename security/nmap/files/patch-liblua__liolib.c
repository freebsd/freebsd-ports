--- liblua/liolib.c.orig	2014-01-02 15:33:55 UTC
+++ liblua/liolib.c
@@ -19,6 +19,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <unistd.h>
 
 #define liolib_c
 #define LUA_LIB
