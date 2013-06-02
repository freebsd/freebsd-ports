--- setup.rb.orig	2013-05-28 15:52:34.000000000 -0600
+++ setup.rb	2013-05-28 15:54:12.000000000 -0600
@@ -1311,6 +1311,9 @@ class Installer
       File.open(path) {|f|
         line = f.gets
       }
+      if RUBY_VERSION >= "1.9"
+        line.force_encoding('ASCII-8BIT')
+      end
       return nil unless /\A#!/ =~ line
       parse(line)
     end
