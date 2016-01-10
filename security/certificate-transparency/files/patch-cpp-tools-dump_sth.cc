--- cpp/tools/dump_sth.cc.orig	2015-10-27 10:35:13.973569000 +0100
+++ cpp/tools/dump_sth.cc	2015-10-27 10:35:44.745588000 +0100
@@ -26,11 +26,11 @@ void DumpSth(const char *filename) {
 
 
 int main(int argc, char *argv[]) {
-  google::SetVersionString(cert_trans::kBuildVersion);
-  google::ParseCommandLineFlags(&argc, &argv, true);
+  gflags::SetVersionString(cert_trans::kBuildVersion);
+  gflags::ParseCommandLineFlags(&argc, &argv, true);
   google::InitGoogleLogging(argv[0]);
 
-  LOG(INFO) << "Build version: " << google::VersionString();
+  LOG(INFO) << "Build version: " << gflags::VersionString();
 
   for (int i = 1; i < argc; ++i)
     DumpSth(argv[i]);
