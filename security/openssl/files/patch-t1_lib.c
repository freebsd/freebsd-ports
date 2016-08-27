CVE-2016-2177

--- ssl/t1_lib.c.orig
+++ ssl/t1_lib.c
@@ -1867,11 +1867,11 @@ static void ssl_check_for_safari(SSL *s, const unsigned char *data,
         0x02, 0x03,             /* SHA-1/ECDSA */
     };
 
-    if (data >= (limit - 2))
+    if (limit - data <= 2)
         return;
     data += 2;
 
-    if (data > (limit - 4))
+    if (limit - data < 4)
         return;
     n2s(data, type);
     n2s(data, size);
@@ -1879,7 +1879,7 @@ static void ssl_check_for_safari(SSL *s, const unsigned char *data,
     if (type != TLSEXT_TYPE_server_name)
         return;
 
-    if (data + size > limit)
+    if (limit - data < size)
         return;
     data += size;
 
@@ -1887,7 +1887,7 @@ static void ssl_check_for_safari(SSL *s, const unsigned char *data,
         const size_t len1 = sizeof(kSafariExtensionsBlock);
         const size_t len2 = sizeof(kSafariTLS12ExtensionsBlock);
 
-        if (data + len1 + len2 != limit)
+        if (limit - data != (int)(len1 + len2))
             return;
         if (memcmp(data, kSafariExtensionsBlock, len1) != 0)
             return;
@@ -1896,7 +1896,7 @@ static void ssl_check_for_safari(SSL *s, const unsigned char *data,
     } else {
         const size_t len = sizeof(kSafariExtensionsBlock);
 
-        if (data + len != limit)
+        if (limit - data != (int)(len))
             return;
         if (memcmp(data, kSafariExtensionsBlock, len) != 0)
             return;
@@ -2053,19 +2053,19 @@ static int ssl_scan_clienthello_tlsext(SSL *s, unsigned char **p,
     if (data == limit)
         goto ri_check;
 
-    if (data > (limit - 2))
+    if (limit - data < 2)
         goto err;
 
     n2s(data, len);
 
-    if (data + len != limit)
+    if (limit - data != len)
         goto err;
 
-    while (data <= (limit - 4)) {
+    while (limit - data >= 4) {
         n2s(data, type);
         n2s(data, size);
 
-        if (data + size > (limit))
+        if (limit - data < size)
             goto err;
 # if 0
         fprintf(stderr, "Received extension type %d size %d\n", type, size);
@@ -2472,18 +2472,18 @@ static int ssl_scan_clienthello_custom_tlsext(SSL *s,
     if (s->hit || s->cert->srv_ext.meths_count == 0)
         return 1;
 
-    if (data >= limit - 2)
+    if (limit - data <= 2)
         return 1;
     n2s(data, len);
 
-    if (data > limit - len)
+    if (limit - data < len)
         return 1;
 
-    while (data <= limit - 4) {
+    while (limit - data >= 4) {
         n2s(data, type);
         n2s(data, size);
 
-        if (data + size > limit)
+        if (limit - data < size)
             return 1;
         if (custom_ext_parse(s, 1 /* server */ , type, data, size, al) <= 0)
             return 0;
@@ -2569,20 +2569,20 @@ static int ssl_scan_serverhello_tlsext(SSL *s, unsigned char **p,
                              SSL_TLSEXT_HB_DONT_SEND_REQUESTS);
 # endif
 
-    if (data >= (d + n - 2))
+    if ((d + n) - data <= 2)
         goto ri_check;
 
     n2s(data, length);
-    if (data + length != d + n) {
+    if ((d + n) - data != length) {
         *al = SSL_AD_DECODE_ERROR;
         return 0;
     }
 
-    while (data <= (d + n - 4)) {
+    while ((d + n) - data >= 4) {
         n2s(data, type);
         n2s(data, size);
 
-        if (data + size > (d + n))
+        if ((d + n) - data < size)
             goto ri_check;
 
         if (s->tlsext_debug_cb)
@@ -3307,29 +3307,33 @@ int tls1_process_ticket(SSL *s, unsigned char *session_id, int len,
     /* Skip past DTLS cookie */
     if (SSL_IS_DTLS(s)) {
         i = *(p++);
-        p += i;
-        if (p >= limit)
+
+        if (limit - p <= i)
             return -1;
+
+        p += i;
     }
     /* Skip past cipher list */
     n2s(p, i);
-    p += i;
-    if (p >= limit)
+    if (limit - p <= i)
         return -1;
+    p += i;
+
     /* Skip past compression algorithm list */
     i = *(p++);
-    p += i;
-    if (p > limit)
+    if (limit - p < i)
         return -1;
+    p += i;
+
     /* Now at start of extensions */
-    if ((p + 2) >= limit)
+    if (limit - p <= 2)
         return 0;
     n2s(p, i);
-    while ((p + 4) <= limit) {
+    while (limit - p >= 4) {
         unsigned short type, size;
         n2s(p, type);
         n2s(p, size);
-        if (p + size > limit)
+        if (limit - p < size)
             return 0;
         if (type == TLSEXT_TYPE_session_ticket) {
             int r;
-- 
1.9.1

