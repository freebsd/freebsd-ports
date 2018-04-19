--- src/daemon/command_line_args.h.orig	2018-04-12 18:39:37 UTC
+++ src/daemon/command_line_args.h
@@ -42,7 +42,7 @@ namespace daemon_args
   , "Specify configuration file"
   , (daemonizer::get_default_data_dir() / std::string(CRYPTONOTE_NAME ".conf")).string()
   , {{ &cryptonote::arg_testnet_on, &cryptonote::arg_stagenet_on }}
-  , [](std::array<bool, 2> testnet_stagenet, bool defaulted, std::string val) {
+  , [](std::array<bool, 2> testnet_stagenet, bool defaulted, std::string val) -> std::string {
       if (testnet_stagenet[0] && defaulted)
         return (daemonizer::get_default_data_dir() / "testnet" /
                 std::string(CRYPTONOTE_NAME ".conf")).string();
@@ -57,7 +57,7 @@ namespace daemon_args
   , "Specify log file"
   , (daemonizer::get_default_data_dir() / std::string(CRYPTONOTE_NAME ".log")).string()
   , {{ &cryptonote::arg_testnet_on, &cryptonote::arg_stagenet_on }}
-  , [](std::array<bool, 2> testnet_stagenet, bool defaulted, std::string val) {
+  , [](std::array<bool, 2> testnet_stagenet, bool defaulted, std::string val) -> std::string {
       if (testnet_stagenet[0] && defaulted)
         return (daemonizer::get_default_data_dir() / "testnet" /
                 std::string(CRYPTONOTE_NAME ".log")).string();
