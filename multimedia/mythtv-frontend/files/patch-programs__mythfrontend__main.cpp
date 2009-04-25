--- ./programs/mythfrontend/main.cpp.orig	2008-02-23 22:25:03.000000000 -0500
+++ ./programs/mythfrontend/main.cpp	2009-04-22 21:05:21.000000000 -0400
@@ -577,7 +577,7 @@
 void haltnow()
 {
     QString halt_cmd = gContext->GetSetting("HaltCommand", 
-                                            "sudo /sbin/halt -p");
+                                            "/sbin/shutdown -p now");
     if (!halt_cmd.isEmpty())
         system(halt_cmd.ascii());
 }
