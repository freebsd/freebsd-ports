--- liblua/liolib.c.orig	2016-07-02 17:02:27 UTC
+++ liblua/liolib.c
@@ -16,6 +16,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <unistd.h>
 
 #include "lua.h"
 
