--- lib/inc/internal/facts/freebsd/zpool_resolver.hpp.orig	2017-07-10 16:43:09 UTC
+++ lib/inc/internal/facts/freebsd/zpool_resolver.hpp
@@ -0,0 +1,24 @@
+/**
+ * @file
+ * Declares the FreeBSD ZFS storage pool (zpool) fact resolver.
+ */
+#pragma once
+
+#include "../resolvers/zpool_resolver.hpp"
+
+namespace facter { namespace facts { namespace freebsd {
+
+    /**
+     * Responsible for resolving ZFS storage pool (zpool) facts.
+     */
+    struct zpool_resolver : resolvers::zpool_resolver
+    {
+     protected:
+        /**
+         * Gets the platform's zpool command.
+         * @return Returns the platform's zpool command.
+         */
+        virtual std::string zpool_command();
+    };
+
+}}}  // namespace facter::facts::freebsd
