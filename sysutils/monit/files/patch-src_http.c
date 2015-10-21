--- src/http.c.orig	2015-06-02 10:09:34 UTC
+++ src/http.c
@@ -137,6 +137,8 @@ void monit_http(Httpd_Action action) {
 
 
 static void *thread_wrapper(void *arg) {
+        sigset_t ns;
+        set_signal_block(&ns, NULL);
         Engine_start();
 #ifdef HAVE_OPENSSL
         Ssl_threadCleanup();
