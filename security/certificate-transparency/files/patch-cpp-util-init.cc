--- cpp/util/init.cc.orig	2016-10-14 17:11:57 UTC
+++ cpp/util/init.cc
@@ -49,8 +49,8 @@ void LibEventLog(int severity, const cha
 
 
 void InitCT(int* argc, char** argv[]) {
-  google::SetVersionString(cert_trans::kBuildVersion);
-  google::ParseCommandLineFlags(argc, argv, true);
+  gflags::SetVersionString(cert_trans::kBuildVersion);
+  gflags::ParseCommandLineFlags(argc, argv, true);
   google::InitGoogleLogging(*argv[0]);
   google::InstallFailureSignalHandler();
 
@@ -68,7 +68,7 @@ void InitCT(int* argc, char** argv[]) {
 
   cert_trans::LoadCtExtensions();
 
-  LOG(INFO) << "Build version: " << google::VersionString();
+  LOG(INFO) << "Build version: " << gflags::VersionString();
 #ifdef ENABLE_HARDENING
   LOG(INFO) << "Binary built with hardening enabled.";
 #else
