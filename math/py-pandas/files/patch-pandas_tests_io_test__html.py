Reported upstream

Various py3k test failures in tests.io.test_html with US-ASCII
preferred encoding
https://github.com/pandas-dev/pandas/issues/16525

--- pandas/tests/io/test_html.py.orig	2017-05-04 14:53:46 UTC
+++ pandas/tests/io/test_html.py
@@ -20,7 +20,7 @@ from numpy.random import rand
 from pandas import (DataFrame, MultiIndex, read_csv, Timestamp, Index,
                     date_range, Series)
 from pandas.compat import (map, zip, StringIO, string_types, BytesIO,
-                           is_platform_windows)
+                           is_platform_windows, PY3)
 from pandas.io.common import URLError, urlopen, file_path_to_url
 from pandas.io.html import read_html
 from pandas._libs.parsers import ParserError
@@ -96,6 +96,9 @@ class ReadHtmlMixin(object):
 class TestReadHtml(ReadHtmlMixin):
     flavor = 'bs4'
     spam_data = os.path.join(DATA_PATH, 'spam.html')
+    spam_data_kwargs = {}
+    if PY3:
+        spam_data_kwargs['encoding'] = 'UTF-8'
     banklist_data = os.path.join(DATA_PATH, 'banklist.html')
 
     @classmethod
@@ -247,10 +250,10 @@ class TestReadHtml(ReadHtmlMixin):
         assert_framelist_equal(df1, df2)
 
     def test_string_io(self):
-        with open(self.spam_data) as f:
+        with open(self.spam_data, **self.spam_data_kwargs) as f:
             data1 = StringIO(f.read())
 
-        with open(self.spam_data) as f:
+        with open(self.spam_data, **self.spam_data_kwargs) as f:
             data2 = StringIO(f.read())
 
         df1 = self.read_html(data1, '.*Water.*')
@@ -258,7 +261,7 @@ class TestReadHtml(ReadHtmlMixin):
         assert_framelist_equal(df1, df2)
 
     def test_string(self):
-        with open(self.spam_data) as f:
+        with open(self.spam_data, **self.spam_data_kwargs) as f:
             data = f.read()
 
         df1 = self.read_html(data, '.*Water.*')
@@ -267,10 +270,10 @@ class TestReadHtml(ReadHtmlMixin):
         assert_framelist_equal(df1, df2)
 
     def test_file_like(self):
-        with open(self.spam_data) as f:
+        with open(self.spam_data, **self.spam_data_kwargs) as f:
             df1 = self.read_html(f, '.*Water.*')
 
-        with open(self.spam_data) as f:
+        with open(self.spam_data, **self.spam_data_kwargs) as f:
             df2 = self.read_html(f, 'Unit')
 
         assert_framelist_equal(df1, df2)
