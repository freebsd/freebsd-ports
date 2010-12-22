--- admin/detect-autoconf.sh.orig	2006-11-09 16:42:52.000000000 -0600
+++ admin/detect-autoconf.sh	2010-09-28 11:41:11.000000000 -0500
@@ -12,4 +12,4 @@
 # separator if one is present, e.g. -1.2 where - is the separator.
-KDE_AUTOCONF_VERS="-2.58 -2.57 257 -2.54 -2.53a -2.53 -2.52 -2.5x"
-KDE_AUTOMAKE_VERS="-1.7 17 -1.6"
+KDE_AUTOCONF_VERS="-%%AUTOCONF_VERSION%%"
+KDE_AUTOMAKE_VERS="-%%AUTOMAKE_VERSION%%"
 
