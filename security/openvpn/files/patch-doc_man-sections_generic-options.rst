--- doc/man-sections/generic-options.rst.orig	2023-01-25 10:00:58 UTC
+++ doc/man-sections/generic-options.rst
@@ -507,5 +507,8 @@ which mode OpenVPN is configured as.
   since it is usually used by other system services already. Always
   create a dedicated user for openvpn.
 
+  The FreeBSD port creates a group and user named :code:`openvpn`
+  for this purpose.
+
 --writepid file
   Write OpenVPN's main process ID to ``file``.
