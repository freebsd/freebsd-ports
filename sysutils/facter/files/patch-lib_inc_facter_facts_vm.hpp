--- lib/inc/facter/facts/vm.hpp.orig	2017-06-27 17:42:22 UTC
+++ lib/inc/facter/facts/vm.hpp
@@ -137,6 +137,11 @@ namespace facter { namespace facts {
          * The name for Solaris ldom
          */
         constexpr static char const* ldom = "ldom";
+
+        /**
+         * The name of FreeBSD jails
+         */
+        constexpr static char const* jail = "jail";
     };
 
 }}  // namespace facter::facts
