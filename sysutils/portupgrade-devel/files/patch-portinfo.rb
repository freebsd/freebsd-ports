--- lib/portinfo.rb.orig	Sat Nov  9 02:18:27 2002
+++ lib/portinfo.rb	Tue Jun 22 13:07:48 2004
@@ -17,11 +17,9 @@
     line.is_a?(String) or raise ArgumentError,
       "You must specify a one line text of port info."
 
-    values = line.chomp.split(FIELD_SEPARATOR, NFIELDS)
+    values = line.chomp.split(FIELD_SEPARATOR)
 
-    if values.size != NFIELDS || values[NFIELDS - 1].index(FIELD_SEPARATOR)
-      raise ArgumentError, "Port info line must consist of #{NFIELDS} fields."
-    end
+    values.push("") while values.size < NFIELDS
 
     @attr = {}
 
