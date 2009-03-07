--- script/tests/dlopen.sh.orig	2009-03-07 03:03:34.000000000 +0000
+++ script/tests/dlopen.sh	2009-03-07 03:04:03.000000000 +0000
@@ -67,7 +67,7 @@
 	esac
 done
 
-${CC:-gcc} $RPM_OPT_FLAGS $CFLAGS -o $tempdir/dlopen $cflags $tempdir/dlopen.c $ldflags -ldl
+${CC:-gcc} $RPM_OPT_FLAGS $CFLAGS -o $tempdir/dlopen $cflags $tempdir/dlopen.c $ldflags
 
 retval=0
 for module in $modules ; do
