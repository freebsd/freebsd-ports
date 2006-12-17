--- ./src/crypto/sha1.h.orig	Mon Dec  6 09:32:07 2004
+++ ./src/crypto/sha1.h	Sun Nov 26 21:56:00 2006
@@ -15,7 +15,7 @@
 #include <stdint.h>
 #include <string>
 
-#include "endian.h"
+#include "myendian.h"
 
 using std::string;
 
