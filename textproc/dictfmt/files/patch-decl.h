--- decl.h	Mon Jan 24 18:44:03 2005
+++ decl.h	Mon Jan 24 18:32:44 2005
@@ -28,7 +28,7 @@
 declarations for standard library calls.  We provide them here for
 situations that we know about. */
 
-#if defined(__sparc__) && !defined(__linux__)
+#if defined(__sparc__) && !defined(__linux__) && !defined(__FreeBSD__)
 				/* Both SunOS and Solaris */
 extern int    getrusage( int who, struct rusage * );
 extern void   bcopy( const void *, void *, int );
