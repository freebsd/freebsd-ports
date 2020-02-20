See https://github.com/iocage/iocage/commit/b47dc2c47ff125d644720b03f598a9caf4e08192
--- iocage_lib/ioc_fetch.py.orig	2019-09-26 07:23:24 UTC
+++ iocage_lib/ioc_fetch.py
@@ -964,19 +964,16 @@ class IOCFetch(iocage_lib.ioc_json.IOCZF
 
                     if not cli:
                         for jail, path in jails.items():
-                            _json = iocage_lib.ioc_json.IOCJson(path)
+                            _json = iocage_lib.ioc_json.IOCJson(path, cli=False)
                             props = _json.json_get_value('all')
 
                             if props['basejail'] and self.release.rsplit(
                                 '-', 1
                             )[0] in props['release']:
-                                props['release'] = new_release
-                                _json.json_write(props)
+                                _json.json_set_value(f'release={new_release}')
                     else:
-                        _json = iocage_lib.ioc_json.IOCJson(jails[uuid])
-                        props = _json.json_get_value('all')
-                        props['release'] = new_release
-                        _json.json_write(props)
+                        _json = iocage_lib.ioc_json.IOCJson(jails[uuid], cli=False)
+                        _json.json_set_value(f'release={new_release}')
 
             if self.verify:
                 # tmp only exists if they verify SSL certs
