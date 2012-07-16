--- python-2.7.3.p0/src/setup.py-orig	2012-04-22 00:04:08.000000000 +0000
+++ python-2.7.3.p0/src/setup.py	2012-04-22 00:10:25.000000000 +0000
@@ -1432,10 +1432,24 @@
             macros = dict()
             libraries = []
 
-        elif platform in ('freebsd4', 'freebsd5', 'freebsd6', 'freebsd7', 'freebsd8'):
+        elif platform in ('freebsd4', 'freebsd5', 'freebsd6'):
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
+        elif platform in ('freebsd7', 'freebsd8', 'freebsd9', 'freebsd10'):
+            # FreeBSD's P1003.1b semaphore support is very experimental
+            # and has many known problems. (as of June 2008)
+            macros = dict(                  # FreeBSD 7+
+                HAVE_SEM_OPEN=1,
+                HAVE_SEM_TIMEDWAIT=1,
+                HAVE_FD_TRANSFER=1,
+                )
             libraries = []
 
         elif platform.startswith('openbsd'):
