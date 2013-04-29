--- lib/puppet/provider/service/freebsd.rb.orig	2013-04-28 02:55:36.017584743 +0000
+++ lib/puppet/provider/service/freebsd.rb	2013-04-28 02:55:52.581583782 +0000
@@ -41,7 +41,7 @@
   def rcvar_name
     name = self.rcvar[1]
     self.error("No rcvar name found in rcvar") if name.nil?
-    name = name.gsub!(/(.*)(_enable)?=(.*)/, '\1')
+    name = name.gsub!(/(.*?)(_enable)?=(.*)/, '\1')
     self.error("rcvar name is empty") if name.nil?
     self.debug("rcvar name is #{name}")
     name
