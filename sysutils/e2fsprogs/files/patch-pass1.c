$FreeBSD$

--- e2fsck/pass1.c.orig	Wed Aug 27 19:59:14 2003
+++ e2fsck/pass1.c	Wed Aug 27 19:59:19 2003
@@ -165 +165 @@
-static int strnlen(const char * s, int count)
+int strnlen(const char * s, int count)
