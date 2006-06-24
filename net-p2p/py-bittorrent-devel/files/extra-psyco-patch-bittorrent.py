--- bittorrent.py.orig	Tue May 16 20:59:49 2006
+++ bittorrent.py	Thu May 18 23:04:01 2006
@@ -14,6 +14,13 @@
 
 from __future__ import division
 
+try:
+  import psyco
+  assert psyco.__version__ >= 0x010300f0
+  psyco.full()
+except:
+  pass
+
 import os
 import sys
 try:
