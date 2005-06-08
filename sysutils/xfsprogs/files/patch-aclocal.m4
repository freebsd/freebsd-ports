--- aclocal.m4.orig	Tue Oct 12 20:26:01 2004
+++ aclocal.m4	Thu Dec 23 14:52:43 2004
@@ -107,7 +107,7 @@
     tar=$TAR
     AC_SUBST(tar)
     if test -z "$ZIP"; then
-        AC_PATH_PROG(ZIP, gzip,, /bin:/usr/local/bin:/usr/freeware/bin)
+        AC_PATH_PROG(ZIP, gzip,, /bin:/usr/local/bin:/usr/freeware/bin:/usr/bin)
     fi
 
     zip=$ZIP
@@ -148,14 +148,14 @@
 
     if test "$enable_gettext" = yes; then
         if test -z "$MSGFMT"; then
-                AC_PATH_PROG(MSGFMT, msgfmt,, /usr/bin:/usr/freeware/bin)
+                AC_PATH_PROG(MSGFMT, msgfmt,, /usr/bin:/usr/freeware/bin:$PATH)
         fi
         msgfmt=$MSGFMT
         AC_SUBST(msgfmt)
         AC_PACKAGE_NEED_UTILITY($1, "$msgfmt", msgfmt, gettext)
 
         if test -z "$MSGMERGE"; then
-                AC_PATH_PROG(MSGMERGE, msgmerge,, /usr/bin:/usr/freeware/bin)
+                AC_PATH_PROG(MSGMERGE, msgmerge,, /usr/bin:/usr/freeware/bin:$PATH)
         fi
         msgmerge=$MSGMERGE
         AC_SUBST(msgmerge)
