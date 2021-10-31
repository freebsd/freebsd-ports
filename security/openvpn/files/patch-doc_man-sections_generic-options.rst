--- doc/man-sections/generic-options.rst.orig	2021-10-31 16:17:17 UTC
+++ doc/man-sections/generic-options.rst
@@ -431,7 +431,7 @@ which mode OpenVPN is configured as.
   able to gain control of an OpenVPN session. Though OpenVPN's security
   features make this unlikely, it is provided as a second line of defense.
 
-  By setting ``user`` to :code:`nobody` or somebody similarly unprivileged,
+  By setting ``user`` to :code:`openvpn` or somebody similarly unprivileged,
   the hostile party would be limited in what damage they could cause. Of
   course once you take away privileges, you cannot return them to an
   OpenVPN session. This means, for example, that if you want to reset an
