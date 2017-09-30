--- sifter.py.orig	2017-09-30 17:57:06 UTC
+++ sifter.py
@@ -27,10 +27,10 @@ import code
 import copy
 from ctypes import *
 
-INJECTOR = "./injector"
+INJECTOR = "injector"
 arch = ""
 
-OUTPUT = "./data/"
+OUTPUT = os.getenv("HOME") + "/.sandsifter/"
 LOG  = OUTPUT + "log"
 SYNC = OUTPUT + "sync"
 TICK = OUTPUT + "tick"
@@ -679,7 +679,7 @@ class Gui:
             time.sleep(self.TIME_SLICE)
 
 def get_cpu_info():
-    with open("/proc/cpuinfo", "r") as f:
+    with open("/compat/linux/proc/cpuinfo", "r") as f:
         cpu = [l.strip() for l in f.readlines()[:7]]
     return cpu
 
@@ -808,9 +808,16 @@ def main():
     if not os.path.exists(OUTPUT):
         os.makedirs(OUTPUT)
 
+    real_injector, errors = \
+        subprocess.Popen(
+                ['which', INJECTOR],
+                stdout=subprocess.PIPE,
+                stderr=subprocess.PIPE
+                ).communicate()
+    real_injector = real_injector.replace('\n', '') # strip newline from shell output
     injector_bitness, errors = \
         subprocess.Popen(
-                ['file', INJECTOR],
+                ['file', real_injector],
                 stdout=subprocess.PIPE,
                 stderr=subprocess.PIPE
                 ).communicate()
