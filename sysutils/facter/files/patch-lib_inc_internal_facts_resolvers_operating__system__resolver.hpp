--- lib/inc/internal/facts/resolvers/operating_system_resolver.hpp.orig	2017-07-18 18:49:09 UTC
+++ lib/inc/internal/facts/resolvers/operating_system_resolver.hpp
@@ -216,6 +216,20 @@ namespace facter { namespace facts { nam
          * @return Returns the resolver data.
          */
         virtual data collect_data(collection& facts);
+
+        /**
+         * Collects the resolver's kernel data.
+         * @param facts The fact collection that is resolving facts.
+         * @param result The current resolver data.
+         */
+        virtual void collect_kernel_data(collection& facts, data &result);
+
+        /**
+         * Collects the resolver's release data.
+         * @param facts The fact collection that is resolving facts.
+         * @param result The current resolver data.
+         */
+        virtual void collect_release_data(collection& facts, data &result);
     };
 
 }}}  // namespace facter::facts::resolvers
