--- osquery/main/run.cpp.orig	2015-05-05 00:16:41 UTC
+++ osquery/main/run.cpp
@@ -10,10 +10,9 @@
 
 #include <errno.h>
 
-#include <gflags/gflags.h>
-
 #include <osquery/core.h>
 #include <osquery/events.h>
+#include <osquery/flags.h>
 #include <osquery/logger.h>
 #include <osquery/sql.h>
 
@@ -27,7 +26,7 @@ int main(int argc, char* argv[]) {
 
   // Let gflags parse the non-help options/flags.
   GFLAGS_NAMESPACE::ParseCommandLineFlags(&argc, &argv, false);
-  GFLAGS_NAMESPACE::InitGoogleLogging(argv[0]);
+  google::InitGoogleLogging(argv[0]);
 
   if (FLAGS_query == "") {
     fprintf(stderr, "Usage: %s --query=\"query\"\n", argv[0]);
