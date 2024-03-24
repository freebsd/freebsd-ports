From: Jonatan Heyman <jonatan@heyman.info>
Date: Thu, 10 Nov 2022 23:26:07 +0100
Subject: [PATCH] Global regex flags must be at the start of regex in Python
 3.11

Obtained from:

https://patch-diff.githubusercontent.com/raw/miracle2k/django-assets/pull/104.patch

--- django_assets/glob.py.orig	2018-02-23 09:54:00 UTC
+++ django_assets/glob.py
@@ -121,7 +121,7 @@ def translate(pat):
                 res = '%s([%s])' % (res, stuff)
         else:
             res = res + re.escape(c)
-    return res + '\Z(?ms)'
+    return '(?ms)' + res + '\Z'
 
 
 """Filename globbing utility."""
