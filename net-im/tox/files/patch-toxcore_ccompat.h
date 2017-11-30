--- toxcore/ccompat.h.orig	2017-04-27 18:20:19 UTC
+++ toxcore/ccompat.h
@@ -29,8 +29,6 @@
 // Emulation using alloca.
 #ifdef _WIN32
 #include <malloc.h>
-#else
-#include <alloca.h>
 #endif
 
 #define VLA(type, name, size)                           \
