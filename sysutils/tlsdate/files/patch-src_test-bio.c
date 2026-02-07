Obtained from:	https://chromium-review.googlesource.com/c/chromiumos/third_party/tlsdate/+/549533

--- src/test-bio.c.orig	2015-05-28 18:49:40 UTC
+++ src/test-bio.c
@@ -15,6 +15,7 @@
 #include <assert.h>
 #include <string.h>
 
+#include "src/openssl_compat.h"
 #include "src/test-bio.h"
 #include "src/util.h"
 
@@ -34,7 +35,7 @@ struct test_ctx
 
 static struct test_ctx *bio_ctx (BIO *b)
 {
-  struct test_ctx *ctx = b->ptr;
+  struct test_ctx *ctx = BIO_get_data(b);
   assert (ctx->magic == kMagic);
   return ctx;
 }
@@ -70,16 +71,16 @@ int test_new (BIO *b)
   ctx->insz = 0;
   ctx->out = NULL;
   ctx->outsz = 0;
-  b->init = 1;
-  b->flags = 0;
-  b->ptr = ctx;
+  BIO_set_init(b, 1);
+  BIO_clear_flags(b, ~0);
+  BIO_set_data(b, ctx);
   return 1;
 }
 
 int test_free (BIO *b)
 {
   struct test_ctx *ctx;
-  if (!b || !b->ptr)
+  if (!b || !BIO_get_data(b))
     return 1;
   ctx = bio_ctx (b);
   free (ctx->in);
@@ -114,6 +115,8 @@ long test_callback_ctrl (BIO *b, int cmd
   return 0;
 }
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+
 BIO_METHOD test_methods =
 {
   BIO_TYPE_SOCKET,
@@ -133,6 +136,29 @@ BIO_METHOD *BIO_s_test()
   return &test_methods;
 }
 
+#else
+
+static BIO_METHOD *test_methods;
+
+BIO_METHOD *BIO_s_test()
+{
+  if (!test_methods) {
+    test_methods = BIO_meth_new(BIO_TYPE_SOCKET, "test");
+    BIO_meth_set_write(test_methods, test_write);
+    BIO_meth_set_read(test_methods, test_read);
+    BIO_meth_set_puts(test_methods, NULL);
+    BIO_meth_set_gets(test_methods, NULL);
+    BIO_meth_set_ctrl(test_methods, test_ctrl);
+    BIO_meth_set_create(test_methods, test_new);
+    BIO_meth_set_destroy(test_methods, test_free);
+    BIO_meth_set_callback_ctrl(test_methods, test_callback_ctrl);
+  }
+
+  return test_methods;
+}
+
+#endif
+
 BIO API *BIO_new_test()
 {
   return BIO_new (BIO_s_test());
