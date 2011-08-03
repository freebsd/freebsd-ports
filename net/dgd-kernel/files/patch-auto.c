$FreeBSD$

--- kernellib/kernel/lib/auto.c.orig	2011-07-30 14:18:12.000000000 -0700
+++ kernellib/kernel/lib/auto.c	2011-07-30 14:19:44.000000000 -0700
@@ -765,11 +765,11 @@
 {
     object rsrcd;
     int stack, ticks;
-    string function;
+    string funcname;
     mixed tls, *limits, result;
 
     rsrcd = ::find_object(RSRCD);
-    function = arg1;
+    funcname = arg1;
     stack = ::status()[ST_STACKDEPTH];
     ticks = ::status()[ST_TICKS];
     rlimits (-1; -1) {
@@ -781,7 +781,7 @@
     }
 
     rlimits (limits[LIM_MAXSTACK]; limits[LIM_MAXTICKS]) {
-	result = call_other(this_object(), function, args...);
+	result = call_other(this_object(), funcname, args...);
 
 	ticks = ::status()[ST_TICKS];
 	rlimits (-1; -1) {
@@ -797,36 +797,36 @@
  * NAME:	call_limited()
  * DESCRIPTION:	call a function with the current object owner's resource limits
  */
-static mixed call_limited(string function, mixed args...)
+static mixed call_limited(string funcname, mixed args...)
 {
-    CHECKARG(function, 1, "call_limited");
+    CHECKARG(funcname, 1, "call_limited");
     if (!this_object()) {
 	return nil;
     }
-    CHECKARG(function_object(function, this_object()) != AUTO ||
-							 function == "create",
+    CHECKARG(function_object(funcname, this_object()) != AUTO ||
+							 funcname == "create",
 	     1, "call_limited");
 
-    return _F_call_limited(function, args);
+    return _F_call_limited(funcname, args);
 }
 
 /*
  * NAME:	call_out()
  * DESCRIPTION:	start a callout
  */
-static int call_out(string function, mixed delay, mixed args...)
+static int call_out(string funcname, mixed delay, mixed args...)
 {
     int type;
     string oname;
 
-    CHECKARG(function, 1, "call_out");
+    CHECKARG(funcname, 1, "call_out");
     type = typeof(delay);
     CHECKARG(type == T_INT || type == T_FLOAT, 2, "call_out");
     if (!this_object()) {
 	return 0;
     }
-    CHECKARG(function_object(function, this_object()) != AUTO ||
-							 function == "create",
+    CHECKARG(function_object(funcname, this_object()) != AUTO ||
+							 funcname == "create",
 	     1, "call_out");
     oname = object_name(this_object());
     if (sscanf(oname, "%*s#-1") != 0) {
@@ -838,9 +838,9 @@
      */
     if (sscanf(oname, "/kernel/%*s") != 0) {
 	/* direct callouts for kernel objects */
-	return ::call_out(function, delay, args...);
+	return ::call_out(funcname, delay, args...);
     }
-    return ::call_out("_F_callout", delay, function, 0, args);
+    return ::call_out("_F_callout", delay, funcname, 0, args);
 }
 
 /*
@@ -867,11 +867,11 @@
  * NAME:	_F_callout()
  * DESCRIPTION:	callout gate
  */
-nomask void _F_callout(string function, int handle, mixed *args)
+nomask void _F_callout(string funcname, int handle, mixed *args)
 {
     if (!previous_program()) {
 	if (handle == 0 && !::find_object(RSRCD)->suspended(this_object())) {
-	    _F_call_limited(function, args);
+	    _F_call_limited(funcname, args);
 	} else {
 	    mixed *tls;
 	    mixed **callouts;
@@ -882,7 +882,7 @@
 		::find_object(RSRCD)->remove_callout(tls, this_object(),
 						     handle);
 	    }
-	    handle = ::call_out("_F_callout", LONG_TIME, function, 0, args);
+	    handle = ::call_out("_F_callout", LONG_TIME, funcname, 0, args);
 	    callouts = ::status(this_object())[O_CALLOUTS];
 	    for (i = sizeof(callouts); callouts[--i][CO_HANDLE] != handle; ) ;
 	    callouts[i][CO_FIRSTXARG + 1] = handle;
