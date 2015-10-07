--- rtrmgr/module_manager.hh.orig	2012-01-11 17:56:10 UTC
+++ rtrmgr/module_manager.hh
@@ -144,7 +144,9 @@ private:
     string	_expath;	// The expanded absolute path to the program
     bool	_do_exec;	// false indicates we're running in test mode,
 				// when we may not actually start any processes
+public:
     bool	_verbose;	// Set to true if output is verbose
+private:
     XorpTimer	_shutdown_timer; // A timer used during shutdown
     XorpCallback0<void>::RefPtr _terminate_cb; // The cb when module terminated
 };
