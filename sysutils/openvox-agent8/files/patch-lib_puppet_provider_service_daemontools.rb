--- lib/puppet/provider/service/daemontools.rb.orig	2024-02-22 01:02:28 UTC
+++ lib/puppet/provider/service/daemontools.rb
@@ -41,7 +41,7 @@ Puppet::Type.type(:service).provide :daemontools, :par
 
   EOT
 
-  commands :svc => "/usr/bin/svc", :svstat => "/usr/bin/svstat"
+  commands :svc => "%%PREFIX%%/bin/svc", :svstat => "%%PREFIX%%/bin/svstat"
 
   class << self
     attr_writer :defpath
@@ -88,7 +88,7 @@ Puppet::Type.type(:service).provide :daemontools, :par
   # find the service dir on this node
   def servicedir
     unless @servicedir
-      ["/service", "/etc/service", "/var/lib/svscan"].each do |path|
+      ["/var/service", "/etc/service", "/var/lib/svscan"].each do |path|
         if Puppet::FileSystem.exist?(path)
           @servicedir = path
           break
