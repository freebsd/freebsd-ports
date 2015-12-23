--- ./buildtools/wafsamba/samba_install.py.orig	2015-07-21 09:47:48.000000000 +0000
+++ ./buildtools/wafsamba/samba_install.py	2015-10-05 13:00:26.761717407 +0000
@@ -116,7 +116,7 @@
                 inst_name    = bld.make_libname(t.target)
         elif self.vnum:
             vnum_base    = self.vnum.split('.')[0]
-            install_name = bld.make_libname(target_name, version=self.vnum)
+            install_name = bld.make_libname(target_name, version=vnum_base)
             install_link = bld.make_libname(target_name, version=vnum_base)
             inst_name    = bld.make_libname(t.target)
             if not self.private_library:
