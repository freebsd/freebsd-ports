Avoid the download of various intersphinx inventories during build.  Only two
intersphinx mappings are used and the documentation can be built/used without
them.

--- docs/conf.py.orig	2022-06-12 10:26:47 UTC
+++ docs/conf.py
@@ -188,13 +188,3 @@ texinfo_documents = [
 # -- Extension configuration -------------------------------------------------
 
 # -- Options for intersphinx extension ---------------------------------------
-
-intersphinx_mapping = {
-    "python": ("https://docs.python.org/3/", None),
-    "django": (
-        "https://docs.djangoproject.com/en/stable/",
-        "https://docs.djangoproject.com/en/stable/_objects/",
-    ),
-    "pythonldap": ("https://www.python-ldap.org/en/latest/", None),
-    "tox": ("https://tox.wiki/en/latest/", None),
-}
