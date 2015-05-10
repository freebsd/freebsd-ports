--- include/osquery/registry.h.orig	2015-05-05 00:16:41 UTC
+++ include/osquery/registry.h
@@ -41,11 +41,11 @@ namespace osquery {
  * @param type A typename that derives from Plugin.
  * @param name A string identifier for the registry.
  */
-#define CREATE_REGISTRY(type, name)              \
-  namespace registry {                           \
-  __constructor__ static void type##Registry() { \
-    Registry::create<type>(name);                \
-  }                                              \
+#define CREATE_REGISTRY(type, name)                       \
+  namespace registry {                                    \
+  __registry_constructor__ static void type##Registry() { \
+    Registry::create<type>(name);                         \
+  }                                                       \
   }
 
 /**
@@ -56,11 +56,11 @@ namespace osquery {
  * @param type A typename that derives from Plugin.
  * @param name A string identifier for the registry.
  */
-#define CREATE_LAZY_REGISTRY(type, name)         \
-  namespace registry {                           \
-  __constructor__ static void type##Registry() { \
-    Registry::create<type>(name, true);          \
-  }                                              \
+#define CREATE_LAZY_REGISTRY(type, name)                  \
+  namespace registry {                                    \
+  __registry_constructor__ static void type##Registry() { \
+    Registry::create<type>(name, true);                   \
+  }                                                       \
   }
 
 /**
@@ -75,15 +75,15 @@ namespace osquery {
  * @param registry The string name for the registry.
  * @param name A string identifier for this registry item.
  */
-#define REGISTER(type, registry, name)               \
-  __constructor__ static void type##RegistryItem() { \
-    Registry::add<type>(registry, name);             \
+#define REGISTER(type, registry, name)                      \
+  __plugin_constructor__ static void type##RegistryItem() { \
+    Registry::add<type>(registry, name);                    \
   }
 
 /// The same as REGISTER but prevents the plugin item from being broadcasted.
-#define REGISTER_INTERNAL(type, registry, name)      \
-  __constructor__ static void type##RegistryItem() { \
-    Registry::add<type>(registry, name, true);       \
+#define REGISTER_INTERNAL(type, registry, name)             \
+  __plugin_constructor__ static void type##RegistryItem() { \
+    Registry::add<type>(registry, name, true);              \
   }
 
 /**
