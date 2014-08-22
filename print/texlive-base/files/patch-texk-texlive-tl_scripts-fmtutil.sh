--- ./texk/texlive/tl_scripts/fmtutil.sh.orig	2014-04-21 09:17:48.000000000 +0900
+++ ./texk/texlive/tl_scripts/fmtutil.sh	2014-08-21 05:35:01.000000000 +0900
@@ -404,8 +404,7 @@
 ###############################################################################
 mktexupd()
 {
-  initTexmfMain
-  "$MT_TEXMFMAIN/web2c/mktexupd" "$@"
+  "$MT_MKTEXUPD" "$@"
 }
 
 ###############################################################################
@@ -687,6 +686,9 @@
 
   # remove any * for the sake of the kpsewhich lookup.
   eval lastarg=\$$#
+  case $lastarg in
+  \#*)	eval lastarg=\$$(($# - 1)); texargs="${texargs%\#*}" ;;
+  esac
   inifile=`echo $lastarg | sed 's%^\*%%'`
 
   # See if we can find $inifile for return code:
