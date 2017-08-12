--- lib/src/facts/resolvers/operating_system_resolver.cc.orig	2017-07-18 18:49:09 UTC
+++ lib/src/facts/resolvers/operating_system_resolver.cc
@@ -231,18 +231,27 @@ namespace facter { namespace facts { nam
     {
         data result;
 
+        collect_kernel_data(facts, result);
+        collect_release_data(facts, result);
+
+        return result;
+    }
+
+    void operating_system_resolver::collect_kernel_data(collection& facts, data& result)
+    {
         auto kernel = facts.get<string_value>(fact::kernel);
         if (kernel) {
             result.name = kernel->value();
             result.family = kernel->value();
         }
+    }
 
+    void operating_system_resolver::collect_release_data(collection& facts, data& result)
+    {
         auto release = facts.get<string_value>(fact::kernel_release);
         if (release) {
             result.release = release->value();
         }
-
-        return result;
     }
 
     tuple<string, string> operating_system_resolver::parse_distro(string const& name, string const& release)
