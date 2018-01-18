--- third-party/mongoose/mongoose.c.orig	2018-01-12 09:48:20 UTC
+++ third-party/mongoose/mongoose.c
@@ -730,7 +730,7 @@ struct mg_request_info *mg_get_request_info(struct mg_
   return &conn->request_info;
 }
 
-static void mg_strlcpy(register char *dst, register const char *src, size_t n) {
+static void mg_strlcpy(char *dst, const char *src, size_t n) {
   for (; *src != '\0' && n > 1; n--) {
     *dst++ = *src++;
   }
@@ -2139,7 +2139,7 @@ static void MD5Init(MD5_CTX *ctx) {
 }
 
 static void MD5Transform(uint32_t buf[4], uint32_t const in[16]) {
-  register uint32_t a, b, c, d;
+  uint32_t a, b, c, d;
 
   a = buf[0];
   b = buf[1];
@@ -4511,7 +4511,7 @@ static int set_ports_option(struct mg_context *ctx) {
 					   (void *)
 #endif
 					   &on, sizeof(on))) != 0 ||
-	       (rc_bind = bind(so.sock,
+	       (rc_bind = ::bind(so.sock,
 			       &sa->sa,
 			       (sa->sa.sa_family == AF_INET) ? sizeof(sa->sin) : sizeof(sa->sin6))
 		) != 0 ||
