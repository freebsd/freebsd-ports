--- cpp/client/ct.cc.orig	2016-02-02 11:35:23 UTC
+++ cpp/client/ct.cc
@@ -461,8 +461,8 @@ static void MakeCert() {
 // (This means the relevant section should be last in the configuration.)
 // 1.2.3.1=DER:[raw encoding of proof]
 static void WriteProofToConfig() {
-  CHECK(!FLAGS_sct_token.empty()) << google::ProgramUsage();
-  CHECK(!FLAGS_extensions_config_out.empty()) << google::ProgramUsage();
+  CHECK(!FLAGS_sct_token.empty()) << gflags::ProgramUsage();
+  CHECK(!FLAGS_extensions_config_out.empty()) << gflags::ProgramUsage();
 
   string sct;
 
@@ -489,8 +489,8 @@ static const char kPEMLabel[] = "SERVERI
 // Wrap the proof in the format expected by the TLS extension,
 // so that we can feed it to OpenSSL.
 static void ProofToExtensionData() {
-  CHECK(!FLAGS_sct_token.empty()) << google::ProgramUsage();
-  CHECK(!FLAGS_tls_extension_data_out.empty()) << google::ProgramUsage();
+  CHECK(!FLAGS_sct_token.empty()) << gflags::ProgramUsage();
+  CHECK(!FLAGS_tls_extension_data_out.empty()) << gflags::ProgramUsage();
 
   string serialized_sct;
   PCHECK(util::ReadBinaryFile(FLAGS_sct_token, &serialized_sct))
@@ -990,12 +990,12 @@ int Monitor() {
 // Exit code upon abnormal exit (CHECK failures): != 0
 // (on UNIX, 134 is expected)
 int main(int argc, char** argv) {
-  google::SetUsageMessage(argv[0] + string(kUsage));
+  gflags::SetUsageMessage(argv[0] + string(kUsage));
   util::InitCT(&argc, &argv);
 
   const string main_command(argv[0]);
   if (argc < 2) {
-    std::cout << google::ProgramUsage();
+    std::cout << gflags::ProgramUsage();
     return 1;
   }
 
@@ -1035,7 +1035,7 @@ int main(int argc, char** argv) {
   } else if (cmd == "sth") {
     ret = GetSTH();
   } else {
-    std::cout << google::ProgramUsage();
+    std::cout << gflags::ProgramUsage();
     ret = 1;
   }
 
