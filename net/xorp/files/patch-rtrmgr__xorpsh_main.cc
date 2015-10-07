--- rtrmgr/xorpsh_main.cc.orig	2012-01-11 17:56:10 UTC
+++ rtrmgr/xorpsh_main.cc
@@ -146,7 +146,7 @@ XorpShell::XorpShell(EventLoop& eventloo
       _verbose(verbose),
       _ipc_name(IPCname),
       _got_config(false),
-      _got_modules(false),
+      // _got_modules(false),
       _mode(MODE_INITIALIZING),
       _xorpsh_interface(&_xrl_router, *this)
 {
@@ -667,7 +667,7 @@ XorpShell::config_changed(uid_t user_id,
 	_router_cli->notify_user(response, /* urgent */ true);
 	// XXX it's not clear we can continue if this happens
     }
-    response == "";
+    // response == "";
     if (!_ct->apply_deletions(user_id, deletions,
 			      /* this is not a provisional change */ false,
 			      response)) {
