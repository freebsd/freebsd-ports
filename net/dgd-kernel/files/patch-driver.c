$FreeBSD$

--- kernellib/kernel/sys/driver.c.orig	2011-07-30 14:15:13.000000000 -0700
+++ kernellib/kernel/sys/driver.c	2011-07-30 14:16:23.000000000 -0700
@@ -596,16 +596,16 @@
  * NAME:	_touch()
  * DESCRIPTION:	touch an object that has been flagged with call_touch()
  */
-private int _touch(mixed *tls, object obj, string function)
+private int _touch(mixed *tls, object obj, string funcname)
 {
-    return objectd->touch(obj, function);
+    return objectd->touch(obj, funcname);
 }
 
 /*
  * NAME:	touch()
  * DESCRIPTION:	wrapper for _touch()
  */
-static int touch(object obj, string function)
+static int touch(object obj, string funcname)
 {
     mixed *tls;
     string prog;
@@ -614,7 +614,7 @@
 	if (!previous_object()) {
 	    tls = allocate(tls_size);
 	} else if (KERNEL()) {
-	    prog = function_object(function, obj);
+	    prog = function_object(funcname, obj);
 	    if (prog && sscanf(prog, "/kernel/%*s") != 0 &&
 		status()[ST_STACKDEPTH] < 0) {
 		/*
@@ -625,7 +625,7 @@
 	    }
 	}
 
-	return _touch(tls, obj, function);
+	return _touch(tls, obj, funcname);
     }
     return FALSE;
 }
@@ -795,7 +795,7 @@
 private void _runtime_error(mixed tls, string str, int caught, int ticks,
 			    mixed **trace)
 {
-    string line, function, progname, objname;
+    string line, funcname, progname, objname;
     int i, sz, len;
     object user;
 
@@ -836,10 +836,10 @@
 		line = line[strlen(line) - 4 ..];
 	    }
 
-	    function = trace[i][TRACE_FUNCTION];
-	    len = strlen(function);
+	    funcname = trace[i][TRACE_FUNCTION];
+	    len = strlen(funcname);
 	    if (progname == AUTO && i != sz - 1 && len > 3) {
-		switch (function[.. 2]) {
+		switch (funcname[.. 2]) {
 		case "bad":
 		case "_F_":
 		case "_Q_":
@@ -847,7 +847,7 @@
 		}
 	    }
 	    if (len < 17) {
-		function += "                 "[len ..];
+		funcname += "                 "[len ..];
 	    }
 
 	    objname = trace[i][TRACE_OBJNAME];
@@ -857,10 +857,10 @@
 		    objname[len] == '#') {
 		    objname = objname[len ..];
 		}
-		str += line + " " + function + " " + progname + " (" + objname +
+		str += line + " " + funcname + " " + progname + " (" + objname +
 		       ")\n";
 	    } else {
-		str += line + " " + function + " " + progname + "\n";
+		str += line + " " + funcname + " " + progname + "\n";
 	    }
 	}
 
@@ -914,7 +914,7 @@
 static void atomic_error(string str, int atom, int ticks)
 {
     mixed **trace;
-    string line, function, progname, objname;
+    string line, funcname, progname, objname;
     int i, sz, len;
     object obj;
 
@@ -936,10 +936,10 @@
 		line = line[strlen(line) - 4 ..];
 	    }
 
-	    function = trace[i][TRACE_FUNCTION];
-	    len = strlen(function);
+	    funcname = trace[i][TRACE_FUNCTION];
+	    len = strlen(funcname);
 	    if (progname == AUTO && i != sz - 1 && len > 3) {
-		switch (function[.. 2]) {
+		switch (funcname[.. 2]) {
 		case "bad":
 		case "_F_":
 		case "_Q_":
@@ -947,7 +947,7 @@
 		}
 	    }
 	    if (len < 17) {
-		function += "                 "[len ..];
+		funcname += "                 "[len ..];
 	    }
 
 	    objname = trace[i][TRACE_OBJNAME];
@@ -957,10 +957,10 @@
 		    objname[len] == '#') {
 		    objname = objname[len ..];
 		}
-		str += line + " " + function + " " + progname + " (" + objname +
+		str += line + " " + funcname + " " + progname + " (" + objname +
 		       ")\n";
 	    } else {
-		str += line + " " + function + " " + progname + "\n";
+		str += line + " " + funcname + " " + progname + "\n";
 	    }
 	}
 
