--- rtrmgr/cli.cc.orig	2012-01-11 17:56:10 UTC
+++ rtrmgr/cli.cc
@@ -741,7 +741,7 @@ RouterCLI::op_mode_help(const vector<str
     path = token_vector2line(command_global_name);
     XLOG_ASSERT(path.substr(0, 4) == "help");
     if (path.size() == 4) {
-	trimmed_path == "";
+	trimmed_path = "";
     } else {
 	XLOG_ASSERT(path.substr(0, 5) == "help ");
 	trimmed_path = path.substr(5, path.size() - 5);
@@ -1062,7 +1062,7 @@ RouterCLI::configure_mode_help(const vec
     path = token_vector2line(command_global_name);
     XLOG_ASSERT(path.substr(0, 4) == "help");
     if (path.size() == 4) {
-	trimmed_path == "";
+	trimmed_path = "";
     } else {
 	XLOG_ASSERT(path.substr(0, 5) == "help ");
 	trimmed_path = path.substr(5, path.size() - 5);
