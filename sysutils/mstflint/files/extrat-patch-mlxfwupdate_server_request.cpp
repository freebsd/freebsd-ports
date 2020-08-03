--- mlxfwupdate/server_request.cpp.orig	2020-01-09 00:45:10.200149000 +0100
+++ mlxfwupdate/server_request.cpp	2020-01-09 00:46:56.459627000 +0100
@@ -43,9 +43,7 @@
 
 
 using namespace std;
-#ifndef USE_CURL
-#define USE_CURL
-#endif
+#undef USE_CURL
 
 extern int abort_request;
 
@@ -62,7 +60,9 @@ ServerRequest::ServerRequest(const char *url, const ch
     _show_progress = show_progress;
     _ceritifcate   = certificate;
     _numberOfRetrials = numberOfRetrials;
+#ifdef USE_CURL
     _headers       = NULL;
+#endif
     if (proxy != NULL) {
         if (proxy[0] != 0) {
             _UseProxy = 1;
