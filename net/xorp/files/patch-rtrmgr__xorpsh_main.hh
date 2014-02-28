--- ./rtrmgr/xorpsh_main.hh.orig	2011-03-16 21:16:14.000000000 +0000
+++ ./rtrmgr/xorpsh_main.hh	2014-02-26 21:17:13.000000000 +0000
@@ -151,7 +151,7 @@
     string		_authfile;
     string		_authtoken;
     bool		_got_config;
-    bool		_got_modules;
+    // bool		_got_modules;
     string		_configuration;
 
     bool		_xrl_generic_done;	// XRL startup/shutdown flag
