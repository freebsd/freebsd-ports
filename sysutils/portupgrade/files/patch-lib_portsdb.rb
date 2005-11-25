Index: lib/portsdb.rb
===================================================================
--- lib/portsdb.rb	(.../vendor/portupgrade/trunk/lib/portsdb.rb)	(revision 2)
+++ lib/portsdb.rb	(.../branches/ports/lib/portsdb.rb)	(revision 41)
@@ -194,8 +194,8 @@
   def db_dir=(new_db_dir)
     @db_dir = new_db_dir || ENV['PORTS_DBDIR'] || ports_dir
 
-    @db_file = File.join(@db_dir, 'INDEX.db')
-    @db_filebase = @db_file.sub(/\.db$/, '')
+    @db_filebase = File.join(@db_dir, File.basename(index_file()))
+    @db_file = @db_filebase + '.db'
 
     close_db
 
@@ -846,7 +846,7 @@
 
   def all_depends_list(origin, before_args = nil, after_args = nil)
     if !before_args && !after_args && i = port(origin)
-      i.all_depends.map { |n| origin(n) }
+      i.all_depends.map { |n| origin(n) }.compact
     else
       all_depends_list!(origin, before_args, after_args)
     end
