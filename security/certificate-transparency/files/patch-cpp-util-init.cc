--- cpp/util/init.cc.orig	2015-10-24 17:36:31.678280000 +0200
+++ cpp/util/init.cc	2015-10-24 17:37:42.378343000 +0200
@@ -48,8 +48,8 @@ void LibEventLog(int severity, const cha
 
 
 void InitCT(int* argc, char** argv[]) {
-  google::SetVersionString(cert_trans::kBuildVersion);
-  google::ParseCommandLineFlags(argc, argv, true);
+  gflags::SetVersionString(cert_trans::kBuildVersion);
+  gflags::ParseCommandLineFlags(argc, argv, true);
   google::InitGoogleLogging(*argv[0]);
   google::InstallFailureSignalHandler();
 
@@ -67,7 +67,7 @@ void InitCT(int* argc, char** argv[]) {
 
   cert_trans::LoadCtExtensions();
 
-  LOG(INFO) << "Build version: " << google::VersionString();
+  LOG(INFO) << "Build version: " << gflags::VersionString();
 #ifdef ENABLE_HARDENING
   LOG(INFO) << "Binary built with hardening enabled.";
 #else
