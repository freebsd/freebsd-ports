Index: lib/portsdb.rb
===================================================================
RCS file: /home/cvs/pkgtools/lib/portsdb.rb,v
retrieving revision 1.80
diff -u -2 -r1.80 portsdb.rb
--- lib/portsdb.rb	30 Jun 2004 16:22:35 -0000	1.80
+++ lib/portsdb.rb	12 Jul 2004 16:08:12 -0000
@@ -550,5 +550,5 @@
       open_db_for_rebuild!
 
-      File.open(index_file) do |f|
+      open("| sort #{shelljoin(index_file)}") do |f|
 	f.each_with_index do |line, i|
 	  lineno = i + 1
