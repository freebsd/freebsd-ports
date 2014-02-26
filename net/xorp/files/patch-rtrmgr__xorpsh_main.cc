--- ./rtrmgr/xorpsh_main.cc.orig	2012-01-11 17:46:45.000000000 +0000
+++ ./rtrmgr/xorpsh_main.cc	2014-02-26 21:17:13.000000000 +0000
@@ -146,7 +146,7 @@
       _verbose(verbose),
       _ipc_name(IPCname),
       _got_config(false),
-      _got_modules(false),
+      // _got_modules(false),
       _mode(MODE_INITIALIZING),
       _xorpsh_interface(&_xrl_router, *this)
 {
@@ -667,7 +667,7 @@
 	_router_cli->notify_user(response, /* urgent */ true);
 	// XXX it's not clear we can continue if this happens
     }
-    response == "";
+    // response == "";
     if (!_ct->apply_deletions(user_id, deletions,
 			      /* this is not a provisional change */ false,
 			      response)) {
