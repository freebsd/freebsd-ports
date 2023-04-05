--- projects/GKCore/GKCore/GKUtils.cs.orig	2023-03-27 21:40:19 UTC
+++ projects/GKCore/GKCore/GKUtils.cs
@@ -1758,7 +1758,11 @@ namespace GKCore
 
         public static string GetTempDir()
         {
-            string tempPath = Environment.GetEnvironmentVariable("TEMP");
+            string tempPath;
+            if (SysUtils.IsUnix())
+                tempPath = Environment.GetEnvironmentVariable("TMP") ?? "/tmp";
+            else
+                tempPath = Environment.GetEnvironmentVariable("TEMP");
             return tempPath + Path.DirectorySeparatorChar;
         }
 
@@ -1772,8 +1776,7 @@ namespace GKCore
 
         public static string GetAppPath()
         {
-            string result = Path.GetFullPath(Path.Combine(GetBinPath(), @".." + Path.DirectorySeparatorChar));
-            return result;
+            return GetBinPath();
         }
 
         public static string GetPluginsPath()
