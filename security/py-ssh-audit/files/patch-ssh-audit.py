--- ssh-audit.py.orig	2020-03-12 08:24:32 UTC
+++ ssh-audit.py
@@ -49,11 +49,11 @@ try:  # pragma: nocover
 	from typing import Callable, Optional, Union, Any
 except ImportError:  # pragma: nocover
 	pass
-try:  # pragma: nocover
-	from colorama import init as colorama_init
-	colorama_init(strip=False)  # pragma: nocover
-except ImportError:  # pragma: nocover
-	pass
+#try:  # pragma: nocover
+#	from colorama import init as colorama_init
+#	colorama_init(strip=False)  # pragma: nocover
+#except ImportError:  # pragma: nocover
+#	pass
 
 
 def usage(err=None):
