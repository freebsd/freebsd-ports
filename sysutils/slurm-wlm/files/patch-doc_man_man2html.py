--- doc/man/man2html.py.orig	2016-08-24 23:46:50 UTC
+++ doc/man/man2html.py
@@ -180,7 +180,7 @@ version = sys.argv[1]
 for f in sys.argv[4:]:
     posLastDot = f.rfind(".")
     mhtmlname = f[:posLastDot] + ".mhtml"
-    cmd = "man2html " + f + "> " + mhtmlname
+    cmd = "man2html < " + f + "> " + mhtmlname
     os.system(cmd)
     print(">>>>>>> " + mhtmlname)
     files.append(mhtmlname)
