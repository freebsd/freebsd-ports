--- dao/main.cc.orig	Sat Dec 28 03:01:20 2002
+++ dao/main.cc	Sat Dec 28 03:04:38 2002
@@ -1890,11 +1890,7 @@
 
   SETTINGS = new Settings;
 
-  settingsPath = "/etc/cdrdao.conf";
-  if (SETTINGS->read(settingsPath) == 0)
-    message(3, "Read settings from \"%s\".", settingsPath);
-
-  settingsPath = "/etc/defaults/cdrdao";
+  settingsPath = "%%PREFIX%%/etc/cdrdao.conf";
   if (SETTINGS->read(settingsPath) == 0)
     message(3, "Read settings from \"%s\".", settingsPath);
 
