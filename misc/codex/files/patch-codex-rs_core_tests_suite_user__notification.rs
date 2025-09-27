--- codex-rs/core/tests/suite/user_notification.rs.orig	2025-09-27 09:08:21 UTC
+++ codex-rs/core/tests/suite/user_notification.rs
@@ -35,7 +35,7 @@ async fn summarize_context_three_requests_and_instruct
     let notify_script = notify_dir.path().join("notify.sh");
     std::fs::write(
         &notify_script,
-        r#"#!/bin/bash
+        r#"#!/bin/sh
 set -e
 echo -n "${@: -1}" > $(dirname "${0}")/notify.txt"#,
     )?;
