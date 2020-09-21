--- src/mailman/rest/tests/test_systemconf.py.orig	2017-11-18 01:23:39 UTC
+++ src/mailman/rest/tests/test_systemconf.py
@@ -41,7 +41,7 @@ class TestSystemConfiguration(unittest.TestCase):
             default_language='en',
             email_commands_max_lines='10',
             filtered_messages_are_preservable='no',
-            html_to_plain_text_command='/usr/bin/lynx -dump $filename',
+            html_to_plain_text_command='/usr/local/bin/lynx -dump $filename',
             layout='testing',
             listname_chars='[-_.0-9a-z]',
             noreply_address='noreply',
