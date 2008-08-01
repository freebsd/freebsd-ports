--- install.rb.orig	2008-07-24 08:03:04.000000000 +0900
+++ install.rb	2008-08-01 18:48:33.000000000 +0900
@@ -98,11 +98,12 @@
 end
 
 def do_man(man, strip = 'man/')
+  return
   man.each do |mf|
     omf = File.join(InstallOptions.man_dir, mf.gsub(/#{strip}/, ''))
     om = File.dirname(omf)
     File.makedirs(om, true)
-    File.chmod(0644, om)
+    File.chmod(0755, om)
     File.install(mf, omf, 0644, true)
     gzip = %x{which gzip}
     gzip.chomp!
@@ -223,7 +224,7 @@
   else
     bindir = Config::CONFIG['bindir']
     sbindir = Config::CONFIG['sbindir']
-    mandir = Config::CONFIG['mandir']
+    mandir = ENV['PREFIX'] + "/man"
     tmpdirs << Config::CONFIG['bindir']
   end
 
