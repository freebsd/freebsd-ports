--- lib/inc/internal/facts/freebsd/zfs_resolver.hpp.orig	2017-07-10 16:43:09 UTC
+++ lib/inc/internal/facts/freebsd/zfs_resolver.hpp
@@ -0,0 +1,24 @@
+/**
+ * @file
+ * Declares the ZFS fact resolver.
+ */
+#pragma once
+
+#include "../resolvers/zfs_resolver.hpp"
+
+namespace facter { namespace facts { namespace freebsd {
+
+    /**
+     * Responsible for resolving ZFS facts.
+     */
+    struct zfs_resolver : resolvers::zfs_resolver
+    {
+     protected:
+        /**
+         * Gets the platform's ZFS command.
+         * @return Returns the platform's ZFS command.
+         */
+        virtual std::string zfs_command();
+    };
+
+}}}  // namespace facter::facts::freebsd
