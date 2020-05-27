--- libscidavis/python.pri.orig	2020-05-10 23:27:36 UTC
+++ libscidavis/python.pri
@@ -28,7 +28,7 @@
     } 
     SIP_FAILURE = TRUE
     system(mkdir -p $${SIP_DIR})
-    system($$system($$PYTHONBIN python-sipcmd.py PyQt$$QT_MAJOR_VERSION) $$system($$PYTHONBIN-config --includes) -c $${SIP_DIR}  src/scidavis.sip): SIP_FAILURE = FALSE
+    system($$system($$PYTHONBIN python-sipcmd.py PyQt$$QT_MAJOR_VERSION) -I $$PYQT_SIPDIR $$system($$PYTHONBIN-config --includes) -c $${SIP_DIR}  src/scidavis.sip): SIP_FAILURE = FALSE
     equals(SIP_FAILURE, "TRUE") {
         error(`$$PYTHONBIN python-sipcmd.py PyQt$$QT_MAJOR_VERSION` `$$PYTHONBIN-config --includes` -c $${SIP_DIR}  src/scidavis.sip FAILED in $$PWD)
     }
