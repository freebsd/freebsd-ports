--- src/libwsmake/wsLoader.cpp.orig	2013-11-20 16:09:13.000000000 +0100
+++ src/libwsmake/wsLoader.cpp	2013-11-20 16:09:22.000000000 +0100
@@ -24,6 +24,7 @@
 
 #include "osa.h"
 
+#include <stdlib.h>
 #include <unistd.h>
 #include <errno.h>
 
