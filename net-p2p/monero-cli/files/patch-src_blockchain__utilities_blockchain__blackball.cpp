--- src/blockchain_utilities/blockchain_blackball.cpp.orig	2018-04-12 18:35:24 UTC
+++ src/blockchain_utilities/blockchain_blackball.cpp
@@ -165,7 +165,7 @@ int main(int argc, char* argv[])
       "blackball-db-dir", "Specify blackball database directory",
       get_default_db_path(),
       {{ &arg_testnet_on, &arg_stagenet_on }},
-      [](std::array<bool, 2> testnet_stagenet, bool defaulted, std::string val) {
+      [](std::array<bool, 2> testnet_stagenet, bool defaulted, std::string val) -> std::string {
         if (testnet_stagenet[0])
           return (boost::filesystem::path(val) / "testnet").string();
         else if (testnet_stagenet[1])
