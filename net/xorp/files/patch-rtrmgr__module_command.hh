--- rtrmgr/module_command.hh.orig	2012-01-11 17:56:10 UTC
+++ rtrmgr/module_command.hh
@@ -87,6 +87,7 @@ private:
     Action*		_status_method;
     Action*		_startup_method;
     Action*		_shutdown_method;
+public:
     bool		_execute_done;
     bool		_verbose;	// Set to true if output is verbose
 };
