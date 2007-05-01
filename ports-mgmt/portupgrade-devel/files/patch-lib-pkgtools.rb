--- lib/pkgtools.rb.orig	Tue May  1 11:12:02 2007
+++ lib/pkgtools.rb	Tue May  1 11:12:16 2007
@@ -646,6 +646,9 @@
 
 # raises StandardError
 def modify_pkgdep(pkgname, dep, newdep, neworigin = nil)
+  pkgdir = $pkgdb.pkgdir(pkgname)
+  return if pkgdir.nil? || !File.directory?(pkgdir)
+
   pkgver_re = %r{-\d\S*$}
   file = $pkgdb.pkg_contents(pkgname)
 
