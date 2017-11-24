--- ssh-audit.py.orig	2017-11-23 08:27:24 UTC
+++ ssh-audit.py
@@ -43,11 +43,12 @@ try:  # pragma: nocover
 	from typing import Callable, Optional, Union, Any
 except ImportError:  # pragma: nocover
 	pass
-try:  # pragma: nocover
-	from colorama import init as colorama_init
-	colorama_init()  # pragma: nocover
-except ImportError:  # pragma: nocover
-	pass
+# colorama is only for Windows, posix systems support colors without it
+#try:  # pragma: nocover
+#	from colorama import init as colorama_init
+#	colorama_init()  # pragma: nocover
+#except ImportError:  # pragma: nocover
+#	pass
 
 
 def usage(err=None):
