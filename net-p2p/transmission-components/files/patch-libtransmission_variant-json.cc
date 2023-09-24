--- libtransmission/variant-json.cc.orig	2023-09-19 12:15:17 UTC
+++ libtransmission/variant-json.cc
@@ -99,7 +99,7 @@ void error_handler(jsonsl_t jsn, jsonsl_error_t error,
             fmt::arg("position", jsn->pos),
             fmt::arg("text", std::string_view{ buf, std::min(size_t{ 16U }, data->size - jsn->pos) }),
             fmt::arg("error", jsonsl_strerror(error)),
-            fmt::arg("error_code", error)));
+            fmt::arg("error_code", static_cast<int>(error))));
 }
 
 int error_callback(jsonsl_t jsn, jsonsl_error_t error, struct jsonsl_state_st* state, jsonsl_char_t* at)
