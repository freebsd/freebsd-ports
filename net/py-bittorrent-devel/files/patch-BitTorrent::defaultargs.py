--- BitTorrent/defaultargs.py.orig	Sun Dec 26 08:41:09 2004
+++ BitTorrent/defaultargs.py	Sun Dec 26 08:41:16 2004
@@ -83,7 +83,7 @@
      'if nonzero, set the TOS option for peer connections to this value'),
     ('filesystem_encoding', '',
      "character encoding used on the local filesystem. If left empty, autodetected. Autodetection doesn't work under python versions older than 2.3"),
-    ('enable_bad_libc_workaround', 0,
+    ('enable_bad_libc_workaround', 1,
      'enable workaround for a bug in BSD libc that makes file reads very slow.'),
     ]
 
