--- install.rb~	Fri Jan 28 00:37:45 2005
+++ install.rb	Fri Jan 28 00:38:12 2005
@@ -41,7 +41,7 @@
     site_libdir = $:.find {|x| x =~ /site_ruby$/}
     if !site_libdir
       site_libdir = File.join(@libdir, "site_ruby")
-    elsif site_libdir !~ Regexp.quote(@version)
+    elsif site_libdir !~ /#{Regexp.quote(@version)}/
       site_libdir = File.join(site_libdir, @version)
     end
     site_libdir
