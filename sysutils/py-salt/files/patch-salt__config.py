diff --git a/salt/config.py b/salt/config.py
index 071e06b..1f83c33 100644
--- salt/config.py.orig
+++ salt/config.py
@@ -63,7 +63,7 @@
 
 VALID_OPTS = {
     # The address of the salt master. May be specified as IP address or hostname
-    'master': str,
+    'master': (str, list),
 
     # The TCP/UDP port of the master to connect to in order to listen to publications
     'master_port': int,
@@ -541,7 +541,7 @@
     'file_recv': bool,
     'file_recv_max_size': int,
     'file_ignore_regex': list,
-    'file_ignore_glob': bool,
+    'file_ignore_glob': list,
     'fileserver_backend': list,
     'fileserver_followsymlinks': bool,
     'fileserver_ignoresymlinks': bool,
@@ -833,7 +833,7 @@
     'file_recv': False,
     'file_recv_max_size': 100,
     'file_ignore_regex': [],
-    'file_ignore_glob': None,
+    'file_ignore_glob': [],
     'fileserver_backend': ['roots'],
     'fileserver_followsymlinks': True,
     'fileserver_ignoresymlinks': False,
@@ -1348,26 +1348,30 @@ def _validate_opts(opts):
     Check that all of the types of values passed into the config are
     of the right types
     '''
+    def format_multi_opt(valid_type):
+        try:
+            num_types = len(valid_type)
+        except TypeError:
+            # Bare type name won't have a length, return the name of the type
+            # passed.
+            return valid_type.__name__
+        else:
+            if num_types == 1:
+                return valid_type.__name__
+            elif num_types > 1:
+                ret = ', '.join(x.__name__ for x in valid_type[:-1])
+                ret += ' or ' + valid_type[-1].__name__
+
     errors = []
-    err = ('Key {0} with value {1} has an invalid type of {2}, a {3} is '
+
+    err = ('Key \'{0}\' with value {1} has an invalid type of {2}, a {3} is '
            'required for this value')
     for key, val in six.iteritems(opts):
         if key in VALID_OPTS:
-            if isinstance(VALID_OPTS[key](), list):
-                if isinstance(val, VALID_OPTS[key]):
-                    continue
-                else:
-                    errors.append(
-                        err.format(key, val, type(val).__name__, 'list')
-                    )
-            if isinstance(VALID_OPTS[key](), dict):
-                if isinstance(val, VALID_OPTS[key]):
-                    continue
-                else:
-                    errors.append(
-                        err.format(key, val, type(val).__name__, 'dict')
-                    )
-            else:
+            if isinstance(val, VALID_OPTS[key]):
+                continue
+
+            if hasattr(VALID_OPTS[key], '__call__'):
                 try:
                     VALID_OPTS[key](val)
                     if isinstance(val, (list, dict)):
@@ -1384,14 +1388,21 @@ def _validate_opts(opts):
                                 VALID_OPTS[key].__name__
                             )
                         )
-                except ValueError:
+                except (TypeError, ValueError):
                     errors.append(
-                        err.format(key, val, type(val).__name__, VALID_OPTS[key])
-                    )
-                except TypeError:
-                    errors.append(
-                        err.format(key, val, type(val).__name__, VALID_OPTS[key])
+                        err.format(key,
+                                   val,
+                                   type(val).__name__,
+                                   VALID_OPTS[key].__name__)
                     )
+                continue
+
+            errors.append(
+                err.format(key,
+                           val,
+                           type(val).__name__,
+                           format_multi_opt(VALID_OPTS[key].__name__))
+            )
 
     # RAET on Windows uses 'win32file.CreateMailslot()' for IPC. Due to this,
     # sock_dirs must start with '\\.\mailslot\' and not contain any colons.
@@ -1404,7 +1415,7 @@ def _validate_opts(opts):
                 '\\\\.\\mailslot\\' + opts['sock_dir'].replace(':', ''))
 
     for error in errors:
-        log.warning(error)
+        log.debug(error)
     if errors:
         return False
     return True

