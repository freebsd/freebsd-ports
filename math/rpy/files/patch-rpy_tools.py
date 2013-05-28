--- rpy_tools.py
+++ rpy_tools.py
@@ -97,8 +97,7 @@ def get_R_VERSION(RHOME=None, force_exec=False):
     if stat or len(output)<=0:
       raise RuntimeError("Couldn't execute the R interpreter" +
                          " `%s'.\n" % rexec )
-    # edd 05 Apr 2006  version = re.search("R +([0-9]\.[0-9]\.[0-9])", output)
-    version = re.search(" +([0-9]\.[0-9]\.[0-9])", output)
+    version = re.search(" +([0-9]+\.[0-9]+\.[0-9]+)", output)
     if not version:
       raise RuntimeError("Couldn't obtain version number from output\n"
                                "of `R --version'.\n")
@@ -143,3 +142,20 @@ def get_PYTHON_DIR():
                        % PYTHON_DIR )
     
   return PYTHON_DIR
+
+def get_R_LAPACK_LIB_FLAGS(RHOME=get_R_HOME()):
+  """
+  Determine the necessary link arguments for lapack 
+  """
+  rexec = os.path.join(RHOME, 'bin', 'R')
+  stat, output = getstatusoutput('"%s" CMD config LAPACK_LIBS' % rexec )
+  if stat or len(output)<=0:
+    raise RuntimeError("Couldn't execute the R interpreter" +
+                       " `%s'.\n" % rexec )
+  
+  LAPACK_LIB_FLAGS = output.strip()
+  if not LAPACK_LIB_FLAGS:
+    raise RuntimeError("Couldn't obtain LAPACK_LIBS information from output\n"
+                       "of `R CMD config LAPACK_LIBS'.\n")
+  
+  return LAPACK_LIB_FLAGS
diff --git setup.py setup.py
index cf0fa2e..4a1f840 100644
