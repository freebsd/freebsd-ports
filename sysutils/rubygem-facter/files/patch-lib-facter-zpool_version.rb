--- lib/facter/zpool_version.rb.orig
+++ lib/facter/zpool_version.rb
@@ -4,7 +4,7 @@
   setcode do
     if Facter::Core::Execution.which('zpool')
       zpool_v = Facter::Core::Execution.exec('zpool upgrade -v')
-      zpool_version = zpool_v.match(/ZFS pool version (\d+)./).captures.first unless zpool_v.empty?
+      zpool_version = zpool_v.scan(/^\s+(\d+)\s+/m).flatten.last unless zpool_v.empty?
     end
   end
 end
