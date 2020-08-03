--- lib/events/auditlog.go.orig	2020-07-08 18:08:40 UTC
+++ lib/events/auditlog.go
@@ -45,7 +45,7 @@ import (
 const (
 	// SessionLogsDir is a subdirectory inside the eventlog data dir
 	// where all session-specific logs and streams are stored, like
-	// in /var/lib/teleport/logs/sessions
+	// in /var/db/teleport/logs/sessions
 	SessionLogsDir = "sessions"
 
 	// PlaybacksDir is a directory for playbacks
