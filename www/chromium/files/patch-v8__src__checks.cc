--- v8/src/checks.cc.orig	2014-01-07 21:03:55.000000000 +0100
+++ v8/src/checks.cc	2014-01-11 01:09:31.000000000 +0100
@@ -32,6 +32,7 @@
 # include <execinfo.h>
 #endif  // V8_LIBC_GLIBC || V8_OS_BSD
 #include <stdio.h>
+#include <unistd.h> // size_t
 
 #include "platform.h"
 #include "v8.h"
