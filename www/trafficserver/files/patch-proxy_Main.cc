--- proxy/Main.cc.orig	2016-07-11 23:03:32 UTC
+++ proxy/Main.cc
@@ -539,7 +539,7 @@ cmd_list(char * /* cmd ATS_UNUSED */)
 
   Note("Cache Storage:");
   Store tStore;
-  if (tStore.read_config() < 0) {
+  if (tStore.read_config() != NULL) {
     Note("config read failure");
     return CMD_FAILED;
   } else {
