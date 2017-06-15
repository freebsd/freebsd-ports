--- aclocal.m4.orig	2012-03-04 04:55:05 UTC
+++ aclocal.m4
@@ -319,6 +319,7 @@ AC_DEFUN([OD_OPENVPN_HEADER],[
 	AC_CACHE_VAL(od_cv_openvpn, [
 		AC_LINK_IFELSE([
 				AC_LANG_PROGRAM([
+						#include <stddef.h>
 						#include <openvpn-plugin.h>
 					], [
 						int flag = OPENVPN_PLUGIN_UP;
