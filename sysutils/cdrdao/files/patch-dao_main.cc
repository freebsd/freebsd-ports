--- dao/main.cc.orig	2018-05-16 10:46:39 UTC
+++ dao/main.cc
@@ -2330,15 +2330,7 @@ int main(int argc, char **argv)
 
     Settings* settings = new Settings;
 
-    settingsPath = "/etc/cdrdao.conf";
-    if (settings->read(settingsPath) == 0)
-	log_message(3, "Read settings from \"%s\".", settingsPath);
-
-    settingsPath = "/etc/defaults/cdrdao";
-    if (settings->read(settingsPath) == 0)
-	log_message(3, "Read settings from \"%s\".", settingsPath);
-
-    settingsPath = "/etc/default/cdrdao";
+    settingsPath = "%%PREFIX%%/etc/cdrdao.conf";
     if (settings->read(settingsPath) == 0)
 	log_message(3, "Read settings from \"%s\".", settingsPath);
 
