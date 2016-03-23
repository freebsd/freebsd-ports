From 15ea270b76053effb114a3f423a2215506a4e24d Mon Sep 17 00:00:00 2001
From: RouxRC <b.ooghe@gmail.com>
Date: Mon, 23 Nov 2015 20:49:25 +0100
Subject: [PATCH] adapt tests to now full https twitter

--- tests/test_sanity.py.orig	2016-02-20 07:27:26 UTC
+++ tests/test_sanity.py
@@ -52,7 +52,7 @@ def test_API_set_unicode_tweet():
 
 
 def clean_link(text):
-    pos = text.find(" http://t.co")
+    pos = text.find(" https://t.co")
     if pos != -1:
         return text[:pos]
     return text
