--- programs/mythbackend/scheduler.cpp~	Sat Sep  9 13:50:38 2006
+++ programs/mythbackend/scheduler.cpp	Mon Jan 15 14:06:50 2007
@@ -1578,7 +1578,7 @@
     gContext->dispatch(me);
 
     QString halt_cmd = gContext->GetSetting("ServerHaltCommand",
-                                            "sudo /sbin/halt -p");
+                                            "/sbin/shutdown -p now");
 
     if (!halt_cmd.isEmpty())
     {
