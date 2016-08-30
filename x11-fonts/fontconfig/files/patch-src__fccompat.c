There is an undiagnosed ARMv6 core dump in this code
as discovered in FreeBSD Bug 183536 when using clang.
Removing this code from ARM builds resolves it.

https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=183536

--- src/fccompat.c.orig	2016-07-11 02:41:06 UTC
+++ src/fccompat.c
@@ -191,7 +191,7 @@ FcRandom(void)
 #else
     random_r (&fcrandbuf, &result);
 #endif
-#elif HAVE_RANDOM
+#elif HAVE_RANDOM && !defined(__arm__)
     static char statebuf[256];
     char *state;
     static FcBool initialized = FcFalse;
