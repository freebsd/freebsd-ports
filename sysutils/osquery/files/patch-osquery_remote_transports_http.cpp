--- osquery/remote/transports/http.cpp.orig	2015-05-05 00:16:41 UTC
+++ osquery/remote/transports/http.cpp
@@ -25,9 +25,14 @@ Status HTTPTransport::sendRequest() {
   http::client client;
   http::client::request r(destination_);
   decorateRequest(r);
-  response_ = client.get(r);
-  response_status_ =
-      serializer_->deserialize(body(response_), response_params_);
+
+  try {
+    response_ = client.get(r);
+    response_status_ =
+        serializer_->deserialize(body(response_), response_params_);
+  } catch (const std::exception& e) {
+    return Status(1, std::string("Request error: ") + e.what());
+  }
   return response_status_;
 }
 
@@ -35,9 +40,14 @@ Status HTTPTransport::sendRequest(const 
   http::client client;
   http::client::request r(destination_);
   decorateRequest(r);
-  response_ = client.post(r, params);
-  response_status_ =
-      serializer_->deserialize(body(response_), response_params_);
+
+  try {
+    response_ = client.post(r, params);
+    response_status_ =
+        serializer_->deserialize(body(response_), response_params_);
+  } catch (const std::exception& e) {
+    return Status(1, std::string("Request error: ") + e.what());
+  }
   return response_status_;
 }
 }
