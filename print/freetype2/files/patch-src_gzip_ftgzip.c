--- src/gzip/ftgzip.c.orig	Sat Jan 18 13:04:29 2003
+++ src/gzip/ftgzip.c	Sat Jan 18 13:04:40 2003
@@ -177,7 +177,7 @@
     (void)FT_STREAM_SKIP( 6 );
 
     /* skip the extra field */
-    if ( head[3] && FT_GZIP_EXTRA_FIELD )
+    if ( head[3] & FT_GZIP_EXTRA_FIELD )
     {
       FT_UInt  len;
 
@@ -187,7 +187,7 @@
     }
 
     /* skip original file name */
-    if ( head[3] && FT_GZIP_ORIG_NAME )
+    if ( head[3] & FT_GZIP_ORIG_NAME )
       for (;;)
       {
         FT_UInt  c;
