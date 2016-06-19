--- encfs/makeKey.cpp.orig	2016-06-18 20:53:44 UTC
+++ encfs/makeKey.cpp
@@ -25,6 +25,7 @@
 #include "openssl.h"
 
 #include <iostream>
+#include <cstdlib>
 
 #include <sys/types.h>
 #include <unistd.h>
