--- ./programs/mythbackend/scheduler.cpp.orig	2008-02-20 22:23:22.000000000 -0500
+++ ./programs/mythbackend/scheduler.cpp	2009-02-23 09:59:26.000000000 -0500
@@ -2054,7 +2054,7 @@
     gContext->dispatch(me);
 
     QString halt_cmd = gContext->GetSetting("ServerHaltCommand",
-                                            "sudo /sbin/halt -p");
+                                            "/sbin/shutdown -p now");
 
     if (!halt_cmd.isEmpty())
     {
