--- rpy_tools.py.orig	2009-12-29 09:42:02.000000000 +0800
+++ rpy_tools.py	2009-12-29 09:42:41.000000000 +0800
@@ -97,8 +97,8 @@
     if stat or len(output)<=0:
       raise RuntimeError("Couldn't execute the R interpreter" +
                          " `%s'.\n" % rexec )
-    # edd 05 Apr 2006  version = re.search("R +([0-9]\.[0-9]\.[0-9])", output)
-    version = re.search(" +([0-9]\.[0-9]\.[0-9])", output)
+    # edd 05 Apr 2006  version = re.search("R +([0-9]\.[0-9][0-9]\.[0-9])", output)
+    version = re.search(" +([0-9]\.[0-9][0-9]\.[0-9])", output)
     if not version:
       raise RuntimeError("Couldn't obtain version number from output\n"
                                "of `R --version'.\n")
