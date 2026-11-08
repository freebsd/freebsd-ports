Description: Make the editable_wheel hook optional; the ports tree's
  setuptools 63 does not have it.
Issue ID: none
Changeset: none
TODO: FreeBSD-specific (old setuptools in ports), not for upstream.

--- setup.py.orig	2026-10-12 00:55:10 UTC
+++ setup.py
@@ -17,7 +17,10 @@ from setuptools.command.build import build  # type: ig
 # External imports
 from setuptools import setup  # type: ignore[import]
 from setuptools.command.build import build  # type: ignore[import]
-from setuptools.command.editable_wheel import editable_wheel  # type: ignore[import]
+try:
+    from setuptools.command.editable_wheel import editable_wheel  # type: ignore[import]
+except ImportError:  # setuptools < 64
+    editable_wheel = None
 from setuptools.command.sdist import sdist  # type: ignore[import]
 
 # --- Helpers ----------------------------------------------------------------
@@ -162,7 +165,7 @@ class Build(build):  # type: ignore
         build_or_install_bokehjs(self.distribution.packages)
         super().run()
 
-class EditableWheel(editable_wheel):  # type: ignore
+class EditableWheel(editable_wheel or object):  # type: ignore
     def run(self) -> None:
         check_tags()
         build_or_install_bokehjs(self.distribution.packages)
@@ -174,4 +177,7 @@ class Sdist(sdist):  # type: ignore
         build_or_install_bokehjs(self.distribution.packages)
         super().run()
 
-setup(cmdclass={"build": Build, "editable_wheel": EditableWheel, "sdist": Sdist})
+cmdclass = {"build": Build, "sdist": Sdist}
+if editable_wheel is not None:
+    cmdclass["editable_wheel"] = EditableWheel
+setup(cmdclass=cmdclass)
