--- mod_throttle.c.orig	Mon Oct 28 00:50:56 2002
+++ mod_throttle.c	Mon Oct 28 00:51:06 2002
@@ -41,6 +41,10 @@
  * for a FreeBSD machine for testing and several suggestions.
  */
 
+#ifdef INET6
+#error mod_throttle is not IPv6-aware.
+#endif
+
 /***********************************************************************
  *** Pick one that best suits your system.
  ***********************************************************************/
--- mod_throttle.c.orig Mon May 10 15:59:10 2004
+++ mod_throttle.c      Mon May 10 16:00:45 2004
@@ -215,8 +215,8 @@
 static const char dtype[] = "Directory";
 static const char text_html[] = "text/html";
 static const char text_plain[] = "text/plain";
-static const char file_lock[] = "logs/mod_throttle.lock";
-static const char file_runtime[] = "logs/mod_throttle.runtime";
+static const char file_lock[] = "/var/run/mod_throttle/mod_throttle.lock";
+static const char file_runtime[] = "/var/run/mod_throttle/mod_throttle.runtime";

 static const char x_is_subrequest[] = "x-is-subrequest";
 static const char request_handler[] = "request-handler";

