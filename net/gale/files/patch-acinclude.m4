diff -u -N /tmp/gale-0.99egg/acinclude.m4 ./acinclude.m4
--- /tmp/gale-0.99egg/acinclude.m4	Wed Dec 31 16:00:00 1969
+++ ./acinclude.m4	Tue Nov  6 13:55:13 2001
@@ -0,0 +1,110 @@
+dnl This is a subroutine of AC_OUTPUT.
+dnl It is called after running config.status.
+dnl AC_OUTPUT_SUBDIRS(DIRECTORY...)
+define([AC_OUTPUT_SUBDIRS],
+[
+ifdef([AC_PROVIDE_AC_PROG_INSTALL], [ac_given_INSTALL="$INSTALL"
+])dnl
+if test "$no_recursion" != yes; then
+
+  # Remove --cache-file and --srcdir arguments so they do not pile up.
+  ac_sub_configure_args=
+  ac_prev=
+  for ac_arg in $ac_configure_args; do
+    if test -n "$ac_prev"; then
+      ac_prev=
+      continue
+    fi
+    case "$ac_arg" in
+    -cache-file | --cache-file | --cache-fil | --cache-fi \
+    | --cache-f | --cache- | --cache | --cach | --cac | --ca | --c)
+      ac_prev=cache_file ;;
+    -cache-file=* | --cache-file=* | --cache-fil=* | --cache-fi=* \
+    | --cache-f=* | --cache-=* | --cache=* | --cach=* | --cac=* | --ca=* | --c=*)
+      ;;
+    -srcdir | --srcdir | --srcdi | --srcd | --src | --sr)
+      ac_prev=srcdir ;;
+    -srcdir=* | --srcdir=* | --srcdi=* | --srcd=* | --src=* | --sr=*)
+      ;;
+    *) ac_sub_configure_args="$ac_sub_configure_args $ac_arg" ;;
+    esac
+  done
+
+  for ac_config_dir in $1; do
+
+    # Do not complain, so a configure script can configure whichever
+    # parts of a large source tree are present.
+    if test ! -d $srcdir/$ac_config_dir; then
+      continue
+    fi
+
+    echo configuring in $ac_config_dir
+
+    case "$srcdir" in
+    .) ;;
+    *)
+      if test -d ./$ac_config_dir || mkdir ./$ac_config_dir; then :;
+      else
+        AC_MSG_ERROR(can not create `pwd`/$ac_config_dir)
+      fi
+      ;;
+    esac
+
+    ac_popdir=`pwd`
+    cd $ac_config_dir
+
+changequote(, )dnl
+      # A "../" for each directory in /$ac_config_dir.
+      ac_dots=`echo $ac_config_dir|sed -e 's%^\./%%' -e 's%[^/]$%&/%' -e 's%[^/]*/%../%g'`
+changequote([, ])dnl
+
+    case "$srcdir" in
+    .) # No --srcdir option.  We are building in place.
+      ac_sub_srcdir=$srcdir ;;
+    /*) # Absolute path.
+      ac_sub_srcdir=$srcdir/$ac_config_dir ;;
+    *) # Relative path.
+      ac_sub_srcdir=$ac_dots$srcdir/$ac_config_dir ;;
+    esac
+
+    # Check for guested configure; otherwise get Cygnus style configure.
+    if test -f $ac_sub_srcdir/configure; then
+      ac_sub_configure=$ac_sub_srcdir/configure
+    elif test -f $ac_sub_srcdir/configure.in; then
+      ac_sub_configure=$ac_configure
+    else
+      AC_MSG_WARN(no configuration information is in $ac_config_dir)
+      ac_sub_configure=
+    fi
+
+    # The recursion is here.
+    if test -n "$ac_sub_configure"; then
+
+      # Make the cache file name correct relative to the subdirectory.
+      case "$cache_file" in
+      /*) ac_sub_cache_file=$cache_file ;;
+      *) # Relative path.
+        ac_sub_cache_file="$ac_dots$cache_file" ;;
+      esac
+ifdef([AC_PROVIDE_AC_PROG_INSTALL],
+      [  case "$ac_given_INSTALL" in
+changequote(, )dnl
+        [/$]*) INSTALL="$ac_given_INSTALL" ;;
+changequote([, ])dnl
+        *) INSTALL="$ac_dots$ac_given_INSTALL" ;;
+        esac
+])dnl
+
+      echo "[running ${CONFIG_SHELL-/bin/sh} $ac_sub_configure $ac_sub_configure_args --cache-file=$ac_sub_cache_file] --srcdir=$ac_sub_srcdir"
+      # The eval makes quoting arguments work.
+      if eval ${CONFIG_SHELL-/bin/sh} $ac_sub_configure $ac_sub_configure_args --cache-file=$ac_sub_cache_file --srcdir=$ac_sub_srcdir
+      then :
+      else
+        AC_MSG_ERROR($ac_sub_configure failed for $ac_config_dir)
+      fi
+    fi
+
+    cd $ac_popdir
+  done
+fi
+])
