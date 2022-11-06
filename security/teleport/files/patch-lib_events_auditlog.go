--- lib/events/auditlog.go.orig	2022-02-23 04:58:43 UTC
+++ lib/events/auditlog.go
@@ -45,7 +45,7 @@ import (
 const (
 	// SessionLogsDir is a subdirectory inside the eventlog data dir
 	// where all session-specific logs and streams are stored, like
-	// in /var/lib/teleport/logs/sessions
+	// in /var/db/teleport/logs/sessions
 	SessionLogsDir = "sessions"
 
	// StreamingLogsDir is a subdirectory of sessions /var/lib/teleport/logs/streaming
