--- cpp/tools/dump_sth.cc.orig	2016-10-14 17:11:57 UTC
+++ cpp/tools/dump_sth.cc
@@ -26,11 +26,11 @@ void DumpSth(const char* filename) {
 
 
 int main(int argc, char* argv[]) {
-  google::SetVersionString(cert_trans::kBuildVersion);
-  google::ParseCommandLineFlags(&argc, &argv, true);
+  gflags::SetVersionString(cert_trans::kBuildVersion);
+  gflags::ParseCommandLineFlags(&argc, &argv, true);
   google::InitGoogleLogging(argv[0]);
 
-  LOG(INFO) << "Build version: " << google::VersionString();
+  LOG(INFO) << "Build version: " << gflags::VersionString();
 
   for (int i = 1; i < argc; ++i)
     DumpSth(argv[i]);
