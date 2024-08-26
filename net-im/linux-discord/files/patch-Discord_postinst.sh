--- Discord/postinst.sh.orig	2024-08-22 19:49:42 UTC
+++ Discord/postinst.sh
@@ -16,16 +16,16 @@ for DIR in /home/* ; do
 # This is probably just paranoia, but some people claim that clearing out
 # cache and/or the sock file fixes bugs for them, so here we go
 for DIR in /home/* ; do
-  rm -rf "$DIR/.config/discord/Cache"
-  rm -rf "$DIR/.config/discord/GPUCache"
+  rm -Rf "$DIR/.config/discord/Cache"
+  rm -Rf "$DIR/.config/discord/GPUCache"
 
   # A previous bug made some files in this folder owned by root
   # and discord will hang if those files are present
   SETTINGS_FILE="$DIR/.config/discord/Crashpad/settings.dat"
   if [ -f "$SETTINGS_FILE" ]; then
-    OWNER=$(stat -c "%U" "$SETTINGS_FILE")
+    OWNER=$(stat -f "%Su" "$SETTINGS_FILE")
     if [ "$OWNER" = "root" ]; then
-      rm -rf "$DIR/.config/discord/Crashpad"
+      rm -Rf "$DIR/.config/discord/Crashpad"
     fi
   fi
 done
