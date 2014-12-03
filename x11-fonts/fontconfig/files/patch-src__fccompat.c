There is an undiagnosed ARMv6 core dump in this code
as discovered in FreeBSD Bug 183536 when using clang.
Removing this code from ARM builds resolves it.

https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=183536

--- src/fccompat.c.orig	2014-08-12 16:34:15.875384345 +0200
+++ src/fccompat.c	2014-08-12 16:35:04.752379905 +0200
@@ -191,7 +191,7 @@
 #else
     random_r (&fcrandbuf, &result);
 #endif
-#elif HAVE_RANDOM
+#elif HAVE_RANDOM && !defined(__arm__)
     static char statebuf[256];
     char *state;
     static FcBool initialized = FcFalse;
