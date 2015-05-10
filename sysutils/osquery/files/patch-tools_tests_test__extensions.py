--- tools/tests/test_extensions.py.orig	2015-05-05 00:16:41 UTC
+++ tools/tests/test_extensions.py
@@ -364,9 +364,11 @@ if __name__ == "__main__":
     thrift_path = test_base.ARGS.build + "/generated/gen-py"
     try:
         sys.path.append(thrift_path)
+        sys.path.append(thrift_path + "/osquery")
         from osquery import *
-    except ImportError:
+    except ImportError as e:
         print ("Cannot import osquery thrift API from %s" % (thrift_path))
+        print ("Exception: %s" % (str(e)))
         print ("You must first run: make")
         exit(1)
 
