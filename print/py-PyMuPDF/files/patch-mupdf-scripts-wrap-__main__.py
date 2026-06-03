--- mupdf-1.27.2-source/scripts/wrap/__main__.py.orig	2026-03-31 15:55:23.151691000 -0700
+++ mupdf-1.27.2-source/scripts/wrap/__main__.py	2026-03-31 15:56:04.491151000 -0700
@@ -1736,7 +1736,7 @@
                                 )
                         if command_was_run:
                             macos_patch( libmupdfcpp, f'{build_dirs.dir_so}/libmupdf.dylib{so_version}')
-                        if so_version and state.state_.linux:
+                        if so_version and (state.state_.linux or state.state_.freebsd):
                             jlib.system(f'ln -sf libmupdfcpp.so{so_version} {build_dirs.dir_so}/libmupdfcpp.so')
 
                     elif 'fpic' in dir_so_flags:
