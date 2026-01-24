--- setup.py.orig	2026-01-24 08:17:11 UTC
+++ setup.py
@@ -286,7 +286,7 @@ from typing import Any, ClassVar, IO
 from pathlib import Path
 from typing import Any, ClassVar, IO
 
-import setuptools.command.bdist_wheel
+# import setuptools.command.bdist_wheel
 import setuptools.command.build_ext
 import setuptools.command.sdist
 import setuptools.errors
@@ -1429,29 +1429,37 @@ class concat_license_files:
         self.f1.write_text(self.bsd_text, encoding="utf-8")
 
 
-# Need to create the proper LICENSE.txt for the wheel
-class bdist_wheel(setuptools.command.bdist_wheel.bdist_wheel):
-    def run(self) -> None:
-        with concat_license_files(include_files=True):
-            super().run()
+try:
+    from wheel.bdist_wheel import bdist_wheel as _bdist_wheel
+except ImportError:
+    # This is useful when wheel is not installed and bdist_wheel is not
+    # specified on the command line. If it _is_ specified, parsing the command
+    # line will fail before bdist_wheel is needed
+    bdist_wheel = None
+else:
+    # Need to create the proper LICENSE.txt for the wheel
+    class bdist_wheel(_bdist_wheel):
+        def run(self) -> None:
+            with concat_license_files(include_files=True):
+                super().run()
 
-    def write_wheelfile(self, *args: Any, **kwargs: Any) -> None:
-        super().write_wheelfile(*args, **kwargs)
+        def write_wheelfile(self, *args: Any, **kwargs: Any) -> None:
+            super().write_wheelfile(*args, **kwargs)
 
-        if BUILD_LIBTORCH_WHL:
-            assert self.bdist_dir is not None
-            bdist_dir = Path(self.bdist_dir)
-            # Remove extraneneous files in the libtorch wheel
-            for file in itertools.chain(
-                bdist_dir.rglob("*.a"),
-                bdist_dir.rglob("*.so"),
-            ):
-                if (bdist_dir / file.name).is_file():
+            if BUILD_LIBTORCH_WHL:
+                assert self.bdist_dir is not None
+                bdist_dir = Path(self.bdist_dir)
+                # Remove extraneneous files in the libtorch wheel
+                for file in itertools.chain(
+                    bdist_dir.rglob("*.a"),
+                    bdist_dir.rglob("*.so"),
+                ):
+                    if (bdist_dir / file.name).is_file():
+                        file.unlink()
+                for file in bdist_dir.rglob("*.py"):
                     file.unlink()
-            for file in bdist_dir.rglob("*.py"):
-                file.unlink()
-            # need an __init__.py file otherwise we wouldn't have a package
-            (bdist_dir / "torch" / "__init__.py").touch()
+                # need an __init__.py file otherwise we wouldn't have a package
+                (bdist_dir / "torch" / "__init__.py").touch()
 
 
 class clean(Command):
@@ -1640,11 +1648,12 @@ def configure_extension_build() -> tuple[
     ext_modules.append(C)
 
     cmdclass = {
-        "bdist_wheel": bdist_wheel,
         "build_ext": build_ext,
         "clean": clean,
         "sdist": sdist,
     }
+    if bdist_wheel is not None:
+        cmdclass["bdist_wheel"] = bdist_wheel
 
     entry_points = {
         "console_scripts": [
