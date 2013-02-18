--- ./dynconfig/config.m4.orig	2012-10-02 08:38:44.000000000 +0000
+++ ./dynconfig/config.m4	2013-01-27 07:13:46.156404375 +0000
@@ -60,6 +60,22 @@
 	PRIVILEGED_SOCKET_DIR="\${localstatedir}/lib/samba"
 fi
 
+AC_ARG_WITH(pkgconfigdir,
+[AS_HELP_STRING([--with-pkgconfigdir=DIR],
+ [Which directory to use for .pc files ($libdir/pkgconfig)])],
+[ case "$withval" in
+  yes|no)
+  #
+  # Just in case anybody calls it without argument
+  #
+    AC_MSG_WARN([--with-pkgconfigdir called without argument - will use default])
+  ;;
+  * )
+    PKGCONFIGDIR="$withval"
+  ;;
+  esac])
+
+
 AC_ARG_WITH(modulesdir,
 [AS_HELP_STRING([--with-modulesdir=DIR],
  [Which directory to use for modules ($exec_prefix/modules)])],
@@ -261,7 +277,7 @@
 NMBDSOCKETDIR="${SOCKET_DIR}/nmbd"
 NTP_SIGND_SOCKET_DIR="${SOCKET_DIR}/ntp_signd"
 NCALRPCDIR="${SOCKET_DIR}/ncalrpc"
-CONFIGFILE="${CONFIGDIR}/smb.conf"
+CONFIGFILE="${CONFIGDIR}/%%SAMBA4_CONFIG%%"
 LMHOSTSFILE="${CONFIGDIR}/lmhosts"
 SMB_PASSWD_FILE="${PRIVATE_DIR}/smbpasswd"
 
