--- tests/test_config.py.orig	2018-04-17 19:03:23 UTC
+++ tests/test_config.py
@@ -126,6 +126,7 @@ def test_get_config_file_path():
     fn = config.get_config_file_path

     os.unsetenv('XDG_CONFIG_HOME')
+    os.environ.pop('XDG_CONFIG_HOME', None)

     assert fn() == os.path.expanduser('~/.config/toot/config.json')

