Index: lib/portinfo.rb
===================================================================
RCS file: /home/cvs/pkgtools/lib/portinfo.rb,v
retrieving revision 1.16
diff -u -r1.16 portinfo.rb
--- lib/portinfo.rb	8 Nov 2002 17:18:27 -0000	1.16
+++ lib/portinfo.rb	21 Jun 2004 17:36:11 -0000
@@ -17,9 +17,9 @@
     line.is_a?(String) or raise ArgumentError,
       "You must specify a one line text of port info."
 
-    values = line.chomp.split(FIELD_SEPARATOR, NFIELDS)
+    values = line.chomp.split(FIELD_SEPARATOR)
 
-    if values.size != NFIELDS || values[NFIELDS - 1].index(FIELD_SEPARATOR)
+    if values.size < NFIELDS || values[NFIELDS - 1].index(FIELD_SEPARATOR)
       raise ArgumentError, "Port info line must consist of #{NFIELDS} fields."
     end
 
