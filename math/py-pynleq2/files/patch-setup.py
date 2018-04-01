--- setup.py.orig	2015-10-20 14:54:08 UTC
+++ setup.py
@@ -75,19 +75,21 @@ if len(sys.argv) > 1 and '--help' not in
 
     for src, md5sum in zip(sources, md5sums):
         srcpath = os.path.join('nleq2', src)
-        if not os.path.exists(srcpath):
+        if False and not os.path.exists(srcpath):
             NLEQ2_URL = os.environ.get('PYNLEQ2_NLEQ2_ROOT_URL', None)
             if NLEQ2_URL:
                 download(NLEQ2_URL+src, srcpath)
             else:
                 fmtstr = "Could not find: %s ($PYNLEQ2_NLEQ2_ROOT_URL not set)"
                 raise ValueError(fmtstr % src)
-        if md5_of_file(srcpath).hexdigest() != md5sum:
+        if False and md5_of_file(srcpath).hexdigest() != md5sum:
             raise ValueError("Mismatching MD5 sum for %s" % srcpath)
 
     ext_modules = [
         Extension('pynleq2.nleq2', [os.path.join('nleq2', f)
-                                    for f in ('nleq2.pyf',) + sources])
+                                    for f in ('nleq2.pyf',)]
+                                   , libraries=['ff', 'flang', 'execinfo']
+                                   , library_dirs=['../.fbuild', '/usr/local/flang/lib'])
     ]
 
 PYNLEQ2_RELEASE_VERSION = os.environ.get('PYNLEQ2_RELEASE_VERSION', '')
