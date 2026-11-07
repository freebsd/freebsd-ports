Description: Use the lowercase project name, so the wheel and its
  dist-info are named dshell as the ports framework expects for
  USE_PYTHON=pep517 (setuptools 63 keeps the case of the name).  The
  normalized project name is unchanged.
Issue ID: none
Changeset: none
TODO: FreeBSD-specific (ports framework naming), not for upstream.

--- setup.py.orig	2024-05-01 16:29:33 UTC
+++ setup.py
@@ -1,7 +1,7 @@
 from setuptools import find_packages, setup
 
 setup(
-    name="Dshell",
+    name="dshell",
     version="3.2.3",
     author="USArmyResearchLab",
     description="An extensible network forensic analysis framework",
