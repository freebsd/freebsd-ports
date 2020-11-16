Fix for https://dev.deluge-torrent.org/ticket/3337

--- deluge/core/preferencesmanager.py.orig	2020-11-16 07:47:52 UTC
+++ deluge/core/preferencesmanager.py
@@ -231,7 +231,7 @@ class PreferencesManager(component.Component):
         self.core.apply_session_settings(
             {
                 'listen_system_port_fallback': self.config['listen_use_sys_port'],
-                'listen_interfaces': ''.join(interfaces),
+                'listen_interfaces': ','.join(interfaces),
             }
         )
 
