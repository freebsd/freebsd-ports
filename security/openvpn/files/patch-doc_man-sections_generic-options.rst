--- doc/man-sections/generic-options.rst.orig	2025-09-22 09:50:37 UTC
+++ doc/man-sections/generic-options.rst
@@ -513,5 +513,8 @@ --user user
   since it is usually used by other system services already. Always
   create a dedicated user for openvpn.
 
+  The FreeBSD port creates a group and user named :code:`openvpn`
+  for this purpose.
+
 --writepid file
   Write OpenVPN's main process ID to ``file``.
