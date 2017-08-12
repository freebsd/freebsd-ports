--- lib/inc/internal/facts/freebsd/virtualization_resolver.hpp.orig	2017-07-10 14:30:58 UTC
+++ lib/inc/internal/facts/freebsd/virtualization_resolver.hpp
@@ -0,0 +1,27 @@
+/**
+ * @file
+ * Declares the FreeBSD virtualization fact resolver.
+ */
+#pragma once
+
+#include "../resolvers/virtualization_resolver.hpp"
+
+namespace facter { namespace facts { namespace freebsd {
+
+    /**
+     * Responsible for resolving virtualization facts.
+     */
+    struct virtualization_resolver : resolvers::virtualization_resolver
+    {
+     protected:
+        /**
+         * Gets the name of the hypervisor.
+         * @param facts The fact collection that is resolving facts.
+         * @return Returns the name of the hypervisor or empty string if no hypervisor.
+         */
+        virtual std::string get_hypervisor(collection& facts) override;
+     private:
+        static std::string get_jail_vm();
+    };
+
+}}}  // namespace facter::facts::freebsd
