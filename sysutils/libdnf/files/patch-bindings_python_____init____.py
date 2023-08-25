- from https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=273044
- fix regex and duplicate rtti

--- bindings/python/__init__.py.orig	2023-07-28 12:49:18 UTC
+++ bindings/python/__init__.py
@@ -6,11 +6,14 @@ from . import error
 import sys, os
 sys.setdlopenflags(os.RTLD_NOW | os.RTLD_GLOBAL)
 from . import error
-sys.setdlopenflags(os.RTLD_NOW)
 
+# Other modules also need to be loaded with RTLD_GLOBAL to preserve uniqueness
+# of RTTI.  There are code paths where an exception thrown in one module is
+# supposed to be caught in another.
 from . import common_types
 from . import conf
 from . import module
 from . import repo
 from . import transaction
 from . import utils
+sys.setdlopenflags(os.RTLD_NOW)
