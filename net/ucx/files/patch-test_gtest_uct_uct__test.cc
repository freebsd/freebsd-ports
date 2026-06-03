--- test/gtest/uct/uct_test.cc.orig	2026-02-04 09:52:47 UTC
+++ test/gtest/uct/uct_test.cc
@@ -12,6 +12,7 @@
 #include <ucs/sys/sock.h>
 #include <ucs/sys/string.h>
 #include <common/test_helpers.h>
+#include <ucs/type/cpu_set.h>
 #include <algorithm>
 #ifdef HAVE_MALLOC_H
 #include <malloc.h>
@@ -31,7 +32,7 @@ resource::resource() : component(NULL), dev_type(UCT_D
                        sys_device(UCS_SYS_DEVICE_ID_UNKNOWN),
                        variant(DEFAULT_VARIANT)
 {
-    CPU_ZERO(&local_cpus);
+    UCS_CPU_ZERO(&local_cpus);
 }
 
 resource::resource(uct_component_h component, const std::string& component_name,
@@ -385,7 +386,7 @@ void uct_test::set_cm_resources(std::vector<resource>&
 
         if (component_attr.flags & UCT_COMPONENT_FLAG_CM) {
             ucs_cpu_set_t local_cpus;
-            CPU_ZERO(&local_cpus);
+            UCS_CPU_ZERO(&local_cpus);
             uct_test::set_cm_sockaddr_resources(uct_components[cmpt_index],
                                                 component_attr.name, local_cpus,
                                                 all_resources);
