--- lib/src/util/config/posix/config.cc.orig
+++ lib/src/util/config/posix/config.cc
@@ -7,6 +7,6 @@
     }
 
     std::string default_config_location() {
-        return "/etc/puppetlabs/facter/facter.conf";
+        return "%%PREFIX%%/etc/facter/facter.conf";
     }
 }}}  // namespace facter::util::config
