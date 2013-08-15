--- python-2.7.5.p1/src/setup.py-orig	2013-03-17 03:13:46.000000000 +0000
+++ python-2.7.5.p1/src/setup.py	2013-03-17 03:15:11.000000000 +0000
@@ -642,7 +642,7 @@
         # use the same library for the readline and curses modules.
         if 'curses' in readline_termcap_library:
             curses_library = readline_termcap_library
-        elif self.compiler.find_library_file(lib_dirs, 'ncursesw'):
+        elif self.compiler.find_library_file(lib_dirs, 'xxxncursesw'):
             curses_library = 'ncursesw'
         elif self.compiler.find_library_file(lib_dirs, 'ncurses'):
             curses_library = 'ncurses'
@@ -681,7 +681,7 @@
                                                      'termcap'):
                 readline_libs.append('termcap')
             exts.append( Extension('readline', ['readline.c'],
-                                   library_dirs=['/usr/lib/termcap'],
+                                   library_dirs=['/usr/lib', '/usr/lib/termcap'],
                                    extra_link_args=readline_extra_link_args,
                                    libraries=readline_libs) )
         else:
@@ -1120,7 +1122,7 @@
                 sysroot = macosx_sdk_root()
                 f = os.path.join(sysroot, f[1:])
 
-        if os.path.exists(f) and not db_incs:
+        if os.path.exists(f):
             data = open(f).read()
             m = re.search(r"#s*define\s+HASHVERSION\s+2\s*", data)
             if m is not None:
@@ -1246,12 +1248,13 @@
         # provided by the ncurses library.
         panel_library = 'panel'
         if curses_library.startswith('ncurses'):
-            if curses_library == 'ncursesw':
+            if curses_library == 'xxxncursesw':
                 # Bug 1464056: If _curses.so links with ncursesw,
                 # _curses_panel.so must link with panelw.
                 panel_library = 'panelw'
             curses_libs = [curses_library]
             exts.append( Extension('_curses', ['_cursesmodule.c'],
+                                   library_dirs = ['/usr/lib'],
                                    libraries = curses_libs) )
         elif curses_library == 'curses' and platform != 'darwin':
                 # OSX has an old Berkeley curses, not good enough for
@@ -1264,6 +1267,7 @@
                 curses_libs = ['curses']
 
             exts.append( Extension('_curses', ['_cursesmodule.c'],
+                                   library_dirs = ['/usr/lib'],
                                    libraries = curses_libs) )
         else:
             missing.append('_curses')
@@ -1432,10 +1436,22 @@
             macros = dict()
             libraries = []
 
-        elif host_platform in ('freebsd4', 'freebsd5', 'freebsd6', 'freebsd7', 'freebsd8'):
+        elif host_platform in ('freebsd4', 'freebsd5', 'freebsd6'):
             # FreeBSD's P1003.1b semaphore support is very experimental
             # and has many known problems. (as of June 2008)
-            macros = dict()
+            macros = dict(                  # FreeBSD 4-6
+                HAVE_SEM_OPEN=0,
+                HAVE_SEM_TIMEDWAIT=0,
+                HAVE_FD_TRANSFER=1,
+                )
+            libraries = []
+
+        elif host_platform in ('freebsd7', 'freebsd8', 'freebsd9', 'freebsd10'):
+            macros = dict(                  # FreeBSD 7+
+                HAVE_SEM_OPEN=1,
+                HAVE_SEM_TIMEDWAIT=1,
+                HAVE_FD_TRANSFER=1,
+                )
             libraries = []
 
         elif host_platform.startswith('openbsd'):
@@ -1484,7 +1500,7 @@
             missing.append('linuxaudiodev')
 
         if (host_platform in ('linux2', 'freebsd4', 'freebsd5', 'freebsd6',
-                        'freebsd7', 'freebsd8')
+                        'freebsd7', 'freebsd8', 'freebsd9', 'freebsd10')
             or host_platform.startswith("gnukfreebsd")):
             exts.append( Extension('ossaudiodev', ['ossaudiodev.c']) )
         else:
@@ -2066,9 +2082,7 @@
           ext_modules=[Extension('_struct', ['_struct.c'])],
 
           # Scripts to install
-          scripts = ['Tools/scripts/pydoc', 'Tools/scripts/idle',
-                     'Tools/scripts/2to3',
-                     'Lib/smtpd.py']
+          scripts = []
         )
 
 # --install-platlib
