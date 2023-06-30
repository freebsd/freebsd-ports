--- gramps/gen/utils/grampslocale.py.orig	2023-06-29 20:37:13 UTC
+++ gramps/gen/utils/grampslocale.py
@@ -525,9 +525,14 @@ class GrampsLocale:
         # with locale instead of gettext. Win32 doesn't support bindtextdomain.
         if self.localedir:
             if not sys.platform == 'win32':
-                # bug12278, _build_popup_ui() under linux and macOS
-                locale.textdomain(self.localedomain)
-                locale.bindtextdomain(self.localedomain, self.localedir)
+                if hasattr(locale, 'textdomain'):
+                    # bug12278, _build_popup_ui() under linux and macOS
+                    locale.textdomain(self.localedomain)
+                    locale.bindtextdomain(self.localedomain, self.localedir)
+                else:
+                    import gettext
+                    gettext.textdomain(self.localedomain)
+                    gettext.bindtextdomain(self.localedomain, self.localedir)
             else:
                 self._win_bindtextdomain(self.localedomain.encode('utf-8'),
                                          self.localedir.encode('utf-8'))
