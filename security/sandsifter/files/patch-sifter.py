--- sifter.py.orig	2017-09-22 12:42:26 UTC
+++ sifter.py
@@ -26,11 +26,12 @@ import argparse
 import code
 import copy
 from ctypes import *
+import sysctl
 
-INJECTOR = "./injector"
+INJECTOR = "injector"
 arch = ""
 
-OUTPUT = "./data/"
+OUTPUT = os.getenv("HOME") + "/.sandsifter/"
 LOG  = OUTPUT + "log"
 SYNC = OUTPUT + "sync"
 TICK = OUTPUT + "tick"
@@ -679,7 +680,7 @@ class Gui:
             time.sleep(self.TIME_SLICE)
 
 def get_cpu_info():
-    with open("/proc/cpuinfo", "r") as f:
+    with open("/compat/linux/proc/cpuinfo", "r") as f:
         cpu = [l.strip() for l in f.readlines()[:7]]
     return cpu
 
@@ -808,9 +809,16 @@ def main():
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
