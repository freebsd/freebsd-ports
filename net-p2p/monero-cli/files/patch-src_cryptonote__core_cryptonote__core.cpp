--- src/cryptonote_core/cryptonote_core.cpp.orig	2018-04-12 18:30:36 UTC
+++ src/cryptonote_core/cryptonote_core.cpp
@@ -81,7 +81,7 @@ namespace cryptonote
   , "Specify data directory"
   , tools::get_default_data_dir()
   , {{ &arg_testnet_on, &arg_stagenet_on }}
-  , [](std::array<bool, 2> testnet_stagenet, bool defaulted, std::string val) {
+  , [](std::array<bool, 2> testnet_stagenet, bool defaulted, std::string val) -> std::string {
       if (testnet_stagenet[0])
         return (boost::filesystem::path(val) / "testnet").string();
       else if (testnet_stagenet[1])
