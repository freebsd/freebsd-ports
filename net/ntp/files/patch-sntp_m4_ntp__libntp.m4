--- sntp/m4/ntp_libntp.m4.orig	2017-02-01 09:47:13 UTC
+++ sntp/m4/ntp_libntp.m4
@@ -693,7 +693,28 @@ esac
 
 AC_MSG_RESULT([$ntp_have_solarisprivs])
 
-case "$ntp_use_dev_clockctl$ntp_have_linuxcaps$ntp_have_solarisprivs" in
+AC_CHECK_HEADERS([sys/mac.h])
+
+AC_ARG_ENABLE(
+    [trustedbsd_mac],
+    [AS_HELP_STRING(
+	[--enable-trustedbsd-mac],
+	[- Use TrustedBSD MAC policy for non-root clock control]
+    )],
+    [ntp_use_trustedbsd_mac=$enableval]
+)
+
+AC_MSG_CHECKING([if we should use TrustedBSD MAC privileges])
+
+case "$ntp_use_trustedbsd_mac$ac_cv_header_sys_mac_h" in
+ yesyes)
+    AC_DEFINE([HAVE_TRUSTEDBSD_MAC], [1],
+	[Are TrustedBSD MAC policy privileges available?])
+esac
+
+AC_MSG_RESULT([$ntp_use_trustedbsd_mac])
+
+case "$ntp_use_dev_clockctl$ntp_have_linuxcaps$ntp_have_solarisprivs$ntp_use_trustedbsd_mac" in
  *yes*)
     AC_DEFINE([HAVE_DROPROOT], [1],
 	[Can we drop root privileges?])
