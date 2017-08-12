--- lib/inc/internal/facts/freebsd/memory_resolver.hpp.orig	2017-07-10 14:30:58 UTC
+++ lib/inc/internal/facts/freebsd/memory_resolver.hpp
@@ -0,0 +1,25 @@
+/**
+ * @file
+ * Declares the FreeBSD memory fact resolver.
+ */
+#pragma once
+
+#include "../resolvers/memory_resolver.hpp"
+
+namespace facter { namespace facts { namespace freebsd {
+
+    /**
+     * Responsible for resolving memory facts.
+     */
+    struct memory_resolver : resolvers::memory_resolver
+    {
+     protected:
+        /**
+         * Collects the resolver data.
+         * @param facts The fact collection that is resolving facts.
+         * @return Returns the resolver data.
+         */
+        virtual data collect_data(collection& facts) override;
+    };
+
+}}}  // namespace facter::facts::osx
