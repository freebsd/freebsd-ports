Avoid the download of various intersphinx inventories during build.  Only two
intersphinx mappings are used and the documentation can be built/used without
them.

--- docs/conf.py.orig	2021-02-28 15:46:24 UTC
+++ docs/conf.py
@@ -186,15 +186,3 @@ texinfo_documents = [
 
 
 # -- Extension configuration -------------------------------------------------
-
-# -- Options for intersphinx extension ---------------------------------------
-
-intersphinx_mapping = {
-    "python": ("https://docs.python.org/3/", None),
-    "django": (
-        "https://docs.djangoproject.com/en/stable/",
-        "https://docs.djangoproject.com/en/stable/_objects/",
-    ),
-    "pythonldap": ("https://python-ldap.readthedocs.io/en/latest/", None),
-    "tox": ("https://tox.readthedocs.io/en/latest/", None),
-}
