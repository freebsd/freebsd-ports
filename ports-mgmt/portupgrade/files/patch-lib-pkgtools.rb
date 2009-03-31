--- lib/pkgtools.rb.orig	2009-03-31 19:59:37.000000000 +0400
+++ lib/pkgtools.rb	2009-03-31 20:00:11.000000000 +0400
@@ -1165,7 +1165,7 @@
     STDERR.puts "uname(1) could be broken - cannot parse the output: #{uname}"
   end
 
-  def pkg_site_mirror(root = ENV['PACKAGEROOT'] || 'ftp://ftp.FreeBSD.org')
+  def pkg_site_mirror(root = ENV['PACKAGEROOT'] || 'ftp://ftp.FreeBSD.org/')
     sprintf('%s/pub/FreeBSD/ports/%s/packages-%s/',
 	    root, OS_PLATFORM, OS_PKGBRANCH)
   end
