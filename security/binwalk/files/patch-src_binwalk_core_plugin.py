--- src/binwalk/core/plugin.py.orig	2021-09-10 19:46:40.000000000 +0200
+++ src/binwalk/core/plugin.py	2026-08-02 21:33:59.984158000 +0200
@@ -1,7 +1,7 @@
 # Core code for supporting and managing plugins.
 
 import os
-import imp
+import importlib
 import inspect
 import binwalk.core.common
 import binwalk.core.settings
@@ -168,6 +168,9 @@
             }
         }
 
+        import importlib.util
+        import sys
+
         for key in plugins.keys():
             if key == 'user':
                 plugins[key]['path'] = self.settings.user.plugins
@@ -180,7 +183,18 @@
                         module = file_name[:-len(self.MODULE_EXTENSION)]
 
                         try:
-                            plugin = imp.load_source(module, os.path.join(plugins[key]['path'], file_name))
+                            # Define full module path
+                            file_path = os.path.join(plugins[key]['path'], file_name)
+                            spec = importlib.util.spec_from_file_location(module, file_path)
+                            
+                            # Loads the plugin dynamically if the specification is valid
+                            if spec and spec.loader:
+                                plugin = importlib.util.module_from_spec(spec)
+                                sys.modules[module] = plugin
+                                spec.loader.exec_module(plugin)
+                            else:
+                                raise ImportError(f"Não foi possível criar a especificação para {file_name}")
+
                             plugin_class = self._find_plugin_class(plugin)
 
                             plugins[key]['enabled'][module] = True
@@ -196,6 +210,7 @@
                         except Exception as e:
                             binwalk.core.common.warning("Error loading plugin '%s': %s" % (file_name, str(e)))
                             plugins[key]['enabled'][module] = False
+                            continue  # Skips reading description if plugin failed to load
 
                         try:
                             plugins[key]['descriptions'][
@@ -207,12 +222,16 @@
                                 module] = 'No description'
         return plugins
 
+
     def load_plugins(self):
         plugins = self.list_plugins()
         self._load_plugin_modules(plugins['user'])
         self._load_plugin_modules(plugins['system'])
 
     def _load_plugin_modules(self, plugins):
+        import importlib.util
+        import sys
+
         for module in plugins['modules']:
             try:
                 file_path = os.path.join(plugins['path'], module + self.MODULE_EXTENSION)
@@ -222,7 +241,15 @@
                 continue
 
             try:
-                plugin = imp.load_source(module, file_path)
+                # Creates the specification and loads the module dynamically
+                spec = importlib.util.spec_from_file_location(module, file_path)
+                if spec and spec.loader:
+                    plugin = importlib.util.module_from_spec(spec)
+                    sys.modules[module] = plugin
+                    spec.loader.exec_module(plugin)
+                else:
+                    raise ImportError(f"Não foi possível criar a especificação para {file_path}")
+
                 plugin_class = self._find_plugin_class(plugin)
 
                 class_instance = plugin_class(self.parent)
