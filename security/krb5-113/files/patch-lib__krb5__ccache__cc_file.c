--- lib/krb5/ccache/cc_file.c.orig	2014-10-15 16:55:10.000000000 -0700
+++ lib/krb5/ccache/cc_file.c	2015-02-12 13:00:31.967166267 -0800
@@ -136,6 +136,7 @@
     fcc_data *data = id->data;
     struct stat sb;
 
+    *size_out = 0;
     k5_cc_mutex_assert_locked(context, &data->lock);
     if (fstat(data->fd, &sb) == -1)
         return interpret_errno(context, errno);
