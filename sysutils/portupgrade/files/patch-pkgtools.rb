--- lib/pkgtools.rb.orig	Tue Apr 22 14:35:20 2003
+++ lib/pkgtools.rb	Tue Apr 22 17:57:25 2003
@@ -604,8 +604,9 @@
     neworigin ||= $pkgdb.origin(newdep)
   end
 
+  lines = []
+
   File.open(file) do |f|
-    lines = []
     pkgdeps = Set.new
 
     deporigin = nil	# what to do with the next DEPORIGIN
