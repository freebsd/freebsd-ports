--- src/deliver.c.orig	2019-03-11 16:20:17 UTC
+++ src/deliver.c
@@ -763,7 +763,7 @@ if (LOGGING(incoming_interface) && LOGGING(outgoing_in
   {
   g = string_fmt_append(g, " I=[%s]", sending_ip_address);
   if (LOGGING(outgoing_port))
-    g = string_fmt_append(g, "%d", sending_port);
+    g = string_fmt_append(g, ":%d", sending_port);
   }
 return g;
 }
