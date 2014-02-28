--- ./rtrmgr/module_command.hh.orig	2010-07-19 21:10:33.000000000 +0000
+++ ./rtrmgr/module_command.hh	2014-02-26 21:17:13.000000000 +0000
@@ -87,6 +87,7 @@
     Action*		_status_method;
     Action*		_startup_method;
     Action*		_shutdown_method;
+public:
     bool		_execute_done;
     bool		_verbose;	// Set to true if output is verbose
 };
