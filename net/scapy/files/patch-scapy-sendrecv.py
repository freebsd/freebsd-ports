--- scapy/sendrecv.py.orig	2009-07-15 18:19:31.000000000 +0200
+++ scapy/sendrecv.py	2009-07-15 18:19:46.000000000 +0200
@@ -9,7 +9,7 @@
 from arch import *
 from config import conf
 from packet import Gen
-from utils import warning
+from utils import warning,PcapReader
 import plist
 from error import log_runtime,log_interactive
 
