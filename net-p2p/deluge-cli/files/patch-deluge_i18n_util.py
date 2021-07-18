PR: https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=256484
https://dev.deluge-torrent.org/changeset/d6c96d629183e8bab

--- deluge/i18n/util.py.orig	2019-06-12 17:49:45 UTC
+++ deluge/i18n/util.py
@@ -114,7 +114,7 @@ def setup_translation():
         # Workaround for Python 2 unicode gettext (keyword removed in Py3).
         kwargs = {} if not deluge.common.PY2 else {'unicode': True}
 
-        gettext.install(I18N_DOMAIN, translations_path, names='ngettext', **kwargs)
+        gettext.install(I18N_DOMAIN, translations_path, names=['ngettext'], **kwargs)
         builtins.__dict__['_n'] = builtins.__dict__['ngettext']
 
         libintl = None
