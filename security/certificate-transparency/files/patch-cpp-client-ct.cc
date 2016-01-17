--- cpp/client/ct.cc.orig	2015-10-24 17:45:59.877372000 +0200
+++ cpp/client/ct.cc	2015-10-24 17:47:35.728512000 +0200
@@ -458,8 +458,8 @@ static void MakeCert() {
 // (This means the relevant section should be last in the configuration.)
 // 1.2.3.1=DER:[raw encoding of proof]
 static void WriteProofToConfig() {
-  CHECK(!FLAGS_sct_token.empty()) << google::ProgramUsage();
-  CHECK(!FLAGS_extensions_config_out.empty()) << google::ProgramUsage();
+  CHECK(!FLAGS_sct_token.empty()) << gflags::ProgramUsage();
+  CHECK(!FLAGS_extensions_config_out.empty()) << gflags::ProgramUsage();
 
   string sct;
 
@@ -486,8 +486,8 @@ static const char kPEMLabel[] = "SERVERI
 // Wrap the proof in the format expected by the TLS extension,
 // so that we can feed it to OpenSSL.
 static void ProofToExtensionData() {
-  CHECK(!FLAGS_sct_token.empty()) << google::ProgramUsage();
-  CHECK(!FLAGS_tls_extension_data_out.empty()) << google::ProgramUsage();
+  CHECK(!FLAGS_sct_token.empty()) << gflags::ProgramUsage();
+  CHECK(!FLAGS_tls_extension_data_out.empty()) << gflags::ProgramUsage();
 
   string serialized_sct;
   PCHECK(util::ReadBinaryFile(FLAGS_sct_token, &serialized_sct))
@@ -986,12 +986,12 @@ int Monitor() {
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
 
@@ -1031,7 +1031,7 @@ int main(int argc, char** argv) {
   } else if (cmd == "sth") {
     ret = GetSTH();
   } else {
-    std::cout << google::ProgramUsage();
+    std::cout << gflags::ProgramUsage();
     ret = 1;
   }
 
