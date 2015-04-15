--- intltool.m4.orig	2012-02-26 18:31:06 UTC
+++ intltool.m4
@@ -164,6 +164,9 @@ if test -z "$DATADIRNAME"; then
                        return _nl_msg_cat_cntr]])],
     [DATADIRNAME=share],
     [case $host in
+    *-*-dragonfly*|*-*-freebsd*)
+    [DATADIRNAME=share]
+    ;;
     *-*-solaris*)
     dnl On Solaris, if bind_textdomain_codeset is in libc,
     dnl GNU format message catalog is always supported,
