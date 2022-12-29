--- mlxfwupdate/server_request.cpp.orig	2022-12-16 18:34:53.974210000 +0100
+++ mlxfwupdate/server_request.cpp	2022-12-16 18:36:46.969103000 +0100
@@ -43,9 +43,7 @@
 #include <string>
 
 using namespace std;
-#ifndef USE_CURL
-#define USE_CURL
-#endif
+#undef USE_CURL
 
 extern int abort_request;
 
@@ -65,7 +63,9 @@
     _show_progress = show_progress;
     _ceritifcate = certificate;
     _numberOfRetrials = numberOfRetrials;
+#ifdef USE_CURL
     _headers = NULL;
+#endif
     if (proxy != NULL)
     {
         if (proxy[0] != 0)
