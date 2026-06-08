--- iocage_lib/ioc_common.py.orig	2025-12-12 22:04:57 UTC
+++ iocage_lib/ioc_common.py
@@ -1116,7 +1116,7 @@ def get_host_gateways():
             pass
         else:
             default_route = list(filter(
-                lambda x: x['destination'] == 'default', route_entries)
+                lambda x: x['destination'] in ['default', '0.0.0.0', '::/0'], route_entries)
             )
             if default_route and 'gateway' in default_route[0]:
                 gateways[af_mapping[af]]['gateway'] = \
