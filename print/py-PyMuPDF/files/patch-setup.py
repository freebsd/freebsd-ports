--- setup.py.orig	2026-03-31 15:35:34.771336000 -0700
+++ setup.py	2026-03-31 15:39:24.694002000 -0700
@@ -925,7 +925,7 @@
         env_add(env, 'XCXXFLAGS', '-DTOFU_CJK_EXT')
 
     if openbsd or freebsd:
-        env_add(env, 'CXX', 'c++', ' ')
+        env['CXX'] = 'c++'
     
     if darwin and os.environ.get('GITHUB_ACTIONS') == 'true':
         if os.environ.get('ImageOS') == 'macos13':
@@ -1432,6 +1432,8 @@
             ret.append(libclang)
         elif openbsd:
             print(f'OpenBSD: libclang not available via pip; assuming `pkg_add py3-llvm`.')
+        elif freebsd:
+            print(f'FreeBSD: libclang not available via pip; assuming `pkg install py3X-clang`.')
         elif darwin and platform_release_tuple() < (18,):
             # There are still of problems when building on old macos.
             ret.append('libclang==14.0.6')
@@ -1441,6 +1443,8 @@
             print(f'msys2: pip install of swig does not build; assuming `pacman -S swig`.')
         elif openbsd:
             print(f'OpenBSD: pip install of swig does not build; assuming `pkg_add swig`.')
+        elif freebsd:
+            print(f'FreeBSD: pip install of swig does not build; assuming `pkg install swig`.')
         elif PYMUPDF_SETUP_SWIG:
             pass
         elif darwin and python_version_tuple < (3, 13):
