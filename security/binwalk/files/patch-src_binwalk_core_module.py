--- src/binwalk/core/module.py.orig	2021-09-10 19:46:40.000000000 +0200
+++ src/binwalk/core/module.py	2026-08-02 21:33:59.983754000 +0200
@@ -704,18 +704,32 @@
                 modules[module] = module.PRIORITY
 
         # user-defined modules
-        import imp
+        import importlib.util
+        import sys
+        
         user_modules = binwalk.core.settings.Settings().user.modules
         for file_name in os.listdir(user_modules):
             if not file_name.endswith('.py'):
                 continue
             module_name = file_name[:-3]
             try:
-                user_module = imp.load_source(module_name, os.path.join(user_modules, file_name))
+                # Creates module specification from file path
+                file_path = os.path.join(user_modules, file_name)
+                spec = importlib.util.spec_from_file_location(module_name, file_path)
+                
+                # Loads the module into memory using the created specification
+                if spec and spec.loader:
+                    user_module = importlib.util.module_from_spec(spec)
+                    sys.modules[module_name] = user_module
+                    spec.loader.exec_module(user_module)
+                else:
+                    raise ImportError(f"Não foi possível criar a especificação para {file_name}")
+                    
             except KeyboardInterrupt as e:
                 raise e
             except Exception as e:
                 binwalk.core.common.warning("Error loading module '%s': %s" % (file_name, str(e)))
+                continue  # Jumps to the next file if it fails
 
             for (name, module) in inspect.getmembers(user_module):
                 if inspect.isclass(module) and hasattr(module, attribute):
@@ -723,6 +737,7 @@
 
         return sorted(modules, key=modules.get, reverse=True)
 
+
     def help(self):
         '''
         Generates formatted help output.
