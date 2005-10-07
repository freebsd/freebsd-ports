--- test-client.c	Thu Apr 28 12:28:25 2005
+++ /home/frank/tivo/vstream-client-1.2/test-client.c	Thu Oct  6 21:47:52 2005
@@ -6,7 +6,7 @@
 #define CHUNK ( 1024 * 1024 )
 
 // on cygwin, we have large file support already, and no fopen64.
-#ifdef __CYGWIN__
+#if defined(__CYGWIN__) || defined(__FreeBSD__)
 #define fopen64 fopen
 #endif
 
