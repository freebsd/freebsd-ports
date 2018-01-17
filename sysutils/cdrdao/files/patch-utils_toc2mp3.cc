--- utils/toc2mp3.cc.orig	2003-02-22 10:16:56 UTC
+++ utils/toc2mp3.cc
@@ -143,8 +143,8 @@ static void printUsage()
 
   message(0, "LAME encoder version: %s", get_lame_version());
   message(0, "Supported bit rates: ");
-  for (int i = 0; i < 16 && bitrate_table[1][i] >= 0; i++) {
-    message(0, "%d ", bitrate_table[1][i]);
+  for (int br, i = 0; (br = lame_get_bitrate(1, i)) >= 0; i++) {
+    message(0, "%d ", br);
   }
   message(0, "");
 }
@@ -238,8 +238,8 @@ lame_global_flags *init_encoder(int bitr
   lame_global_flags *lf;
   int bitrateOk = 0;
 
-  for (int i = 0; bitrate_table[1][i] >= 0 && !bitrateOk; i++) {
-    if (bitrate == bitrate_table[1][i])
+  for (int br, i = 0; (br = lame_get_bitrate(1, i)) >= 0 && !bitrateOk; i++) {
+    if (br == bitrate)
       bitrateOk = 1;
   }
 
