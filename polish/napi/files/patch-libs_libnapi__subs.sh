--- libs/libnapi_subs.sh.orig	2020-04-26 01:52:36 UTC
+++ libs/libnapi_subs.sh
@@ -189,11 +189,11 @@ subs_convertFormat() {
     subotage_processFile \
         "${videoFileDir}/${sourceSubsFileName}" \
         "none" \
-        "0" \
+        "${fps}" \
         "" \
         "${videoFileDir}/${destSubsFileName}" \
         "${format}" \
-        "${fps}" \
+        "0" \
         ""
     convStatus=$?
 
