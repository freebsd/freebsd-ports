--- src/libdvdcss.c.orig	2018-03-02 15:44:29 UTC
+++ src/libdvdcss.c
@@ -320,7 +320,19 @@ static int init_cache_dir( dvdcss_t dvdcss )
         return -1;
     }
 
-    sprintf( psz_tagfile, "%s/" CACHE_TAG_NAME, dvdcss->psz_cachefile );
+    i_ret = snprintf( psz_tagfile, PATH_MAX, "%s/" CACHE_TAG_NAME,
+                      dvdcss->psz_cachefile );
+    if ( i_ret < 0 || i_ret >= PATH_MAX)
+    {
+        if ( i_ret < 0)
+            print_error( dvdcss, "failed to compose cache directory tag path");
+        else
+            print_error( dvdcss, "cache directory tag path too long: %s/" CACHE_TAG_NAME,
+                         dvdcss->psz_cachefile );
+        dvdcss->psz_cachefile[0] = '\0';
+        return -1;
+    }
+
     i_fd = open( psz_tagfile, O_RDWR|O_CREAT, 0644 );
     if( i_fd >= 0 )
     {
