--- src/apache2/mod_suphp.c.orig	Tue Jul 13 02:43:41 2004
+++ src/apache2/mod_suphp.c	Wed Jul 14 01:51:27 2004
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
 
