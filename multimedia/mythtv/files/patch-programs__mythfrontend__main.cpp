--- ./programs/mythfrontend/main.cpp.orig	2008-02-23 22:25:03.000000000 -0500
+++ ./programs/mythfrontend/main.cpp	2009-02-23 09:59:26.000000000 -0500
@@ -577,7 +577,7 @@
 void haltnow()
 {
     QString halt_cmd = gContext->GetSetting("HaltCommand", 
-                                            "sudo /sbin/halt -p");
+                                            "/sbin/shutdown -p now");
     if (!halt_cmd.isEmpty())
         system(halt_cmd.ascii());
 }
