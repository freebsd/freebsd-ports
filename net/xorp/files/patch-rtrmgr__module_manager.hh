--- ./rtrmgr/module_manager.hh.orig	2011-09-20 00:33:28.000000000 +0000
+++ ./rtrmgr/module_manager.hh	2014-02-26 21:17:13.000000000 +0000
@@ -144,7 +144,9 @@
     string	_expath;	// The expanded absolute path to the program
     bool	_do_exec;	// false indicates we're running in test mode,
 				// when we may not actually start any processes
+public:
     bool	_verbose;	// Set to true if output is verbose
+private:
     XorpTimer	_shutdown_timer; // A timer used during shutdown
     XorpCallback0<void>::RefPtr _terminate_cb; // The cb when module terminated
 };
