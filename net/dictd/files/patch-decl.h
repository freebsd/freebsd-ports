--- decl.h.orig	Sat Jan 11 18:39:08 2003
+++ decl.h	Sat Jan 11 18:38:58 2003
@@ -28,7 +28,7 @@
 declarations for standard library calls.  We provide them here for
 situations that we know about. */
 
-#if defined(__sparc__) && !defined(__linux__)
+#if defined(__sparc__) && !(defined(__linux__) || defined(__FreeBSD__))
 				/* Both SunOS and Solaris */
 extern int    getrusage( int who, struct rusage * );
 extern void   bcopy( const void *, void *, int );
