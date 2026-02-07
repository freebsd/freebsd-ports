--- meson_post_install.py.orig	2022-02-15 21:53:55 UTC
+++ meson_post_install.py
@@ -9,9 +9,9 @@ localstatedir = os.path.normpath(destdir + os.sep + sy
 # FIXME: meson will not track the creation of these directories
 #        https://github.com/mesonbuild/meson/blob/master/mesonbuild/scripts/uninstall.py#L39
 dst_dirs = [
-  (os.path.join(localstatedir, 'lib'), 0o755),
-  (os.path.join(localstatedir, 'lib', 'AccountsService', 'icons'), 0o775),
-  (os.path.join(localstatedir, 'lib', 'AccountsService', 'users'), 0o700),
+  (os.path.join(localstatedir, 'db'), 0o755),
+  (os.path.join(localstatedir, 'db', 'AccountsService', 'icons'), 0o775),
+  (os.path.join(localstatedir, 'db', 'AccountsService', 'users'), 0o700),
 ]
 
 for (dst_dir, dst_dir_mode) in dst_dirs:
