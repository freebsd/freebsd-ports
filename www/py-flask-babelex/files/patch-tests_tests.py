# Failing test: test_custom_locale_selector
# https://github.com/mrjoes/flask-babelex/issues/17
# TODO: Upstream

--- tests/tests.py.orig	2019-12-18 13:03:25 UTC
+++ tests/tests.py
@@ -35,7 +35,7 @@ class DateFormattingTestCase(unittest.TestCase):
         with app.test_request_context():
             app.config['BABEL_DEFAULT_LOCALE'] = 'de_DE'
             assert babel.format_datetime(d, 'long') == \
-                '12. April 2010 15:46:00 MESZ'
+                '12. April 2010 um 15:46:00 MESZ'
 
     def test_init_app(self):
         b = babel.Babel()
@@ -57,7 +57,7 @@ class DateFormattingTestCase(unittest.TestCase):
         with app.test_request_context():
             app.config['BABEL_DEFAULT_LOCALE'] = 'de_DE'
             assert babel.format_datetime(d, 'long') == \
-                '12. April 2010 15:46:00 MESZ'
+                '12. April 2010 um 15:46:00 MESZ'
 
     def test_custom_formats(self):
         app = flask.Flask(__name__)
@@ -95,7 +95,7 @@ class DateFormattingTestCase(unittest.TestCase):
         the_timezone = 'Europe/Vienna'
 
         with app.test_request_context():
-            assert babel.format_datetime(d) == '12.04.2010 15:46:00'
+            assert babel.format_datetime(d) == '12.04.2010, 15:46:00'
 
     def test_refreshing(self):
         app = flask.Flask(__name__)
