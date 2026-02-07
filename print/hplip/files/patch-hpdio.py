--- hpdio.py.orig	2022-02-23 07:41:04 UTC
+++ hpdio.py
@@ -67,7 +67,7 @@ def run(read_pipe2=None,  # pipe from hpssd
 
     global r2, w3
 #    tmp_dir = '/tmp'
-    os.umask(0o111)
+    os.umask(0o133)
 
     try:
         log.set_module("hp-systray(hpdio)")
