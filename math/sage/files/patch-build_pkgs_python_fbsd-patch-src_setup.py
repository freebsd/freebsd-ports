--- /dev/null	2014-11-18 03:33:07.000000000 +0000
+++ build/pkgs/python/fbsd-patch-src_setup.py	2014-11-18 03:37:12.000000000 +0000
@@ -0,0 +1,30 @@
+# Description: SEM option patch. If SEM is enabled, enable the build properly
+# Not upstreamed
+
+--- src/setup.py.orig	2013-04-07 11:07:43.000000000 +0400
++++ src/setup.py	2013-04-07 11:16:36.000000000 +0400
+@@ -1551,10 +1551,22 @@
+             macros = dict()
+             libraries = []
+ 
+-        elif host_platform in ('freebsd4', 'freebsd5', 'freebsd6', 'freebsd7', 'freebsd8'):
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
