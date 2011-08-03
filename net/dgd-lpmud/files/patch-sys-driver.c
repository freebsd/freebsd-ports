$FreeBSD$

--- 2.4.5/dgd/sys/driver.c.orig	2011-08-02 10:20:37.000000000 -0700
+++ 2.4.5/dgd/sys/driver.c	2011-08-02 10:21:09.000000000 -0700
@@ -153,7 +153,7 @@
  * NAME:	touch()
  * DESCRIPTION: determine whether to preserve untouched status.
  */
-static int touch(object obj, string function)
+static int touch(object obj, string funcname)
 {
     return 0;
 }
@@ -273,7 +273,7 @@
 static void runtime_error(string error, int caught, int ticks)
 {
     mixed **trace;
-    string progname, objname, function, str;
+    string progname, objname, funcname, str;
     int i, sz, line, len;
     object player;
 
@@ -285,13 +285,13 @@
     if ((sz=sizeof(trace) - 1) != 0) {
 	for (i = 0; i < sz; i++) {
 	    progname = trace[i][1];
-	    function = trace[i][2];
+	    funcname = trace[i][2];
 
-	    if (progname == AUTO && strlen(function) > 3) {
-		switch (function[0 .. 2]) {
+	    if (progname == AUTO && strlen(funcname) > 3) {
+		switch (funcname[0 .. 2]) {
 		case "bad":
 		    progname = trace[i - 1][1];
-		    function = trace[i - 1][2];
+		    funcname = trace[i - 1][2];
 		case "_F_":
 		case "_Q_":
 		    continue;
@@ -310,8 +310,8 @@
 		str = "    " + line;
 		str = str[strlen(str) - 4 ..];
 	    }
-	    str += " " + function + " ";
-	    len = strlen(function);
+	    str += " " + funcname + " ";
+	    len = strlen(funcname);
 	    if (len < 17) {
 		str += "                 "[len ..];
 	    }
