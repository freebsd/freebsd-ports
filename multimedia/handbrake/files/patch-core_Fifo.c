--- core/Fifo.c.orig	Wed May 26 05:51:32 2004
+++ core/Fifo.c	Fri Nov 19 15:55:26 2004
@@ -23,7 +23,7 @@

 #if defined( HB_BEOS ) || defined( HB_LINUX )
     b->data = memalign( 16, size );
-#elif defined( HB_MACOSX )
+#elif defined( HB_MACOSX ) || defined( HB_FREEBSD )
     /* OS X's malloc returns 16-bytes aligned memory */
     b->data = malloc( size );
 #elif defined( HB_CYGWIN )
@@ -47,7 +47,7 @@
 {
     /* We don't care about alignment here, realloc is only used in the
        AVI muxer anyway */
-#if defined( HB_BEOS ) || defined( HB_LINUX ) || defined( HB_MACOSX )
+#if defined( HB_BEOS ) || defined( HB_LINUX ) || defined( HB_MACOSX ) || defined( HB_FREEBSD )
     b->data = realloc( b->data, size );
 #elif defined( HB_CYGWIN )
     int alignment = b->data - b->dataOrig;
@@ -66,7 +66,7 @@
 {
     HBBuffer * b = *_b;

-#if defined( HB_BEOS ) || defined( HB_LINUX ) || defined( HB_MACOSX )
+#if defined( HB_BEOS ) || defined( HB_LINUX ) || defined( HB_MACOSX ) || defined( HB_FREEBSD )
     free( b->data );
 #elif defined( HB_CYGWIN )
     free( b->dataOrig );
