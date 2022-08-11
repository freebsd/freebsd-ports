--- gramps/gen/utils/grampslocale.py.orig	2022-06-08 13:02:30.116272000 +0200
+++ gramps/gen/utils/grampslocale.py	2022-06-08 12:40:34.253581000 +0200
@@ -527,9 +527,14 @@
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
