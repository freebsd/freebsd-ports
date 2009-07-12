--- ./source4/build/m4/check_path.m4.orig	2009-06-19 04:36:48.000000000 +0000
+++ ./source4/build/m4/check_path.m4	2009-07-12 02:39:36.000000000 +0000
@@ -41,11 +41,6 @@
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
