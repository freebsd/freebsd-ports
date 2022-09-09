Relax requirements for textproc/py-textfsm as it works with newer versions
of TextFSM.

--- setup.py.orig	2022-09-03 15:00:57 UTC
+++ setup.py
@@ -52,7 +52,7 @@ setup(
         "scp>=0.13.3",
         "tenacity",
         "pyyaml>=5.3",
-        "textfsm==1.1.2",
+        "textfsm>=1.1.2",
         "ntc-templates>=2.0.0",
         "pyserial",
     ],
