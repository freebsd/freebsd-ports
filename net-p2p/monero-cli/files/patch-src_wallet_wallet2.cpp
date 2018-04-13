--- src/wallet/wallet2.cpp.orig	2018-03-24 15:56:14 UTC
+++ src/wallet/wallet2.cpp
@@ -145,7 +145,7 @@ struct options {
     "shared-ringdb-dir", tools::wallet2::tr("Set shared ring database path"),
     get_default_ringdb_path(),
     testnet,
-    [](bool testnet, bool defaulted, std::string val) {
+    [](bool testnet, bool defaulted, std::string val) -> std::string {
       if (testnet)
         return (boost::filesystem::path(val) / "testnet").string();
       return val;
