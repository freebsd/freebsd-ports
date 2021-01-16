--- slimta/app/main.py.orig	2021-01-11 18:43:19 UTC
+++ slimta/app/main.py
@@ -44,7 +44,7 @@ def parse_args():
     default_process_name = os.path.basename(sys.argv[0])
     group = argparser.add_argument_group('config options')
     group.add_argument('-c', '--config', metavar='FILE', default=None,
-                       help='Specifies a configuration file to read. If not given, the default locations ($HOME/.slimta/slimta.yaml, /etc/slimta/slimta.yaml) are checked.')
+                       help='Specifies a configuration file to read. If not given, the default locations ($HOME/.slimta/slimta.yaml, %%PREFIX%%/etc/slimta/slimta.yaml) are checked.')
     group.add_argument('-n', '--process-name', metavar='NAME', default=default_process_name,
                        help='Use the process sub-section NAME for configuration. (default: %(default)s)')
     group.add_argument('--no-edge', action='store_true',
