--- configure.ac.orig	2018-12-22 21:11:52.861640000 +0100
+++ configure.ac	2018-12-22 21:11:58.730593000 +0100
@@ -34,6 +34,7 @@
 AC_SUBST(LIBAVAHI_GOBJECT_VERSION_INFO, [0:5:0])
 AC_SUBST(LIBAVAHI_QT3_VERSION_INFO, [1:2:0])
 AC_SUBST(LIBAVAHI_QT4_VERSION_INFO, [1:2:0])
+AC_SUBST(LIBAVAHI_QT5_VERSION_INFO, [1:2:0])
 AC_SUBST(LIBAVAHI_UI_VERSION_INFO, [1:4:1])
 
 # Do not touch these, since they we took this version-info from upstream HOWL/Bonjour
@@ -526,6 +527,32 @@
 AM_CONDITIONAL(HAVE_QT4, test "x$HAVE_QT4" = "xyes")
 
 #
+# Check for Qt 5
+#
+AC_ARG_ENABLE(qt5,
+        AS_HELP_STRING([--disable-qt5],[Disable building of Qt5Core mainloop integration]),
+        [case "${enableval}" in
+                yes) HAVE_QT5=yes ;;
+                no)  HAVE_QT5=no ;;
+                *) AC_MSG_ERROR(bad value ${enableval} for --enable-qt5) ;;
+        esac],
+        [HAVE_QT5=yes])
+
+if test "x$HAVE_QT5" = "xyes" ; then
+        PKG_CHECK_MODULES( QT5, [ Qt5Core >= 5.0.0 ])
+        AC_AVAHI_QT_ADD_PIC_IF_NEEDED
+        AC_SUBST(QT5_CFLAGS)
+        AC_SUBST(QT5_LIBS)
+        QT5_PREFIX="`$PKG_CONFIG --variable=host_bins Qt5Core`"
+        AC_PATH_PROGS(MOC_QT5, [moc-qt5 moc], no, [$QT5_PREFIX])
+        if test "$MOC_QT5" = no; then
+            AC_MSG_ERROR([Could not find QT5 moc])
+        fi
+        AC_SUBST(MOC_QT5)
+fi
+AM_CONDITIONAL(HAVE_QT5, test "x$HAVE_QT5" = "xyes")
+
+#
 # Check for GTK+ 2.0
 #
 AC_ARG_ENABLE(gtk,
@@ -1158,6 +1185,7 @@
     Enable python-dbus:                        ${HAVE_PYTHON_DBUS}
     Enable QT3:                                ${HAVE_QT3}
     Enable QT4:                                ${HAVE_QT4}
+    Enable QT5:                                ${HAVE_QT5}
     Enable Mono:                               ${HAVE_MONO}
     Enable Monodoc:                            ${HAVE_MONODOC}
     Distribution/OS:                           ${with_distro}
@@ -1227,6 +1255,7 @@
     Building avahi-discover-standalone: ${HAVE_GTK2OR3}
     Building libavahi-qt3:              ${HAVE_QT3}
     Building libavahi-qt4:              ${HAVE_QT4}
+    Building libavahi-qt5:              ${HAVE_QT5}
     Building avahi-sharp:               ${HAVE_MONO}
     Building avahi-compat-libdns_sd:    ${ENABLE_COMPAT_LIBDNS_SD}
     Building avahi-compat-howl:         ${ENABLE_COMPAT_HOWL}
