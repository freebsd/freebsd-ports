--- ui/gfx/x/gen_xproto.py.orig	2020-07-13 16:58:52 UTC
+++ ui/gfx/x/gen_xproto.py
@@ -1015,6 +1015,10 @@ def main():
                             'dist-packages')
         sys.path.insert(1, path)
 
+    # Workaround to use the xcb-proto package, which installs using the default python version
+    # Remove this as soon as chromium builds with python3!
+    sys.path.append(os.path.join('..', '..', '..', 'site-packages'))
+
     import xcbgen.xtypes
     import xcbgen.state
 
