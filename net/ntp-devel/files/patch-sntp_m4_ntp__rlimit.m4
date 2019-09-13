--- sntp/m4/ntp_rlimit.m4.orig	2015-09-23 04:49:10.000000000 -0700
+++ sntp/m4/ntp_rlimit.m4	2019-09-11 20:36:17.291424000 -0700
@@ -112,7 +112,7 @@
  yes | no)
     ans=$ntp_dflt_rlimit_memlock
     ;;
- [[1-9]][[0-9]]*) ;;
+ [[1-9]][[0-9]]*|-1) ;;
  *) AC_MSG_ERROR(["--with-memlock requires an integer argument."])
      ;;
 esac
