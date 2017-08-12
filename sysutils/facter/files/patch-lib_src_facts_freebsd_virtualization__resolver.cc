--- lib/src/facts/freebsd/virtualization_resolver.cc.orig	2017-07-10 14:30:58 UTC
+++ lib/src/facts/freebsd/virtualization_resolver.cc
@@ -0,0 +1,44 @@
+#include <internal/facts/freebsd/virtualization_resolver.hpp>
+#include <facter/facts/scalar_value.hpp>
+#include <facter/facts/collection.hpp>
+#include <facter/facts/fact.hpp>
+#include <facter/facts/vm.hpp>
+#include <leatherman/execution/execution.hpp>
+#include <boost/algorithm/string.hpp>
+
+#include <sys/types.h>
+#include <sys/sysctl.h>
+
+using namespace std;
+using namespace facter::facts;
+using namespace leatherman::execution;
+
+namespace facter { namespace facts { namespace freebsd {
+
+    string virtualization_resolver::get_hypervisor(collection& facts)
+    {
+        string value = get_jail_vm();
+
+        if (value.empty()) {
+            auto product_name = facts.get<string_value>(fact::product_name);
+            if (product_name) {
+                value = get_product_name_vm(product_name->value());
+            }
+        }
+
+        return value;
+    }
+
+    string virtualization_resolver::get_jail_vm()
+    {
+        int jailed;
+        size_t size = sizeof(jailed);
+        if (sysctlbyname("security.jail.jailed", &jailed, &size, NULL, 0) == 0) {
+            if (jailed)
+                return vm::jail;
+        }
+
+        return {};
+    }
+
+} } }  // namespace facter::facts::freebsd
