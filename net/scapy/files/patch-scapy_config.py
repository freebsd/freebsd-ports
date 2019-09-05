--- scapy/config.py.orig	2019-01-10 18:33:08 UTC
+++ scapy/config.py
@@ -16,7 +16,7 @@ import socket
 import sys
 
 from scapy import VERSION, base_classes
-from scapy.consts import DARWIN, WINDOWS, LINUX
+from scapy.consts import BSD, DARWIN, WINDOWS, LINUX
 from scapy.data import ETHER_TYPES, IP_PROTOS, TCP_SERVICES, UDP_SERVICES, \
     MANUFDB
 from scapy.error import log_scapy, warning, ScapyInvalidPlatformException
@@ -431,9 +431,9 @@ def _set_conf_sockets():
     """Populate the conf.L2Socket and conf.L3Socket
     according to the various use_* parameters
     """
-    if conf.use_bpf and not DARWIN:
+    if conf.use_bpf and not BSD:
         Interceptor.set_from_hook(conf, "use_bpf", False)
-        raise ScapyInvalidPlatformException("Darwin (OSX) only !")
+        raise ScapyInvalidPlatformException("BSD-like (OSX, *BSD...) only !")
     if conf.use_winpcapy and not WINDOWS:
         Interceptor.set_from_hook(conf, "use_winpcapy", False)
         raise ScapyInvalidPlatformException("Windows only !")
