--- doc/man-sections/generic-options.rst.orig	2026-04-25 20:34:09 UTC
+++ doc/man-sections/generic-options.rst
@@ -473,5 +473,8 @@ --user user
   since it is usually used by other system services already. Always
   create a dedicated user for openvpn.
 
+  The FreeBSD port creates a group and user named :code:`openvpn`
+  for this purpose.
+
 --writepid file
   Write OpenVPN's main process ID to ``file``.
