--- libmaa/decl.h	Mon Jan 24 18:39:34 2005
+++ libmaa/decl.h	Mon Jan 24 18:38:24 2005
@@ -28,7 +28,7 @@
 declarations for standard library calls.  We provide them here for
 situations that we know about. */
 
-#if defined(__sparc__) && !defined(linux)
+#if defined(__sparc__) && !defined(linux) && !defined(__FreeBSD__)
 #include <sys/resource.h>
 				/* Both SunOS and Solaris */
 extern int    getrusage( int who, struct rusage * );
