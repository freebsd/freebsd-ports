--- codex-rs/core/tests/suite/view_image.rs.orig	2026-01-09 19:17:48 UTC
+++ codex-rs/core/tests/suite/view_image.rs
@@ -26,6 +26,8 @@ use tokio::time::Duration;
 use image::load_from_memory;
 use serde_json::Value;
 use tokio::time::Duration;
+use wiremock::ResponseTemplate;
+use wiremock::matchers::body_string_contains;
 
 fn find_image_message(body: &Value) -> Option<&Value> {
     body.get("input")
