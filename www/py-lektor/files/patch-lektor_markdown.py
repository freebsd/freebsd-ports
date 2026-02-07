--- lektor/markdown.py.orig	2023-09-02 08:00:20 UTC
+++ lektor/markdown.py
@@ -2,7 +2,7 @@ import threading
 from urllib.parse import urlsplit
 from weakref import ref as weakref
 
-import mistune
+import mistune0 as mistune
 from markupsafe import Markup
 
 from lektor.context import get_ctx
