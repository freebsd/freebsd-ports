--- lib/inc/internal/facts/freebsd/operating_system_resolver.hpp.orig	2017-07-28 07:09:48 UTC
+++ lib/inc/internal/facts/freebsd/operating_system_resolver.hpp
@@ -0,0 +1,24 @@
+/**
+ * @file
+ * Declares the FreeBSD operating system fact resolver.
+ */
+#pragma once
+
+#include "../posix/operating_system_resolver.hpp"
+
+namespace facter { namespace facts { namespace freebsd {
+
+    /**
+     * Responsible for resolving operating system facts.
+     */
+    struct operating_system_resolver : posix::operating_system_resolver
+    {
+    protected:
+        /**
+         * Collects the resolver's release data.
+         * @param facts The fact collection that is resolving facts.
+         * @param result The current resolver data.
+         */
+        virtual void collect_release_data(collection& facts, data& result) override;
+    };
+}}}  // namespace facter::facts::freebsd
