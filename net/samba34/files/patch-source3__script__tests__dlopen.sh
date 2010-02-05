--- ./source3/script/tests/dlopen.sh.orig	2010-01-18 12:38:09.000000000 +0100
+++ ./source3/script/tests/dlopen.sh	2010-01-22 02:42:50.000000000 +0100
@@ -67,7 +67,7 @@
 	esac
 done
 
-${CC:-gcc} $RPM_OPT_FLAGS $CFLAGS -o $tempdir/dlopen $cflags $tempdir/dlopen.c $ldflags -ldl
+${CC:-gcc} $RPM_OPT_FLAGS $CFLAGS -o $tempdir/dlopen $cflags $tempdir/dlopen.c $ldflags
 
 retval=0
 for module in $modules ; do
