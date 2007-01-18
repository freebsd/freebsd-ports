--- settings.c.orig	Thu Jan 11 16:37:43 2007
+++ settings.c	Wed Jan 17 14:34:49 2007
@@ -165,6 +165,7 @@
 {
     char* userHomeDir;
     int pathLen;
+    DIR* openDirTest;
     
     userHomeDir = getenv("HOME");
     if(userHomeDir == NULL)
@@ -181,7 +182,6 @@
     }
     
     /* MAKE sure userHomeDir is a valid directory */
-    DIR* openDirTest;
     
     openDirTest = opendir(userHomeDir);
     if(openDirTest == NULL)
@@ -222,9 +222,9 @@
     GBLsettingsDictionary = iniparser_load(configFileName);
     if(GBLsettingsDictionary == NULL)
     {
-        printWarning("failed to open config file for reading, trying to create");
-        
         int newConfigFile;
+        
+        printWarning("failed to open config file for reading, trying to create");
         
         newConfigFile = creat(configFileName, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
         if(newConfigFile <= 0)
