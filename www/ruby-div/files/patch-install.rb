--- install.rb~	Wed Dec 26 19:45:56 2001
+++ install.rb	Sat Dec  4 17:52:09 2004
@@ -13,3 +13,3 @@
   $site_libdir = File.join($libdir, "site_ruby")
-elsif $site_libdir !~ Regexp.quote($version)
+elsif $site_libdir !~ /#{Regexp.quote($version)}/
   $site_libdir = File.join($site_libdir, $version)
