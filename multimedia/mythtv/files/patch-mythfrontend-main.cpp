--- programs/mythfrontend/main.cpp~	Mon Sep 11 15:04:42 2006
+++ programs/mythfrontend/main.cpp	Mon Jan 15 14:06:28 2007
@@ -472,7 +472,7 @@
 void haltnow()
 {
     QString halt_cmd = gContext->GetSetting("HaltCommand", 
-                                            "sudo /sbin/halt -p");
+                                            "/sbin/shutdown -p now");
     if (!halt_cmd.isEmpty())
         system(halt_cmd.ascii());
 }
