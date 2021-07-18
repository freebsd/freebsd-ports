--- src/mgr/ActivePyModules.cc.orig	2021-05-13 17:23:08 UTC
+++ src/mgr/ActivePyModules.cc
@@ -497,7 +497,7 @@ void ActivePyModules::notify_all(const std::string &no
     // Send all python calls down a Finisher to avoid blocking
     // C++ code, and avoid any potential lock cycles.
     dout(15) << "queuing notify to " << name << dendl;
-    finisher.queue(new FunctionContext([module, notify_type, notify_id](int r){
+    finisher.queue(new FunctionContext([module = module, notify_type, notify_id](int r){
       module->notify(notify_type, notify_id);
     }));
   }
@@ -516,7 +516,7 @@ void ActivePyModules::notify_all(const LogEntry &log_e
     // log_entry: we take a copy because caller's instance is
     // probably ephemeral.
     dout(15) << "queuing notify (clog) to " << name << dendl;
-    finisher.queue(new FunctionContext([module, log_entry](int r){
+    finisher.queue(new FunctionContext([module = module, log_entry](int r){
       module->notify_clog(log_entry);
     }));
   }
@@ -1015,7 +1015,7 @@ void ActivePyModules::config_notify()
     // Send all python calls down a Finisher to avoid blocking
     // C++ code, and avoid any potential lock cycles.
     dout(15) << "notify (config) " << name << dendl;
-    finisher.queue(new FunctionContext([module](int r){
+    finisher.queue(new FunctionContext([module = module](int r){
 					 module->config_notify();
 				       }));
   }
