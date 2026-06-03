--- tests/test_tool.py.orig	2026-04-07 22:59:54 UTC
+++ tests/test_tool.py
@@ -14,11 +14,9 @@ def test_convert_pdf_to_markdown():
     assert result["success"] is True
     assert "markdown_content" in result
     assert result["markdown_content"] == snapshot("""\
-# **Dummy PDF file**
+**Dummy PDF file**
 
 
------
-
 """)
 
     # temporary file to write the markdown content
@@ -31,9 +29,7 @@ -----
         with open(temp_file_path, encoding="utf-8") as f:
             content = f.read()
             assert content == snapshot("""\
-# **Dummy PDF file**
+**Dummy PDF file**
 
-
------
 
 """)
