There is an undiagnosed ARMv6 core dump in this code
as discovered in FreeBSD Bug 183536 when using clang.
Removing this code from ARM builds resolves it.

--- src/fccompat.c.orig	2013-10-11 03:10:18 UTC
+++ src/fccompat.c
@@ -178,7 +178,7 @@
     }
 
     random_r(&fcrandbuf, &result);
-#elif HAVE_RANDOM
+#elif HAVE_RANDOM && !defined(__arm__)
     static char statebuf[256];
     char *state;
     static FcBool initialized = FcFalse;
