--- Decoder.cpp.orig	Wed Feb 25 13:46:10 2004
+++ Decoder.cpp	Sat Apr 17 23:14:45 2004
@@ -29,6 +29,8 @@
 
 #define PROTOTYPES
 
+#include <unistd.h>
+
 #include <stdlib.h>
 #include <stdio.h>
 #include <uudeview.h>
