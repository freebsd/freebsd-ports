--- src/mailman/rest/tests/test_systemconf.py.orig      2021-12-07 01:47:54 UTC
+++ src/mailman/rest/tests/test_systemconf.py
@@ -48,7 +48,7 @@ class TestSystemConfiguration(unittest.TestCase):
             filter_report='no',
             filtered_messages_are_preservable='no',
             hold_digest='no',
-            html_to_plain_text_command='/usr/bin/lynx -dump $filename',
+            html_to_plain_text_command='/usr/local/bin/lynx -dump $filename',
             layout='testing',
             listname_chars='[-_.0-9a-z]',
             masthead_threshold='4',
