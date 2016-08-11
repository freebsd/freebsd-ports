--- third_party/usrsctp/usrsctp.gyp.orig	2016-05-31 16:52:03.000000000 -0400
+++ third_party/usrsctp/usrsctp.gyp	2016-06-05 17:25:20.996841000 -0400
@@ -111,6 +111,14 @@
           'cflags!': [ '-Werror', '-Wall' ],
           'cflags': [ '-w' ],
         }],
+        ['OS=="freebsd"', {
+          'defines': [
+            'HAVE_SCONN_LEN',
+            '__Userspace_os_FreeBSD',
+          ],
+          'cflags!': [ '-Werror', '-Wall' ],
+          'cflags': [ '-U__FreeBSD__', '-w' ],
+        }],
         ['OS=="mac" or OS=="ios"', {
           'defines': [
             'HAVE_SA_LEN',
