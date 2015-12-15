--- lib/krb5/ccache/cc_kcm.c.orig	2014-10-15 16:55:10.000000000 -0700
+++ lib/krb5/ccache/cc_kcm.c	2014-10-16 00:04:30.312921884 -0700
@@ -377,7 +377,7 @@
 kcmio_call(krb5_context context, struct kcmio *io, struct kcmreq *req)
 {
     krb5_error_code ret;
-    size_t reply_len;
+    size_t reply_len = 0;	/* XXX Make clang happy */
 
     if (k5_buf_status(&req->reqbuf) != 0)
         return ENOMEM;
