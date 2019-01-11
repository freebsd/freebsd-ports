--- content/browser/service_worker/service_worker_fetch_dispatcher.cc.orig	2019-01-09 21:08:27.096726000 +0100
+++ content/browser/service_worker/service_worker_fetch_dispatcher.cc	2019-01-09 21:09:45.655612000 +0100
@@ -625,7 +625,7 @@
   network::ResourceRequest request;
   request.method = original_request->method();
   request.url = original_request->url();
-  // TODO(horo): Set site_for_cookies to support Same-site Cookies.
+  request.site_for_cookies = original_request->site_for_cookies();
   request.request_initiator =
       original_request->initiator().has_value()
           ? original_request->initiator()
