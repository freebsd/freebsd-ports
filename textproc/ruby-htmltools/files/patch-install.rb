--- install.rb.orig	Sun Apr 10 15:32:16 2005
+++ install.rb	Sun Apr 10 15:32:26 2005
@@ -10,6 +10,8 @@
 #   the GNU Lesser General Public License version 2.
 #
 
+
+
 ### begin compat.rb
 
 unless Enumerable.instance_methods(true).include? 'inject' then
@@ -32,6 +34,13 @@
 end
 
 ### end compat.rb
+
+class String 
+	def begin_with?( substr )
+		index( substr ) == 0
+	end
+end
+
 ### begin config.rb
 
 if i = ARGV.index(/\A--rbconfig=/) then
@@ -308,7 +317,7 @@
 module FileOperations
 
   def mkdir_p( dname, prefix = nil )
-    dname = prefix + dname if prefix
+    dname = File.join( prefix, dname ) if ( prefix and not dname.begin_with?( prefix ) )
     $stderr.puts "mkdir -p #{dname}" if verbose?
     return if no_harm?
 
@@ -371,7 +380,9 @@
     $stderr.puts "install #{from} #{dest}" if verbose?
     return if no_harm?
 
-    realdest = prefix + dest if prefix
+    realdest = ( prefix and not dest.begin_with?( prefix ) ) ? 
+    	prefix + dest :
+	dest
     if dir? realdest then
       realdest += '/' + File.basename(from)
     end
