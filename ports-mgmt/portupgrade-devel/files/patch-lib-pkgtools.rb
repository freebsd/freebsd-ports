--- lib/pkgtools.rb.orig	Sat Jun  3 10:05:09 2006
+++ lib/pkgtools.rb	Mon Jun 19 16:36:55 2006
@@ -1048,7 +1048,7 @@
 
     pkg = PkgInfo.new(pkgname)
 
-    re = %r"^((?:#{Regexp.quote(localbase())}|#{Regexp.quote(x11base())})/etc/rc\.d/[^/]+(\.sh))(\.\w+)?$"
+    re = %r"^((?:#{Regexp.quote(localbase())}|#{Regexp.quote(x11base())})/etc/rc\.d/[^/]+(\.sh)?)(\.\w+)?$"
 
     ret = []
     pkg.files.each { |file|
@@ -1066,7 +1066,7 @@
 
     pkg = PkgInfo.new(pkgname)
 
-    re = %r"^((?:#{Regexp.quote(localbase())}|#{Regexp.quote(x11base())})/etc/rc\.d/[^/]+\.sh)(\.\w+)$"
+    re = %r"^((?:#{Regexp.quote(localbase())}|#{Regexp.quote(x11base())})/etc/rc\.d/[^/]+(\.sh)?)(\.\w+)$"
 
     pkg.files.select { |file|
       re =~ file && File.executable?(file)
