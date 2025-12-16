--- codex-rs/core/tests/suite/view_image.rs.orig	2025-12-16 07:13:16 UTC
+++ codex-rs/core/tests/suite/view_image.rs
@@ -24,6 +24,8 @@ use serde_json::Value;
 use image::Rgba;
 use image::load_from_memory;
 use serde_json::Value;
+use wiremock::ResponseTemplate;
+use wiremock::matchers::body_string_contains;
 
 fn find_image_message(body: &Value) -> Option<&Value> {
     body.get("input")
