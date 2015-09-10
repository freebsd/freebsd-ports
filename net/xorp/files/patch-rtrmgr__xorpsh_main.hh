--- rtrmgr/xorpsh_main.hh.orig	2012-01-11 17:56:10 UTC
+++ rtrmgr/xorpsh_main.hh
@@ -151,7 +151,7 @@ private:
     string		_authfile;
     string		_authtoken;
     bool		_got_config;
-    bool		_got_modules;
+    // bool		_got_modules;
     string		_configuration;
 
     bool		_xrl_generic_done;	// XRL startup/shutdown flag
