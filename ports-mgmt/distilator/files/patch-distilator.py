--- distilator.py.orig	2020-07-18 07:41:39 UTC
+++ distilator.py
@@ -1,8 +1,6 @@
 #!/usr/bin/env python
 """Command-line script to check the availability of a ports distfiles."""
 
-from __future__ import print_function  # Imports print_function from python 3
-
 from multiprocessing import Pool
 from functools import partial
 
@@ -38,7 +36,7 @@ class Distfiles:
         valid_urls = []
         for url in urls:
             thisurl = urlparse(url)
-            if thisurl.scheme is not "":
+            if thisurl.scheme != "":
                 valid_urls.append(thisurl.geturl())
         return valid_urls
 
@@ -129,7 +127,7 @@ def resolve_or_timeout_error(url, urltype, args):
 def validate_url_pool(args, iterable):
     """Method to validate a list of URLs."""
     for url, urltype in iterable.items():
-        if urlparse(url).scheme is "http" or "https":
+        if urlparse(url).scheme == "http" or "https":
             try:
                 user_agent = "distilator/%s (%s)" % (__version__, os.uname()[0])
                 headers = {"User-Agent": user_agent}
@@ -160,7 +158,7 @@ def validate_url_pool(args, iterable):
                 status_code = resolve_or_timeout_error(url, urltype, args)
                 return {"status_code": status_code, "urltype": urltype, "url": url}
 
-        if urlparse(url).scheme is "ftp":
+        if urlparse(url).scheme == "ftp":
             try:
                 requests_ftp.monkeypatch_session()
                 session = requests.Session()
