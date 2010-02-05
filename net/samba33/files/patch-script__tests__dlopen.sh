--- ./script/tests/dlopen.sh.orig	2010-01-14 10:12:10.000000000 +0000
+++ ./script/tests/dlopen.sh	2010-02-05 00:27:01.000000000 +0000
@@ -67,7 +67,7 @@
 	esac
 done
 
-${CC:-gcc} $RPM_OPT_FLAGS $CFLAGS -o $tempdir/dlopen $cflags $tempdir/dlopen.c $ldflags -ldl
+${CC:-gcc} $RPM_OPT_FLAGS $CFLAGS -o $tempdir/dlopen $cflags $tempdir/dlopen.c $ldflags
 
 retval=0
 for module in $modules ; do
