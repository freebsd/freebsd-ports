--- ./rtrmgr/cli.cc.orig	2011-03-16 21:16:13.000000000 +0000
+++ ./rtrmgr/cli.cc	2014-02-26 21:17:13.000000000 +0000
@@ -741,7 +741,7 @@
     path = token_vector2line(command_global_name);
     XLOG_ASSERT(path.substr(0, 4) == "help");
     if (path.size() == 4) {
-	trimmed_path == "";
+	trimmed_path = "";
     } else {
 	XLOG_ASSERT(path.substr(0, 5) == "help ");
 	trimmed_path = path.substr(5, path.size() - 5);
@@ -1062,7 +1062,7 @@
     path = token_vector2line(command_global_name);
     XLOG_ASSERT(path.substr(0, 4) == "help");
     if (path.size() == 4) {
-	trimmed_path == "";
+	trimmed_path = "";
     } else {
 	XLOG_ASSERT(path.substr(0, 5) == "help ");
 	trimmed_path = path.substr(5, path.size() - 5);
