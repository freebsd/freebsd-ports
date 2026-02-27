--- codex-rs/core/tests/suite/view_image.rs.orig	2026-02-26 19:39:41 UTC
+++ codex-rs/core/tests/suite/view_image.rs
@@ -41,6 +41,8 @@ use wiremock::MockServer;
 use tokio::time::Duration;
 use wiremock::BodyPrintLimit;
 use wiremock::MockServer;
+use wiremock::ResponseTemplate;
+use wiremock::matchers::body_string_contains;
 
 fn image_messages(body: &Value) -> Vec<&Value> {
     body.get("input")
