* Plumb the devd config backend into configure
*
* define USE_DEV_IO for ARM platforms
*
* Only run pkg-config for udev if it is not disabled to prevent over-linking
*
* Automatically use systemd/logind only on Linux
*
--- configure.ac.orig	2017-03-15 18:05:25 UTC
+++ configure.ac
@@ -266,9 +266,12 @@ case $host_cpu in
 	esac
 	GLX_ARCH_DEFINES="-D__GLX_ALIGN64 -mieee"
 	;;
-  arm*)
+  arm*|aarch64*)
 	ARM_VIDEO=yes
 	DEFAULT_INT10="stub"
+	case $host_os in
+		*freebsd*)	AC_DEFINE(USE_DEV_IO) ;;
+	esac
 	;;
   i*86)
 	I386_VIDEO=yes
@@ -565,6 +568,7 @@ AC_ARG_ENABLE(xcsecurity,     AS_HELP_ST
 AC_ARG_ENABLE(dbe,            AS_HELP_STRING([--disable-dbe], [Build DBE extension (default: enabled)]), [DBE=$enableval], [DBE=yes])
 AC_ARG_ENABLE(xf86bigfont,    AS_HELP_STRING([--enable-xf86bigfont], [Build XF86 Big Font extension (default: disabled)]), [XF86BIGFONT=$enableval], [XF86BIGFONT=no])
 AC_ARG_ENABLE(dpms,           AS_HELP_STRING([--disable-dpms], [Build DPMS extension (default: enabled)]), [DPMSExtension=$enableval], [DPMSExtension=yes])
+AC_ARG_ENABLE(config-devd,    AS_HELP_STRING([--enable-config-devd], [Build devd support (default: auto)]), [CONFIG_DEVD=$enableval], [CONFIG_DEVD=auto])
 AC_ARG_ENABLE(config-udev,    AS_HELP_STRING([--enable-config-udev], [Build udev support (default: auto)]), [CONFIG_UDEV=$enableval], [CONFIG_UDEV=auto])
 AC_ARG_ENABLE(config-udev-kms,    AS_HELP_STRING([--enable-config-udev-kms], [Build udev kms support (default: auto)]), [CONFIG_UDEV_KMS=$enableval], [CONFIG_UDEV_KMS=auto])
 AC_ARG_ENABLE(config-hal,     AS_HELP_STRING([--disable-config-hal], [Build HAL support (default: auto)]), [CONFIG_HAL=$enableval], [CONFIG_HAL=auto])
@@ -856,10 +860,27 @@ if test "x$CONFIG_UDEV" = xyes && test "
 	AC_MSG_ERROR([Hotplugging through both libudev and hal not allowed])
 fi
 
-PKG_CHECK_MODULES(UDEV, $LIBUDEV, [HAVE_LIBUDEV=yes], [HAVE_LIBUDEV=no])
-if test "x$CONFIG_UDEV" = xauto; then
-	CONFIG_UDEV="$HAVE_LIBUDEV"
-	AC_DEFINE(HAVE_LIBUDEV, 1, [Define to 1 if libudev is available.])
+if test "x$CONFIG_DEVD" = xauto; then
+	case $host_os in
+		*freebsd*)
+			CONFIG_DEVD=yes
+			;;
+		*)
+			CONFIG_DEVD=no
+			;;
+	esac
+fi
+AM_CONDITIONAL(CONFIG_DEVD, [test "x$CONFIG_DEVD" = xyes])
+if test "x$CONFIG_DEVD" = xyes; then
+	AC_DEFINE(CONFIG_DEVD, 1, [Use devd for input auto configuration])
+fi
+
+if test "x$CONFIG_UDEV" != xno; then
+	PKG_CHECK_MODULES(UDEV, $LIBUDEV, [HAVE_LIBUDEV=yes], [HAVE_LIBUDEV=no])
+	if test "x$CONFIG_UDEV" = xauto; then
+		CONFIG_UDEV="$HAVE_LIBUDEV"
+		AC_DEFINE(HAVE_LIBUDEV, 1, [Define to 1 if libudev is available.])
+	fi
 fi
 AM_CONDITIONAL(CONFIG_UDEV, [test "x$CONFIG_UDEV" = xyes])
 if test "x$CONFIG_UDEV" = xyes; then
@@ -907,7 +928,14 @@ AM_CONDITIONAL(CONFIG_HAL, [test "x$CONF
 
 if test "x$SYSTEMD_LOGIND" = xauto; then
         if test "x$HAVE_DBUS" = xyes -a "x$CONFIG_UDEV" = xyes ; then
-                SYSTEMD_LOGIND=yes
+            case $host_os in
+                *linux*)
+                        SYSTEMD_LOGIND=yes
+                        ;;
+                *)
+                        SYSTEMD_LOGIND=no
+                        ;;
+            esac
         else
                 SYSTEMD_LOGIND=no
         fi
@@ -2467,12 +2495,12 @@ AC_SUBST([prefix])
 
 AC_CONFIG_COMMANDS([sdksyms], [touch hw/xfree86/sdksyms.dep])
 
-if test "x$CONFIG_HAL" = xno && test "x$CONFIG_UDEV" = xno; then
+if test "x$CONFIG_HAL" = xno && test "x$CONFIG_UDEV" = xno && test "x$CONFIG_DEVD" = xno; then
     AC_MSG_WARN([
-             ***********************************************
-             Neither HAL nor udev backend will be enabled.
+             *****************************************************
+             Neither HAL, devd, nor udev backend will be enabled.
              Input device hotplugging will not be available!
-             ***********************************************])
+             *****************************************************])
 fi
 
 AC_CONFIG_FILES([
