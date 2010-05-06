--- ./acinclude.m4.orig	2008-01-07 10:01:56.000000000 -0500
+++ ./acinclude.m4	2010-05-06 16:06:03.732834004 -0400
@@ -169,13 +169,17 @@
 
   if test -z "$module_standalone"; then
     if test -z "$2"; then
-      libname="mod_$1.la"
+      # The filename of a convenience library must have a "lib" prefix:
+      libname="libmod_$1.la"
       BUILTIN_LIBS="$BUILTIN_LIBS $modpath_current/$libname"
       modpath_static="$modpath_static $libname"
       cat >>$modpath_current/modules.mk<<EOF
 $libname: $objects
 	\$(MOD_LINK) $objects $5
 EOF
+      if test ! -z "$5"; then
+        APR_ADDTO(AP_LIBS, [$5])
+      fi
     else
       apache_need_shared=yes
       libname="mod_$1.la"
