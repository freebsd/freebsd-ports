--- iocage_lib/ioc_plugin.py.orig	2024-09-20 06:45:27 UTC
+++ iocage_lib/ioc_plugin.py
@@ -61,7 +61,10 @@ from iocage_lib.dataset import Dataset
 GIT_LOCK = threading.Lock()
 RE_PLUGIN_VERSION = re.compile(r'"path":"([/\.\+,\d\w-]*)\.txz"')
 
+# deliberately crash if tarfile doesn't have required filter
+tarfile.tar_filter
 
+
 class IOCPlugin(object):
 
     """
@@ -157,7 +160,7 @@ class IOCPlugin(object):
                             shutil.copyfileobj(r.raw, f)
 
                     with tarfile.open(packagesite_txz_path) as p_file:
-                        p_file.extractall(path=tmpdir)
+                        p_file.extractall(path=tmpdir, filter='data')
 
                     packagesite_path = os.path.join(tmpdir, 'packagesite.yaml')
                     if not os.path.exists(packagesite_path):
