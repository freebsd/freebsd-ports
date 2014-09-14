--- config/cs_auto_flags.sh.orig	2012-08-08 00:11:29.000000000 +0200
+++ config/cs_auto_flags.sh	2014-09-14 14:45:51.000000000 +0200
@@ -214,8 +214,6 @@
     gcc-3*|gcc-4.[01234]*)
       ;;
     *)
-      cflags_default_opt="$cflags_default_opt -fexcess-precision=fast"
-      cflags_default_hot="$cflags_default_hot -fexcess-precision=fast"
       ;;
   esac
 
