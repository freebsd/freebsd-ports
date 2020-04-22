Vendor fix for https://dev.deluge-torrent.org/ticket/3298

===================================================================
--- deluge/core/torrentmanager.py	(revision 8b62e50eb8bf81a177c4d62484a44b766c6f54a6)
+++ deluge/core/torrentmanager.py	(revision 23b3f144fce3424ae874d54a659cb7b8dd624ade)
@@ -26,5 +26,5 @@
 import deluge.component as component
 from deluge._libtorrent import lt
-from deluge.common import archive_files, decode_bytes, get_magnet_info, is_magnet
+from deluge.common import PY2, archive_files, decode_bytes, get_magnet_info, is_magnet
 from deluge.configmanager import ConfigManager, get_config_dir
 from deluge.core.authmanager import AUTH_LEVEL_ADMIN
@@ -810,5 +810,8 @@
             try:
                 with open(filepath, 'rb') as _file:
-                    state = pickle.load(_file)
+                    if PY2:
+                        state = pickle.load(_file)
+                    else:
+                        state = pickle.load(_file, encoding='utf8')
             except (IOError, EOFError, pickle.UnpicklingError) as ex:
                 message = 'Unable to load {}: {}'.format(filepath, ex)
