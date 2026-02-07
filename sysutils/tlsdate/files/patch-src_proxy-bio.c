Obtained from:	https://chromium-review.googlesource.com/c/chromiumos/third_party/tlsdate/+/549533

--- src/proxy-bio.c.orig	2015-05-28 18:49:40 UTC
+++ src/proxy-bio.c
@@ -35,6 +35,7 @@
 #include "src/common/strnlen.h"
 #endif
 
+#include "src/openssl_compat.h"
 #include "src/proxy-bio.h"
 
 int socks4a_connect (BIO *b);
@@ -50,29 +51,29 @@ int proxy_new (BIO *b)
   ctx->connect = NULL;
   ctx->host = NULL;
   ctx->port = 0;
-  b->init = 1;
-  b->flags = 0;
-  b->ptr = ctx;
+  BIO_set_init(b, 1);
+  BIO_clear_flags(b, ~0);
+  BIO_set_data(b, ctx);
   return 1;
 }
 
 int proxy_free (BIO *b)
 {
   struct proxy_ctx *c;
-  if (!b || !b->ptr)
+  if (!b || !BIO_get_data(b))
     return 1;
-  c = (struct proxy_ctx *) b->ptr;
+  c = (struct proxy_ctx *) BIO_get_data(b);
   if (c->host)
     free (c->host);
   c->host = NULL;
-  b->ptr = NULL;
+  BIO_set_data(b, NULL);
   free (c);
   return 1;
 }
 
 int socks4a_connect (BIO *b)
 {
-  struct proxy_ctx *ctx = (struct proxy_ctx *) b->ptr;
+  struct proxy_ctx *ctx = (struct proxy_ctx *) BIO_get_data(b);
   int r;
   unsigned char buf[NI_MAXHOST + 16];
   uint16_t port_n = htons (ctx->port);
@@ -102,13 +103,13 @@ int socks4a_connect (BIO *b)
 
   memcpy (buf + sz, ctx->host, strlen (ctx->host) + 1);
   sz += strlen (ctx->host) + 1;
-  r = BIO_write (b->next_bio, buf, sz);
+  r = BIO_write (BIO_next(b), buf, sz);
   if ( -1 == r )
     return -1;
   if ( (size_t) r != sz)
     return 0;
   /* server reply: 1 + 1 + 2 + 4 */
-  r = BIO_read (b->next_bio, buf, 8);
+  r = BIO_read (BIO_next(b), buf, 8);
   if ( -1 == r )
     return -1;
   if ( (size_t) r != 8)
@@ -126,7 +127,7 @@ int socks5_connect (BIO *b)
 {
   unsigned char buf[NI_MAXHOST + 16];
   int r;
-  struct proxy_ctx *ctx = (struct proxy_ctx *) b->ptr;
+  struct proxy_ctx *ctx = (struct proxy_ctx *) BIO_get_data(b);
   uint16_t port_n = htons (ctx->port);
   size_t sz = 0;
   /* the length for SOCKS addresses is only one byte. */
@@ -145,10 +146,10 @@ int socks5_connect (BIO *b)
   buf[0] = 0x05;
   buf[1] = 0x01;
   buf[2] = 0x00;
-  r = BIO_write (b->next_bio, buf, 3);
+  r = BIO_write (BIO_next(b), buf, 3);
   if (r != 3)
     return 0;
-  r = BIO_read (b->next_bio, buf, 2);
+  r = BIO_read (BIO_next(b), buf, 2);
   if (r != 2)
     return 0;
   if (buf[0] != 0x05 || buf[1] != 0x00)
@@ -175,7 +176,7 @@ int socks5_connect (BIO *b)
   sz += strlen (ctx->host);
   memcpy (buf + sz, &port_n, sizeof (port_n));
   sz += sizeof (port_n);
-  r = BIO_write (b->next_bio, buf, sz);
+  r = BIO_write (BIO_next(b), buf, sz);
   if ( -1 == r )
     return -1;
   if ( (size_t) r != sz)
@@ -190,7 +191,7 @@ int socks5_connect (BIO *b)
    * 2b: port, network byte order
    */
   /* grab up through the addr type */
-  r = BIO_read (b->next_bio, buf, 4);
+  r = BIO_read (BIO_next(b), buf, 4);
   if ( -1 == r )
     return -1;
   if (r != 4)
@@ -203,14 +204,14 @@ int socks5_connect (BIO *b)
   if (buf[3] == 0x03)
     {
       unsigned int len;
-      r = BIO_read (b->next_bio, buf + 4, 1);
+      r = BIO_read (BIO_next(b), buf + 4, 1);
       if (r != 1)
         return 0;
       /* host (buf[4] bytes) + port (2 bytes) */
       len = buf[4] + 2;
       while (len)
         {
-          r = BIO_read (b->next_bio, buf + 5, min (len, sizeof (buf)));
+          r = BIO_read (BIO_next(b), buf + 5, min (len, sizeof (buf)));
           if (r <= 0)
             return 0;
           len -= min (len, r);
@@ -219,7 +220,7 @@ int socks5_connect (BIO *b)
   else if (buf[3] == 0x01)
     {
       /* 4 bytes ipv4 addr, 2 bytes port */
-      r = BIO_read (b->next_bio, buf + 4, 6);
+      r = BIO_read (BIO_next(b), buf + 4, 6);
       if (r != 6)
         return 0;
     }
@@ -248,30 +249,30 @@ int sock_gets (BIO *b, char *buf, size_t
 int http_connect (BIO *b)
 {
   int r;
-  struct proxy_ctx *ctx = (struct proxy_ctx *) b->ptr;
+  struct proxy_ctx *ctx = (struct proxy_ctx *) BIO_get_data(b);
   char buf[4096];
   int retcode;
   snprintf (buf, sizeof (buf), "CONNECT %s:%d HTTP/1.1\r\n",
             ctx->host, ctx->port);
-  r = BIO_write (b->next_bio, buf, strlen (buf));
+  r = BIO_write (BIO_next(b), buf, strlen (buf));
   if ( -1 == r )
     return -1;
   if ( (size_t) r != strlen(buf))
     return 0;
   /* required by RFC 2616 14.23 */
   snprintf (buf, sizeof (buf), "Host: %s:%d\r\n", ctx->host, ctx->port);
-  r = BIO_write (b->next_bio, buf, strlen (buf));
+  r = BIO_write (BIO_next(b), buf, strlen (buf));
   if ( -1 == r )
     return -1;
   if ( (size_t) r != strlen(buf))
     return 0;
   strcpy (buf, "\r\n");
-  r = BIO_write (b->next_bio, buf, strlen (buf));
+  r = BIO_write (BIO_next(b), buf, strlen (buf));
   if ( -1 == r )
     return -1;
   if ( (size_t) r != strlen(buf))
     return 0;
-  r = sock_gets (b->next_bio, buf, sizeof (buf));
+  r = sock_gets (BIO_next(b), buf, sizeof (buf));
   if (r)
     return 0;
   /* use %*s to ignore the version */
@@ -279,7 +280,7 @@ int http_connect (BIO *b)
     return 0;
   if (retcode < 200 || retcode > 299)
     return 0;
-  while (! (r = sock_gets (b->next_bio, buf, sizeof (buf))))
+  while (! (r = sock_gets (BIO_next(b), buf, sizeof (buf))))
     {
       if (!strcmp (buf, "\r\n"))
         {
@@ -294,12 +295,12 @@ int http_connect (BIO *b)
 int proxy_write (BIO *b, const char *buf, int sz)
 {
   int r;
-  struct proxy_ctx *ctx = (struct proxy_ctx *) b->ptr;
+  struct proxy_ctx *ctx = (struct proxy_ctx *) BIO_get_data(b);
 
   assert (buf);
   if (sz <= 0)
     return 0;
-  if (!b->next_bio)
+  if (!BIO_next(b))
     return 0;
   if (!ctx->connected)
     {
@@ -307,7 +308,7 @@ int proxy_write (BIO *b, const char *buf
       if (!ctx->connect (b))
         return 0;
     }
-  r = BIO_write (b->next_bio, buf, sz);
+  r = BIO_write (BIO_next(b), buf, sz);
   BIO_clear_retry_flags (b);
   BIO_copy_next_retry (b);
   return r;
@@ -316,10 +317,10 @@ int proxy_write (BIO *b, const char *buf
 int proxy_read (BIO *b, char *buf, int sz)
 {
   int r;
-  struct proxy_ctx *ctx = (struct proxy_ctx *) b->ptr;
+  struct proxy_ctx *ctx = (struct proxy_ctx *) BIO_get_data(b);
 
   assert (buf);
-  if (!b->next_bio)
+  if (!BIO_next(b))
     return 0;
   if (!ctx->connected)
     {
@@ -327,7 +328,7 @@ int proxy_read (BIO *b, char *buf, int s
       if (!ctx->connect (b))
         return 0;
     }
-  r = BIO_read (b->next_bio, buf, sz);
+  r = BIO_read (BIO_next(b), buf, sz);
   BIO_clear_retry_flags (b);
   BIO_copy_next_retry (b);
   return r;
@@ -337,43 +338,45 @@ long proxy_ctrl (BIO *b, int cmd, long n
 {
   long ret;
   struct proxy_ctx *ctx;
-  if (!b->next_bio)
+  if (!BIO_next(b))
     return 0;
-  ctx = (struct proxy_ctx *) b->ptr;
+  ctx = (struct proxy_ctx *) BIO_get_data(b);
   assert (ctx);
   switch (cmd)
     {
     case BIO_C_DO_STATE_MACHINE:
       BIO_clear_retry_flags (b);
-      ret = BIO_ctrl (b->next_bio, cmd, num, ptr);
+      ret = BIO_ctrl (BIO_next(b), cmd, num, ptr);
       BIO_copy_next_retry (b);
       break;
     case BIO_CTRL_DUP:
       ret = 0;
       break;
     default:
-      ret = BIO_ctrl (b->next_bio, cmd, num, ptr);
+      ret = BIO_ctrl (BIO_next(b), cmd, num, ptr);
     }
   return ret;
 }
 
 int proxy_gets (BIO *b, char *buf, int size)
 {
-  return BIO_gets (b->next_bio, buf, size);
+  return BIO_gets (BIO_next(b), buf, size);
 }
 
 int proxy_puts (BIO *b, const char *str)
 {
-  return BIO_puts (b->next_bio, str);
+  return BIO_puts (BIO_next(b), str);
 }
 
 long proxy_callback_ctrl (BIO *b, int cmd, bio_info_cb *fp)
 {
-  if (!b->next_bio)
+  if (!BIO_next(b))
     return 0;
-  return BIO_callback_ctrl (b->next_bio, cmd, fp);
+  return BIO_callback_ctrl (BIO_next(b), cmd, fp);
 }
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+
 BIO_METHOD proxy_methods =
 {
   BIO_TYPE_MEM,
@@ -393,6 +396,29 @@ BIO_METHOD *BIO_f_proxy()
   return &proxy_methods;
 }
 
+#else
+
+static BIO_METHOD *proxy_methods;
+
+BIO_METHOD *BIO_f_proxy()
+{
+  if (!proxy_methods) {
+    proxy_methods = BIO_meth_new(BIO_TYPE_MEM, "proxy");
+    BIO_meth_set_write(proxy_methods, proxy_write);
+    BIO_meth_set_read(proxy_methods, proxy_read);
+    BIO_meth_set_puts(proxy_methods, proxy_puts);
+    BIO_meth_set_gets(proxy_methods, proxy_gets);
+    BIO_meth_set_ctrl(proxy_methods, proxy_ctrl);
+    BIO_meth_set_create(proxy_methods, proxy_new);
+    BIO_meth_set_destroy(proxy_methods, proxy_free);
+    BIO_meth_set_callback_ctrl(proxy_methods, proxy_callback_ctrl);
+  }
+
+  return proxy_methods;
+}
+
+#endif
+
 /* API starts here */
 
 BIO API *BIO_new_proxy()
@@ -402,7 +428,7 @@ BIO API *BIO_new_proxy()
 
 int API BIO_proxy_set_type (BIO *b, const char *type)
 {
-  struct proxy_ctx *ctx = (struct proxy_ctx *) b->ptr;
+  struct proxy_ctx *ctx = (struct proxy_ctx *) BIO_get_data(b);
   if (!strcmp (type, "socks5"))
     ctx->connect = socks5_connect;
   else if (!strcmp (type, "socks4a"))
@@ -416,7 +442,7 @@ int API BIO_proxy_set_type (BIO *b, cons
 
 int API BIO_proxy_set_host (BIO *b, const char *host)
 {
-  struct proxy_ctx *ctx = (struct proxy_ctx *) b->ptr;
+  struct proxy_ctx *ctx = (struct proxy_ctx *) BIO_get_data(b);
   if (strnlen (host, NI_MAXHOST) == NI_MAXHOST)
     return 1;
   ctx->host = strdup (host);
@@ -425,6 +451,6 @@ int API BIO_proxy_set_host (BIO *b, cons
 
 void API BIO_proxy_set_port (BIO *b, uint16_t port)
 {
-  struct proxy_ctx *ctx = (struct proxy_ctx *) b->ptr;
+  struct proxy_ctx *ctx = (struct proxy_ctx *) BIO_get_data(b);
   ctx->port = port;
 }
