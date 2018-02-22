--- lib/src/facts/freebsd/virtualization_resolver.cc.orig	2018-02-13 01:46:04 UTC
+++ lib/src/facts/freebsd/virtualization_resolver.cc
@@ -20,10 +20,7 @@ namespace facter { namespace facts { nam
         string value = get_jail_vm();
 
         if (value.empty()) {
-            auto product_name = facts.get<string_value>(fact::product_name);
-            if (product_name) {
-                value = get_product_name_vm(product_name->value());
-            }
+            value = get_fact_vm(facts);
         }
 
         return value;
