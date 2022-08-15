--- libdino/src/service/call_peer_state.vala	2022-02-13 00:18:06.000000000 +0300
+++ libdino/src/service/call_peer_state.vala	2022-08-15 12:07:56.735765000 +0300
@@ -45,7 +45,10 @@
         this.stream_interactor = stream_interactor;
         this.calls = stream_interactor.get_module(Calls.IDENTITY);
 
-        var session_info_type = stream_interactor.module_manager.get_module(call.account, Xep.JingleRtp.Module.IDENTITY).session_info_type;
+        Xep.JingleRtp.Module jinglertp_module = stream_interactor.module_manager.get_module(call.account, Xep.JingleRtp.Module.IDENTITY);
+        if (jinglertp_module == null) return;
+
+        var session_info_type = jinglertp_module.session_info_type;
         session_info_type.mute_update_received.connect((session,mute, name) => {
             if (this.sid != session.sid) return;
 
