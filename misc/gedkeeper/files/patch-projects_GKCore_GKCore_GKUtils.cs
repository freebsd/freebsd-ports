--- projects/GKCore/GKCore/GKUtils.cs.orig	2023-04-13 18:03:47 UTC
+++ projects/GKCore/GKCore/GKUtils.cs
@@ -1777,8 +1777,7 @@ namespace GKCore
 
         public static string GetAppPath()
         {
-            string result = Path.GetFullPath(Path.Combine(GetBinPath(), @".." + Path.DirectorySeparatorChar));
-            return result;
+            return GetBinPath();
         }
 
         public static string GetPluginsPath()
