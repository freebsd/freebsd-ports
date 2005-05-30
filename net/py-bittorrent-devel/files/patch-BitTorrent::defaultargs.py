--- BitTorrent/defaultargs.py.orig	Tue May 24 03:01:06 2005
+++ BitTorrent/defaultargs.py	Sun May 29 22:48:48 2005
@@ -110,7 +110,7 @@
      _("do not connect to several peers that have the same IP address")),
     ('peer_socket_tos', 8,
      _("if nonzero, set the TOS option for peer connections to this value")),
-    ('bad_libc_workaround', MYFALSE,
+    ('bad_libc_workaround', MYTRUE,
      _("enable workaround for a bug in BSD libc that makes file reads very slow.")),
     ('tracker_proxy', '',
      _("address of HTTP proxy to use for tracker connections")),
