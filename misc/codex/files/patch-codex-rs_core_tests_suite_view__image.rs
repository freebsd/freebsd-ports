--- codex-rs/core/tests/suite/view_image.rs.orig	2026-02-13 01:48:51 UTC
+++ codex-rs/core/tests/suite/view_image.rs
@@ -39,6 +39,8 @@ use wiremock::MockServer;
 use tokio::time::Duration;
 use wiremock::BodyPrintLimit;
 use wiremock::MockServer;
+use wiremock::ResponseTemplate;
+use wiremock::matchers::body_string_contains;
 
 fn find_image_message(body: &Value) -> Option<&Value> {
     body.get("input")
