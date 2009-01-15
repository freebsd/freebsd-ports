--- programs/mythfrontend/main.cpp	2008-09-17 20:22:31.000000000 +0200
+++ programs/mythfrontend/main.cpp	2008-09-17 20:22:58.000000000 +0200
@@ -577,7 +577,7 @@
 void haltnow()
 {
     QString halt_cmd = gContext->GetSetting("HaltCommand", 
-                                            "sudo /sbin/halt -p");
+                                            "/sbin/shutdown -p now");
     if (!halt_cmd.isEmpty())
         system(halt_cmd.ascii());
 }
