--- example/handler/test_handler.cpp.orig	Wed Jun 13 14:15:35 2007
+++ example/handler/test_handler.cpp	Wed Jun 13 14:26:38 2007
@@ -18,7 +18,7 @@
 int TestHandler::handler(ApacheRequestRec *pRequest)
 {
     mHits++;
-    pRequest->content_type("application/x-httpd-cgi");
+    pRequest->content_type((char *)"application/x-httpd-cgi");
     pRequest->dump();
     pRequest->rprintf("BOO");
     ap_setup_client_block(pRequest->get_request_rec(), REQUEST_CHUNKED_ERROR);
