--- setup.py.orig	2023-04-24 22:23:26 UTC
+++ setup.py
@@ -22,7 +22,7 @@ if watchman_src_dir is None:
 # files. Otherwise it is impossible to obtain a relative path across different
 # drives. However this has an implication that we will not be able to build this
 # package outside the repository. Not great but it works.
-py_dir = os.path.join(watchman_src_dir, "watchman", "python")
+py_dir = os.path.join(watchman_src_dir, "python")
 if os.name == "nt":
     os.chdir(py_dir)
     py_dir = os.path.relpath(py_dir)
