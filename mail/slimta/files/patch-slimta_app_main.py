--- slimta/app/main.py.orig	2021-05-11 11:45:15 UTC
+++ slimta/app/main.py
@@ -52,7 +52,7 @@ def parse_args():
     group.add_argument('-c', '--config', metavar='FILE', default=None,
                        help='Specifies a configuration file to read. If not '
                        'given, the default locations '
-                       '($HOME/.slimta/slimta.yaml, /etc/slimta/slimta.yaml) '
+                       '($HOME/.slimta/slimta.yaml, %%PREFIX%%/etc/slimta/slimta.yaml) '
                        'are checked.')
     group.add_argument('-n', '--process-name', metavar='NAME',
                        default=default_process_name,
