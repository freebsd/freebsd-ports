--- dao/main.cc.orig	2025-12-05 11:17:35 UTC
+++ dao/main.cc
@@ -2382,11 +2382,7 @@ int main(int argc, char **argv)
 
     Settings* settings = new Settings;
 
-    settingsPath = "/etc/cdrdao.conf";
-    if (settings->read(settingsPath) == 0)
-	log_message(3, "Read settings from \"%s\".", settingsPath);
-
-    settingsPath = "/etc/defaults/cdrdao";
+    settingsPath = "%%PREFIX%%/etc/cdrdao.conf";
     if (settings->read(settingsPath) == 0)
 	log_message(3, "Read settings from \"%s\".", settingsPath);
 
