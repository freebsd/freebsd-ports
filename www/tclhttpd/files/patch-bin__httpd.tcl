--- bin/httpd.tcl	Wed Jun 14 13:25:50 2000
+++ bin/httpd.tcl	Wed Jun 21 15:59:34 2000
@@ -130,3 +130,3 @@
 } else {
-    set Config(config) [file join $Config(home) tclhttpd.rc]
+    set Config(config) [file join $Config(home) ../etc/tclhttpd.rc]
 }
