Index: lib/pkgtools.rb
===================================================================
RCS file: /home/cvs/pkgtools/lib/pkgtools.rb,v
retrieving revision 1.100
diff -u -1 -r1.100 pkgtools.rb
--- lib/pkgtools.rb	19 Nov 2002 04:53:50 -0000	1.100
+++ lib/pkgtools.rb	20 Nov 2002 06:01:28 -0000
@@ -649,4 +649,4 @@
 
-  filter_file(shelljoin('sed', '-E',
-			"s|^(@comment[[:space:]]+ORIGIN:).*$|\\1#{origin}|"),
+  filter_file(shelljoin('sed',
+			"s|^\\(@comment[ \t][ \t]*ORIGIN:\\).*$|\\1#{origin}|"),
 	      contents_file)
