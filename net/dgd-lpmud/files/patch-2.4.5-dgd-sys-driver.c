$FreeBSD$

--- 2.4.5/dgd/sys/driver.c.orig	1996-11-28 14:23:11.000000000 -0800
+++ 2.4.5/dgd/sys/driver.c	2009-07-05 19:04:50.000000000 -0700
@@ -3,6 +3,10 @@
 # include <status.h>
 # include "/dgd/lib/privilege.h"
 
+#ifdef __NETWORK_EXTENSIONS__
+#define	TELNET_PORT	2000
+#endif
+
 object *usr;		/* user array just before a swapout */
 
 /*
@@ -50,6 +54,9 @@
 	}
     }
     send_message("Setting up ipc.\n");
+#ifdef __NETWORK_EXTENSIONS__
+    open_port("telnet", TELNET_PORT);
+#endif
 }
 
 /*
@@ -143,12 +147,40 @@
 }
 
 /*
+ * NAME:	touch()
+ * DESCRIPTION: determine whether to preserve untouched status.
+ */
+static int touch(object obj, string function)
+{
+    return 0;
+}
+
+/*
  * NAME:	inherit_program()
  * DESCRIPTION:	get an object to inherit
  */
-static object inherit_program(string file, string path)
+static object inherit_program(string file, string path, int priv)
+{
+    object obj;
+
+    file = path_object(path);
+    obj = find_object(file);
+    if (obj == 0) {
+	obj = compile_object(file);
+    }
+    return obj;
+}
+
+/*
+ * NAME:	include_file()
+ * DESCRIPTION:	translate an include path
+ */
+static mixed include_file(string file, string path)
 {
-    return call_object(path);
+    if (path[0] != '/') {
+	return file + "/../" + path;
+    }
+    return path;
 }
 
 /*
@@ -183,7 +215,7 @@
  * NAME:	telnet_connect()
  * DESCRIPTION:	return a player object
  */
-static object telnet_connect()
+static object telnet_connect(int port)
 {
     object user, player;
 
@@ -204,7 +236,7 @@
  * NAME:	binary_connect()
  * DESCRIPTION:	return another player object (just to test)
  */
-static object binary_connect()
+static object binary_connect(int port)
 {
     object user, player;
 
@@ -225,7 +257,7 @@
  * NAME:	runtime_error()
  * DESCRIPTION:	log a runtime error
  */
-static void runtime_error(string error, int caught)
+static void runtime_error(string error, int caught, int ticks)
 {
     mixed **trace;
     string progname, objname, function, str;
@@ -249,6 +281,16 @@
     return user;
 }
 
+#ifdef __NETWORK_EXTENSIONS__
+/*
+ * NAME:	connection()
+ * DESCRIPTION:	return a user object.
+ */
+object connection(string ipnumber, int port) {
+    return telnet_connect(port);
+}
+#endif
+
 /*
  * NAME:	runtime_error()
  * DESCRIPTION:	log a runtime error
@@ -315,6 +357,15 @@
 }
 
 /*
+ * NAME:	atomic_error()
+ * DESCRIPTION:	deal with an atomic error
+ */
+static void atomic_error(string error, int atom, int ticks)
+{
+    send_message(error + "\n");
+}
+
+/*
  * NAME:	interrupt()
  * DESCRIPTION:	deal with a kill signal
  */
@@ -377,3 +428,12 @@
 {
     return 0;	/* No. */
 }
+
+/*
+ * NAME:	object_type()
+ * DESCRIPTION:	translate the object path used in a type declaration
+ */
+static string object_type(string file, string type)
+{
+    return type;
+}
