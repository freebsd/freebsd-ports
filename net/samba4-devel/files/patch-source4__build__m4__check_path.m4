--- ./source4/build/m4/check_path.m4.orig	2010-01-11 05:35:28.000000000 +0000
+++ ./source4/build/m4/check_path.m4	2010-01-24 21:49:26.000000000 +0000
@@ -19,6 +19,7 @@
 piddir="${localstatedir}/run"
 privatedir="\${prefix}/private"
 modulesdir="\${prefix}/modules"
+ncalrpcdir ="\${localstatedir}/ncalrpc"
 winbindd_socket_dir="${localstatedir}/run/winbindd"
 winbindd_privileged_socket_dir="${localstatedir}/lib/winbindd_privileged"
 ntp_signd_socket_dir="${localstatedir}/run/ntp_signd"
@@ -41,11 +42,6 @@
     ntp_signd_socket_dir="${localstatedir}/run/samba/ntp_signd"
     winbindd_socket_dir="${localstatedir}/run/samba/winbindd"
     winbindd_privileged_socket_dir="${localstatedir}/lib/samba/winbindd_privileged"
-else
-	# Check to prevent installing directly under /usr without the FHS
-	AS_IF([test $prefix = /usr || test $prefix = /usr/local],[
-		AC_MSG_ERROR([Don't install directly under "/usr" or "/usr/local" without using the FHS option (--enable-fhs). This could lead to file loss!])
-	])
 fi
 
 #################################################
@@ -81,6 +77,22 @@
   esac])
 
 #################################################
+# set where the ncalrpc sockets should be put
+AC_ARG_WITH(ncalrpcdir,
+[AS_HELP_STRING([--with-ncalrpcdir=DIR],[Where to put the ncalrpc sockets ($ncalrpcdir)])],
+[ case "$withval" in
+  yes|no)
+  #
+  # Just in case anybody calls it without argument
+  #
+    AC_MSG_WARN([--with-ncalrpcdir called without argument - will use default])
+  ;;
+  * )
+    ncalrpcdir="$withval"
+    ;;
+  esac])
+
+#################################################
 # set where the winbindd socket should be put
 AC_ARG_WITH(winbindd-socket-dir,
 [AS_HELP_STRING([--with-winbindd-socket-dir=DIR],[Where to put the winbindd socket ($winbindd_socket_dir)])],
@@ -187,6 +199,7 @@
 AC_SUBST(winbindd_privileged_socket_dir)
 AC_SUBST(ntp_signd_socket_dir)
 AC_SUBST(modulesdir)
+AC_SUBST(ncalrpcdir)
 
 #################################################
 # set prefix for 'make test'
