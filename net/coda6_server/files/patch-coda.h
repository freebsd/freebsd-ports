On Thu, Sep 18, 2003 at 07:50:18PM -0700, Kris Kennaway wrote:

> http://bento.freebsd.org/errorlogs/i386-4-full/coda-server-6.0.2_1.log
> 
> Can you please investigate?

Drop this file into ports/coda6_server/files/patch-aa (or disconnect it from
the build - coda 6 is not very useful on freebsd 4).

--- lib-src/kernel-includes/coda.h.orig	Fri Sep 19 18:34:03 2003
+++ lib-src/kernel-includes/coda.h	Fri Sep 19 18:34:19 2003
@@ -125,8 +125,8 @@
 #define __BIT_TYPES_DEFINED__
 #endif
 
-/* FreeBSD 5.0 */
-#if __FreeBSD__ >= 5
+/* FreeBSD 3.0 and above */
+#if __FreeBSD__ >= 3
 #define __BIT_TYPES_DEFINED__
 #endif
 
