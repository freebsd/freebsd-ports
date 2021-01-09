From: "James R. Barlow" <james@purplerock.ca>
Date: Wed, 6 Jan 2021 00:22:16 -0800
Subject: [PATCH] libqpdf 10.1.0 raises different exception [1]

The different errors are acceptable to us; actually they are more
correct than the original behavior.

From: "James R. Barlow" <james@purplerock.ca>
Date: Wed, 6 Jan 2021 03:39:50 -0800
Subject: [PATCH] Fix test_tokenfilter_is_abstract [2]

Obtained from:

[1] https://github.com/pikepdf/pikepdf/commit/fe4b568ac88ba551458578613b013ac17edf5c4e.patch
[2] https://github.com/pikepdf/pikepdf/commit/7ca375cb6ff82011d716da1614ef5721a97f91b0.patch

--- tests/test_filters.py.orig	2020-09-09 22:57:09 UTC
+++ tests/test_filters.py
@@ -74,19 +74,17 @@ class FilterInvalid(pikepdf.TokenFilter):
 
 def test_invalid_handle_token(pal):
     page = pikepdf.Page(pal.pages[0])
-    with pytest.raises(pikepdf.PdfError):
-        result = page.get_filtered_contents(FilterInvalid())
+    with pytest.raises((TypeError, pikepdf.PdfError)):
+        page.get_filtered_contents(FilterInvalid())
 
 
 def test_invalid_tokenfilter(pal):
     page = pikepdf.Page(pal.pages[0])
     with pytest.raises(TypeError):
-        result = page.get_filtered_contents(list())
+        page.get_filtered_contents(list())
 
 
 def test_tokenfilter_is_abstract(pal):
     page = pikepdf.Page(pal.pages[0])
-    try:
-        result = page.get_filtered_contents(pikepdf.TokenFilter())
-    except pikepdf.PdfError:
-        assert 'Tried to call pure virtual' in pal.get_warnings()[0]
+    with pytest.raises((RuntimeError, pikepdf.PdfError)):
+        page.get_filtered_contents(pikepdf.TokenFilter())
