Obtained from:	https://github.com/asciidoc/asciidoc-py3/commit/8313e45cc78af30bb8df5d33311a7f2fdc50595c

--- asciidoc.py.orig	2020-10-30 15:14:01 UTC
+++ asciidoc.py
@@ -969,7 +969,7 @@ def system(name, args, is_macro=False, attrs=None):
                 line = subs_attrs(line)
                 if line is not None:
                     result.append(line)
-            result = DEFAULT_NEWLINE.join(result)
+            result = config.newline.join(result)
     else:
         assert False
     if result and name in ('eval3', 'sys3'):
