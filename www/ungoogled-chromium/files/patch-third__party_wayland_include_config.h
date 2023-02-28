--- third_party/wayland/include/config.h.orig	2023-02-28 09:34:10 UTC
+++ third_party/wayland/include/config.h
@@ -9,7 +9,11 @@
 
 #define HAVE_BROKEN_MSG_CMSG_CLOEXEC 0
 
+#if __FreeBSD__version > 1300000
 #define HAVE_MEMFD_CREATE
+#else
+#undef HAVE_MEMFD_CREATE
+#endif
 
 #define HAVE_MKOSTEMP
 
@@ -25,7 +29,11 @@
 
 #undef HAVE_SYS_PROCCTL_H
 
+#if defined(__FreeBSD__)
+#define HAVE_SYS_UCRED_H
+#else
 #undef HAVE_SYS_UCRED_H
+#endif
 
 #define HAVE_XUCRED_CR_PID 0
 
