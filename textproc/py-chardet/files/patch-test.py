From 0561ddcedcd12ea1f98b7ddedb93686ed8a5ffa4 Mon Sep 17 00:00:00 2001
From: =?UTF-8?q?Miro=20Hron=C4=8Dok?= <miro@hroncok.cz>
Date: Tue, 12 Mar 2019 18:44:36 +0100
Subject: [PATCH] Support pytest 4, don't apply marks directly to parameters

Fixes https://github.com/chardet/chardet/issues/173

--- test.py.orig	2019-12-18 03:03:28 UTC
+++ test.py
@@ -59,7 +59,7 @@ def gen_test_params():
             full_path = join(path, file_name)
             test_case = full_path, encoding
             if full_path in EXPECTED_FAILURES:
-                test_case = pytest.mark.xfail(test_case)
+                test_case = pytest.param(*test_case, marks=pytest.mark.xfail)
             yield test_case
