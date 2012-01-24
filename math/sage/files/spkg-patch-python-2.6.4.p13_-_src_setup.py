--- python-2.6.4.p13/src/setup.py-orig	2012-01-21 21:42:43.000000000 +0000
+++ python-2.6.4.p13/src/setup.py	2012-01-21 21:45:11.000000000 +0000
@@ -1273,16 +1273,24 @@
                 )
             libraries = []
 
-        elif platform in ('freebsd4', 'freebsd5', 'freebsd6', 'freebsd7', 'freebsd8'):
+        elif platform in ('freebsd4', 'freebsd5', 'freebsd6'):
             # FreeBSD's P1003.1b semaphore support is very experimental
             # and has many known problems. (as of June 2008)
-            macros = dict(                  # FreeBSD
+            macros = dict(                  # FreeBSD 4-6
                 HAVE_SEM_OPEN=0,
                 HAVE_SEM_TIMEDWAIT=0,
                 HAVE_FD_TRANSFER=1,
                 )
             libraries = []
 
+        elif platform in ('freebsd7', 'freebsd8', 'freebsd9', 'freebsd10'):
+            macros = dict(                  # FreeBSD 7+
+                HAVE_SEM_OPEN=1,
+                HAVE_SEM_TIMEDWAIT=1,
+                HAVE_FD_TRANSFER=1,
+               )
+            libraries = []
+
         elif platform.startswith('openbsd'):
             macros = dict(                  # OpenBSD
                 HAVE_SEM_OPEN=0,            # Not implemented
