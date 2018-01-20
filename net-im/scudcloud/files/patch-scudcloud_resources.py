--- scudcloud/resources.py.orig	2018-01-19 13:48:09 UTC
+++ scudcloud/resources.py
@@ -13,7 +13,7 @@ class Resources:
     GOOGLE_OAUTH2_URL_RE = re.compile(r'^https://accounts.google.com/o/oauth')
 
     SPELL_LIMIT = 6
-    SPELL_DICT_PATH  = '/usr/share/hunspell'
+    SPELL_DICT_PATH  = '%%LOCALBASE%%/share/hunspell'
     DEFAULT_CONFDIR  = '~/.config/scudcloud'
     DEFAULT_CACHEDIR = '~/.cache/scudcloud'
 
