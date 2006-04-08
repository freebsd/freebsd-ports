--- src/apache2/mod_suphp.c.orig	Tue Jul 13 04:43:41 2004
+++ src/apache2/mod_suphp.c	Thu Mar  2 20:14:04 2006
@@ -56,7 +56,7 @@
         return -1;
        
     rv = apr_bucket_read(b, &bucket_data, &bucket_data_len, APR_BLOCK_READ);
-    if (!APR_STATUS_IS_SUCCESS(rv) || (bucket_data_len == 0))
+    if (!(rv == APR_SUCCESS) || (bucket_data_len == 0))
     {
         return 0;
     }
@@ -463,7 +463,13 @@
     
     if (((rv = apr_procattr_create(&procattr, p)) != APR_SUCCESS)
         || ((rv = apr_procattr_io_set(procattr, APR_CHILD_BLOCK, APR_CHILD_BLOCK, APR_CHILD_BLOCK)) != APR_SUCCESS)
+
+/* XXX: Pending review by both the Apache APR folks, as well as the suPHP folks.  See thread:
+ * http://lists.marsching.biz/pipermail/suphp/2004-July/000756.html
+ */
+/*
         || ((rv = apr_procattr_dir_set(procattr, ap_make_dirstr_parent(r->pool, r->filename))) != APR_SUCCESS)
+*/
     
     /* set resource limits */
 
@@ -524,7 +530,9 @@
             return rv;
         }
         
-        APR_BRIGADE_FOREACH(bucket, bb)
+ 	for (bucket = APR_BRIGADE_FIRST(bb);
+ 	     bucket != APR_BRIGADE_SENTINEL(bb);
+ 	     bucket = APR_BUCKET_NEXT(bucket))
         {
             const char *data;
             apr_size_t len;
@@ -595,7 +603,9 @@
             
             const char *buf;
             apr_size_t blen;
-            APR_BRIGADE_FOREACH(b, bb)
+ 	    for (b = APR_BRIGADE_FIRST(bb);
+ 		 b != APR_BRIGADE_SENTINEL(bb);
+ 		 b = APR_BUCKET_NEXT(b))
             {
                 if (APR_BUCKET_IS_EOS(b))
                     break;
@@ -616,7 +626,9 @@
             /* empty brigade (script output) */
             const char *buf;
             apr_size_t blen;
-            APR_BRIGADE_FOREACH(b, bb)
+ 	    for (b = APR_BRIGADE_FIRST(bb);
+ 		 b != APR_BRIGADE_SENTINEL(bb);
+ 		 b = APR_BUCKET_NEXT(b))
             {
                 if (APR_BUCKET_IS_EOS(b))
                     break;
