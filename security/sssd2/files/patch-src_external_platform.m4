--- src/external/platform.m4.orig	2026-01-21 16:56:16 UTC
+++ src/external/platform.m4
@@ -18,7 +18,9 @@ if test x"$osname" = x ; then
     elif test -f /etc/gentoo-release ; then
         osname="gentoo"
     elif test -f /etc/os-release ; then
+        _old_version="$VERSION"
         . /etc/os-release
+        VERSION="$_old_version"
         if ([[ "${ID}" = "suse" ]]) || ([[ "${ID_LIKE#*suse*}" != "${ID_LIKE}" ]]); then
             osname="suse"
         fi
