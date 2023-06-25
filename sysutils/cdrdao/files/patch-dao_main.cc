--- dao/main.cc.orig	2023-02-03 14:46:06 UTC
+++ dao/main.cc
@@ -2450,11 +2450,7 @@ int main(int argc, char **argv)
 
     Settings* settings = new Settings;
 
-    settingsPath = "/etc/cdrdao.conf";
-    if (settings->read(settingsPath) == 0)
-	log_message(3, "Read settings from \"%s\".", settingsPath);
-
-    settingsPath = "/etc/defaults/cdrdao";
+    settingsPath = "%%PREFIX%%/etc/cdrdao.conf";
     if (settings->read(settingsPath) == 0)
 	log_message(3, "Read settings from \"%s\".", settingsPath);
 
