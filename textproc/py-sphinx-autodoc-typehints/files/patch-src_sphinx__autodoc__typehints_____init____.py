--- src/sphinx_autodoc_typehints/__init__.py.orig	2023-03-03 19:01:28.608152000 +0100
+++ src/sphinx_autodoc_typehints/__init__.py	2023-03-03 19:03:03.209005000 +0100
@@ -23,7 +23,14 @@
 from sphinx.util.inspect import stringify_signature
 
 from .patches import install_patches
-from .version import __version__
+
+# see https://github.com/tox-dev/sphinx-autodoc-typehints/pull/328/files for the original patch
+try:
+    from .version import __version__
+except ImportError:
+    # The format of this file was changed, so lets fall back to the older style.
+    # See https://github.com/tox-dev/sphinx-autodoc-typehints/issues/327
+    from .version import version as __version__
 
 _LOGGER = logging.getLogger(__name__)
 _PYDATA_ANNOTATIONS = {"Any", "AnyStr", "Callable", "ClassVar", "Literal", "NoReturn", "Optional", "Tuple", "Union"}
