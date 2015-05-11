--- osquery/config/plugins/http.cpp.orig	2015-05-05 00:16:41 UTC
+++ osquery/config/plugins/http.cpp
@@ -14,10 +14,10 @@
 #include <boost/property_tree/ptree.hpp>
 
 #include <osquery/config.h>
+#include <osquery/enrollment.h>
 #include <osquery/flags.h>
-#include <osquery/logger.h>
-#include <osquery/filesystem.h>
 #include <osquery/registry.h>
+
 #include "osquery/remote/requests.h"
 #include "osquery/remote/transports/http.h"
 #include "osquery/remote/serializers/json.h"
@@ -30,7 +30,7 @@ DECLARE_string(enrollment_app_id);
 
 FLAG(string,
      config_enrollment_uri,
-     "Not Specified",
+     "",
      "The endpoint for server side client enrollment");
 
 class HTTPConfigPlugin : public ConfigPlugin {
@@ -40,49 +40,45 @@ class HTTPConfigPlugin : public ConfigPl
 
 REGISTER(HTTPConfigPlugin, "config", "http");
 
-Status runEnrollment(const bool force = false) {
-  PluginResponse resp;
-  PluginRequest req;
-  if (force) {
-    req = {{"enroll", "1"}};
-  } else {
-    req = {{"enroll", "0"}};
+Status runEnrollment(bool force = false) {
+  PluginResponse response;
+  PluginRequest request = {{"enroll", (force) ? "1" : "0"}};
+  auto status = Registry::call("enrollment", "get_key", request, response);
+  if (!status.ok()) {
+    return status;
   }
-  Status stat = Registry::call("enrollment", "get_key", req, resp);
 
-  if (!stat.ok()) {
-    return stat;
-  }
-  if (resp.size() > 0 && resp[0]["key"].length() == 0) {
+  if (response.size() > 0 && response[0]["key"].size() == 0) {
     return Status(1, "Enrollment Error: No Key");
   }
   return Status(0, "OK");
 }
 
-Status getConfig(boost::property_tree::ptree& recv) {
-  // Make request to endpoint with secrets
+Status getConfig(boost::property_tree::ptree& output) {
+  // Make request to endpoint with secrets.
   auto r = Request<HTTPTransport, JSONSerializer>(FLAGS_config_enrollment_uri);
   boost::property_tree::ptree params;
 
-  PluginResponse resp;
-  Status stat =
-      Registry::call("enrollment", "get_key", {{"enroll", "0"}}, resp);
-  params.put<std::string>("enrollment_key", resp[0]["key"]);
+  PluginResponse response;
+  Registry::call("enrollment", "get_key", {{"enroll", "0"}}, response);
+  params.put<std::string>("enrollment_key", response[0]["key"]);
   params.put<std::string>("app_id", FLAGS_enrollment_app_id);
-  stat = r.call(params);
 
-  if (!stat.ok()) {
-    return stat;
+  auto status = r.call(params);
+  if (!status.ok()) {
+    return status;
   }
-  // The call was ok, so store the enrolled key
-  stat = r.getResponse(recv);
-  if (!stat.ok()) {
-    return stat;
+
+  // The call succeeded, store the enrolled key.
+  status = r.getResponse(output);
+  if (!status.ok()) {
+    return status;
   }
+
   // Receive config or key rejection
-  if (recv.count("enrollment_invalid") > 0 &&
-      recv.get<std::string>("enrollment_invalid", "") == "1") {
-    return stat;
+  if (output.count("enrollment_invalid") > 0 &&
+      output.get<std::string>("enrollment_invalid", "") == "1") {
+    return status;
   }
   return Status(0, "OK");
 }
@@ -97,6 +93,7 @@ Status HTTPConfigPlugin::genConfig(std::
       break;
     }
   }
+
   std::stringstream ss;
   write_json(ss, recv);
   config[FLAGS_enrollment_app_id] = ss.str();
