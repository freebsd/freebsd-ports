--- lib/facter/zpool_version.rb.orig
+++ lib/facter/zpool_version.rb
@@ -4,7 +4,7 @@
   setcode do
     if Facter::Util::Resolution.which('zpool')
       zpool_v = Facter::Util::Resolution.exec('zpool upgrade -v')
-      zpool_version = zpool_v.match(/ZFS pool version (\d+)./).captures.first unless zpool_v.nil?
+      zpool_version = zpool_v.scan(/^\s+(\d+)\s+/m).flatten.last unless zpool_v.nil?
     end
   end
 end
