--- mod_watch.c.orig	Thu Mar 14 03:44:07 2002
+++ mod_watch.c	Wed Oct 15 22:37:21 2003
@@ -41,6 +41,10 @@
  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  */
 
+#ifdef INET6
+#error mod_watch is not IPv6-aware.
+#endif
+
 #ifndef SPOOLDIR
 #define SPOOLDIR		"/var/spool/mod_watch/"
 #endif
@@ -1037,22 +1041,22 @@
 	if (shLock(shtable) && MutexLock(mutex))
 		goto error0;
 
-	ap_rprintf(r, "
-<html>
-<style type='text/css'>
-th {
-	font-family: Verdana, Arial, Helvetica, sans-serif;
-	font-size: 10pt;
-	background-color: #0080D7;
-	color: #ffffff;
-}
-.normal, p, ul, td {
-	font-family: Verdana, Arial, Helvetica, sans-serif;
-	font-size: 10pt;
-	color: #000000;
-}
-</style>
-<body>
+	ap_rprintf(r, "\n\
+<html>\n\
+<style type='text/css'>\n\
+th {\n\
+	font-family: Verdana, Arial, Helvetica, sans-serif;\n\
+	font-size: 10pt;\n\
+	background-color: #0080D7;\n\
+	color: #ffffff;\n\
+}\n\
+.normal, p, ul, td {\n\
+	font-family: Verdana, Arial, Helvetica, sans-serif;\n\
+	font-size: 10pt;\n\
+	color: #000000;\n\
+}\n\
+</style>\n\
+<body>\n\
 "
 );
 
