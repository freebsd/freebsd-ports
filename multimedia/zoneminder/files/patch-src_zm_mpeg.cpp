--- src/zm_mpeg.cpp.orig	2009-05-25 22:04:00.000000000 +0400
+++ src/zm_mpeg.cpp	2011-04-08 17:48:07.391806718 +0400
@@ -19,7 +19,7 @@
 
 #include <stdlib.h>
 #include <string.h>
-
+#include <errno.h> 
 #include "zm.h"
 #include "zm_mpeg.h"
 
