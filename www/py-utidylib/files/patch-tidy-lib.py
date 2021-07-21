--- tidy/lib.py.orig	2021-05-02 11:39:44 UTC
+++ tidy/lib.py
@@ -7,6 +7,8 @@ import weakref
 from tidy.error import InvalidOptionError, OptionArgError
 
 LIBNAMES = (
+    # FreeBSD
+    "libtidy5.so",
     # Linux
     "libtidy.so",
     # MacOS
