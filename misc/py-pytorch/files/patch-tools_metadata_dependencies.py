-- Relax the setuptools>=77.0.3 lower bound in the wheel's runtime dependency metadata.
-- FreeBSD's devel/py-setuptools is currently 63.1.0, so the upstream bound would make
-- the installed torch package declare a Requires-Dist that no port can satisfy.
-- The bound only exists upstream for PEP 639 license-expression validation, which the
-- port does not rely on (see files/patch-pyproject.toml, which drops the license-files key).
-- This replaces the old files/patch-setup.py: as of 2.14.0 PyTorch builds via
-- scikit-build-core and setup.py is a pip-forwarding shim, so the install_requires list
-- it used to patch now lives here.
-- see https://github.com/pytorch/pytorch/issues/152276 for the build-system migration
--- tools/metadata/dependencies.py.orig	2026-10-28 18:16:03 UTC
+++ tools/metadata/dependencies.py
@@ -29,7 +29,7 @@ BASE_DEPENDENCIES = [
 BASE_DEPENDENCIES = [
     "filelock",
     "typing-extensions>=4.13.0",
-    "setuptools>=77.0.3",
+    "setuptools",
     "sympy>=1.13.3",
     "networkx>=2.5.1",
     "jinja2",
