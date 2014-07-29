--- dao/main.cc.orig	Sat Dec 28 03:01:20 2002
+++ dao/main.cc	Sat Dec 28 03:04:38 2002
@@ -2314,11 +2314,7 @@
 
     Settings* settings = new Settings;
 
-    settingsPath = "/etc/cdrdao.conf";
-    if (settings->read(settingsPath) == 0)
-	log_message(3, "Read settings from \"%s\".", settingsPath);
-
-    settingsPath = "/etc/defaults/cdrdao";
+    settingsPath = "%%PREFIX%%/etc/cdrdao.conf";
     if (settings->read(settingsPath) == 0)
 	log_message(3, "Read settings from \"%s\".", settingsPath);
 
