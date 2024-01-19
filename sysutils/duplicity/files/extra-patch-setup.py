--- setup.py.orig	2023-12-25 18:14:22 UTC
+++ setup.py
@@ -105,27 +105,6 @@ def get_data_files():
     if os.environ.get("READTHEDOCS") == "True":
         return data_files
 
-    # msgfmt the translation files
-    assert os.path.exists("po"), "Missing 'po' directory."
-
-    linguas = glob.glob("po/*.po")
-    for lang in linguas:
-        lang = lang[3:-3]
-        try:
-            os.mkdir(os.path.join("po", lang))
-        except os.error:
-            pass
-        assert not os.system(f"cp po/{lang}.po po/{lang}"), lang
-        assert not os.system(f"msgfmt po/{lang}.po -o po/{lang}/duplicity.mo"), lang
-
-    for root, dirs, files in os.walk("po"):
-        for file in files:
-            path = os.path.join(root, file)
-            if path.endswith("duplicity.mo"):
-                lang = os.path.split(root)[-1]
-                data_files.append((f"share/locale/{lang}/LC_MESSAGES", [f"po/{lang}/duplicity.mo"]))
-
-    return data_files
 
 
 def VersionedCopy(source, dest):
