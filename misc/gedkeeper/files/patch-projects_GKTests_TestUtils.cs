--- projects/GKTests/TestUtils.cs.orig	2019-09-17 11:17:12 UTC
+++ projects/GKTests/TestUtils.cs
@@ -205,11 +205,7 @@ namespace GKTests
 
         public static string GetTempFilePath(string fileName)
         {
-            #if !__MonoCS__
             fileName = GKUtils.GetTempDir() + fileName;
-            #else
-            fileName = GKUtils.GetHomePath() + fileName;
-            #endif
 
             if (File.Exists(fileName)) File.Delete(fileName); // for local tests!
 
