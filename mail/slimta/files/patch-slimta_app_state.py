--- slimta/app/state.py.orig	2021-01-11 18:40:47 UTC
+++ slimta/app/state.py
@@ -48,7 +48,7 @@ except ImportError as exc:
 class SlimtaState(object):
 
     _global_config_files = [os.path.expanduser('~/.slimta/slimta.yaml'),
-                            '/etc/slimta/slimta.yaml']
+                            '%%PREFIX%%/etc/slimta/slimta.yaml']
 
     def __init__(self, args):
         self.program = args.process_name
