--- mikutter.rb.orig	2012-10-23 09:12:05.000000000 +0900
+++ mikutter.rb	2012-12-02 09:51:43.000000000 +0900
@@ -12,11 +12,7 @@
 
 =end
 
-if File.symlink?($0)
-  Dir.chdir(File.join(File.dirname(File.readlink($0)), 'core'))
-else
-  Dir.chdir(File.join(File.dirname($0), 'core'))
-end
+Dir.chdir('%%RUBY_SITELIBDIR%%/mikutter/core')
 
 Thread.abort_on_exception = true
 ENV['LIBOVERLAY_SCROLLBAR'] = '0'
