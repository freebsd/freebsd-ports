--- lib/httpserver.rb.orig	Fri Oct 25 02:28:40 2002
+++ lib/httpserver.rb	Mon Jan 27 21:35:27 2003
@@ -39,7 +39,7 @@
   StatusCodeMapping = {
     200 => "OK",
     400 => "Bad Request",
-    403 => "Forbidden"
+    403 => "Forbidden",
     405 => "Method Not Allowed",
     411 => "Length Required",
     500 => "Internal Server Error"
