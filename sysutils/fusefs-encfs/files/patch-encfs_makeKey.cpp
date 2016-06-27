--- encfs/makeKey.cpp.orig	2015-03-24 20:45:16 UTC
+++ encfs/makeKey.cpp
@@ -25,6 +25,7 @@
 #include "openssl.h"
 
 #include <iostream>
+#include <cstdlib>
 
 #include <sys/types.h>
 #include <unistd.h>
