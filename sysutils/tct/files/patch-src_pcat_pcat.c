
$FreeBSD$

--- src/pcat/pcat.c.orig
+++ src/pcat/pcat.c
@@ -114,7 +114,7 @@
   * grope kernel memory instead.
   */
 #if defined(FREEBSD2) || defined(FREEBSD3) || defined(FREEBSD4) \
-	|| defined(FREEBSD5)
+	|| defined(FREEBSD5) || defined(FREEBSD6) || defined(FREEBSD7)
 #define SUPPORTED
 #include <sys/param.h>
 #include <sys/user.h>
