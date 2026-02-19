--- codex-rs/core/tests/suite/view_image.rs.orig	2026-02-18 06:34:44 UTC
+++ codex-rs/core/tests/suite/view_image.rs
@@ -40,6 +40,8 @@ use wiremock::MockServer;
 use tokio::time::Duration;
 use wiremock::BodyPrintLimit;
 use wiremock::MockServer;
+use wiremock::ResponseTemplate;
+use wiremock::matchers::body_string_contains;
 
 fn find_image_message(body: &Value) -> Option<&Value> {
     body.get("input")
