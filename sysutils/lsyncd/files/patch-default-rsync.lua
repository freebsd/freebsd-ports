--- default-rsync.lua.orig	2018-03-09 12:39:11 UTC
+++ default-rsync.lua
@@ -682,7 +682,7 @@ rsync.exitcodes  = default.rsyncExitCode
 rsync.rsync =
 {
 	-- The rsync binary to be called.
-	binary        = '/usr/bin/rsync',
+	binary        = '/usr/local/bin/rsync',
 	links         = true,
 	times         = true,
 	protect_args  = true
