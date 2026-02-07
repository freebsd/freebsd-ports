--- setup.py.orig	2025-11-13 17:58:14 UTC
+++ setup.py
@@ -130,28 +130,6 @@ def get_data_files():
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
-        subprocess.run(f"cp po/{lang}.po po/{lang}", shell=True, check=True)
-        subprocess.run(f"msgfmt po/{lang}.po -o po/{lang}/duplicity.mo", shell=True, check=True)
-
-    for root, dirs, files in os.walk("po"):
-        for file in files:
-            path = os.path.join(root, file)
-            if path.endswith("duplicity.mo"):
-                lang = os.path.split(root)[-1]
-                data_files.append((f"share/locale/{lang}/LC_MESSAGES", [f"po/{lang}/duplicity.mo"]))
-
-    return data_files
-
 
 def cleanup():
     if os.path.exists("po/LINGUAS"):
