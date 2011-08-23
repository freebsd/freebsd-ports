diff --git a/lib/pkgdb.rb b/lib/pkgdb.rb
index 819309b..23e4203 100644
--- lib/pkgdb.rb
+++ lib/pkgdb.rb
@@ -431,7 +431,7 @@ class PkgDB
 	@db.select { |path, pkgs|
 	  path[0] == ?/ && pkgs.split.find { |pkg| deleted_pkgs.qinclude?(pkg) }
 	}.each do |path, pkgs|
-	  path = File.realpath(path)
+	  path = File.expand_path(path)
 
 	  pkgs = pkgs.split - deleted_pkgs
 
@@ -466,7 +466,7 @@ class PkgDB
 	  end
 
 	  pkginfo.files.each do |path|
-	    path = File.realpath(path)
+	    path = File.expand_path(path)
 
 	    if @db.key?(path)
 	      pkgs = @db[path].split
@@ -558,7 +558,7 @@ class PkgDB
   end
 
   def which(path, m = false)
-    path = File.realpath(path)
+    path = File.expand_path(path)
 
     open_db
 
