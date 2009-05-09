--- ./system-config-printer-kde/cmake-modules/FindSystemConfigPrinter.py.orig	2008-09-13 12:16:28.000000000 +0400
+++ ./system-config-printer-kde/cmake-modules/FindSystemConfigPrinter.py	2009-05-04 22:46:32.000000000 +0400
@@ -4,7 +4,7 @@
 
 import sys
 
-SYSTEM_CONFIG_PRINTER_DIR = "/usr/share/system-config-printer"
+SYSTEM_CONFIG_PRINTER_DIR = "%%LOCALBASE%%/share/system-config-printer"
 sys.path.append (SYSTEM_CONFIG_PRINTER_DIR)
 
 try:
