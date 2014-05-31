--- /dev/null	2014-05-31 00:44:00.000000000 +0000
+++ build/pkgs/python/fbsd-patch-src_setup.py	2014-05-31 00:38:21.000000000 +0000
@@ -0,0 +1,74 @@
+--- src/setup.py.orig	2013-04-06 18:02:41.000000000 +0400
++++ src/setup.py	2013-04-07 10:52:47.000000000 +0400
+@@ -755,7 +755,7 @@
+             elif curses_library:
+                 readline_libs.append(curses_library)
+             elif self.compiler.find_library_file(lib_dirs +
+-                                                     ['/usr/lib/termcap'],
++                                                     ['/usr/lib', '/usr/lib/termcap'],
+                                                      'termcap'):
+                 readline_libs.append('termcap')
+             exts.append( Extension('readline', ['readline.c'],
+@@ -862,6 +862,8 @@
+             # OpenSSL doesn't do these until 0.9.8 so we'll bring our own hash
+             exts.append( Extension('_sha256', ['sha256module.c']) )
+             exts.append( Extension('_sha512', ['sha512module.c']) )
++        else:
++            open('.without_own_sha', 'w')
+ 
+         # Modules that provide persistent dictionary-like semantics.  You will
+         # probably want to arrange for at least one of them to be available on
+@@ -1208,7 +1210,7 @@
+                 sysroot = macosx_sdk_root()
+                 f = os.path.join(sysroot, f[1:])
+ 
+-        if os.path.exists(f) and not db_incs:
++        if os.path.exists(f):
+             data = open(f).read()
+             m = re.search(r"#s*define\s+HASHVERSION\s+2\s*", data)
+             if m is not None:
+@@ -1540,7 +1544,7 @@
+             macros = dict()
+             libraries = []
+ 
+-        elif host_platform in ('freebsd4', 'freebsd5', 'freebsd6', 'freebsd7', 'freebsd8'):
++        elif host_platform in ('freebsd4', 'freebsd5', 'freebsd6', 'freebsd7', 'freebsd8', 'freebsd9', 'freebsd10', 'freebsd11'):
+             # FreeBSD's P1003.1b semaphore support is very experimental
+             # and has many known problems. (as of June 2008)
+             macros = dict()
+@@ -1592,7 +1596,7 @@
+             missing.append('linuxaudiodev')
+ 
+         if (host_platform in ('linux2', 'freebsd4', 'freebsd5', 'freebsd6',
+-                        'freebsd7', 'freebsd8')
++                        'freebsd7', 'freebsd8', 'freebsd9', 'freebsd10', 'freebsd11')
+             or host_platform.startswith("gnukfreebsd")):
+             exts.append( Extension('ossaudiodev', ['ossaudiodev.c']) )
+         else:
+--- src/setup.py.orig	2013-04-07 11:07:43.000000000 +0400
++++ src/setup.py	2013-04-07 11:16:36.000000000 +0400
+@@ -1544,10 +1544,22 @@
+             macros = dict()
+             libraries = []
+ 
+-        elif host_platform in ('freebsd4', 'freebsd5', 'freebsd6', 'freebsd7', 'freebsd8', 'freebsd9', 'freebsd10', 'freebsd11'):
++        elif host_platform in ('freebsd4', 'freebsd5', 'freebsd6'):
+             # FreeBSD's P1003.1b semaphore support is very experimental
+             # and has many known problems. (as of June 2008)
+-            macros = dict()
++            macros = dict(                  # FreeBSD 4-6
++                HAVE_SEM_OPEN=0,
++                HAVE_SEM_TIMEDWAIT=0,
++                HAVE_FD_TRANSFER=1,
++                )
++            libraries = []
++
++        elif host_platform in ('freebsd7', 'freebsd8', 'freebsd9', 'freebsd10', 'freebsd11'):
++            macros = dict(                  # FreeBSD 7+
++                HAVE_SEM_OPEN=1,
++                HAVE_SEM_TIMEDWAIT=1,
++                HAVE_FD_TRANSFER=1,
++                )
+             libraries = []
+ 
+         elif host_platform.startswith('openbsd'):
