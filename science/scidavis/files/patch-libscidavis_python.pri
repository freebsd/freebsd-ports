--- libscidavis/python.pri.orig	2018-10-17 03:28:35 UTC
+++ libscidavis/python.pri
@@ -27,7 +27,7 @@
       DEFINES += PYTHONHOME=/Applications/scidavis.app/Contents/Resources
     } 
     system(mkdir -p $${SIP_DIR})
-    system($$system($$PYTHONBIN python-sipcmd.py PyQt$$QT_MAJOR_VERSION) $$system($$PYTHONBIN-config --includes) -c $${SIP_DIR}  src/scidavis.sip)
+    system($$system($$PYTHONBIN python-sipcmd.py PyQt$$QT_MAJOR_VERSION) -I $$PYQT_SIPDIR $$system($$PYTHONBIN-config --includes) -c $${SIP_DIR}  src/scidavis.sip)
   }
 
   win32 {
