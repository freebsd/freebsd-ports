--- meson_post_install.py.orig	2019-04-23 15:16:09 UTC
+++ meson_post_install.py
@@ -9,8 +9,8 @@ localstatedir = os.path.normpath(destdir + os.sep + sy
 # FIXME: meson will not track the creation of these directories
 #        https://github.com/mesonbuild/meson/blob/master/mesonbuild/scripts/uninstall.py#L39
 dst_dirs = [
-  (os.path.join(localstatedir, 'lib', 'AccountsService', 'icons'), 0o775),
-  (os.path.join(localstatedir, 'lib', 'AccountsService', 'users'), 0o700),
+  (os.path.join(localstatedir, 'db', 'AccountsService', 'icons'), 0o775),
+  (os.path.join(localstatedir, 'db', 'AccountsService', 'users'), 0o700),
 ]
 
 for (dst_dir, dst_dir_mode) in dst_dirs:
