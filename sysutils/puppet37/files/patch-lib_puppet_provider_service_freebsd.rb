--- lib/puppet/provider/service/freebsd.rb.orig	2015-05-30 18:06:50 UTC
+++ lib/puppet/provider/service/freebsd.rb
@@ -39,7 +39,7 @@ Puppet::Type.type(:service).provide :fre
 
   # Extract service name
   def service_name
-    extract_value_name('service', 0, /# (.*)/, '\1')
+    extract_value_name('service', 0, /# (\S+).*/, '\1')
   end
 
   # Extract rcvar name
