--- acinclude.m4.orig	2010-09-10 23:36:43.000000000 +0200
+++ acinclude.m4	2011-11-02 07:09:19.000000000 +0100
@@ -220,6 +220,18 @@
                 [Define to 1 if net/if_packet.h is available.])
    fi])
 
+dnl Checks for net/if_dl.h.
+AC_DEFUN([OVS_CHECK_IF_DL],
+  [AC_CHECK_HEADER([net/if_dl.h],
+                   [HAVE_IF_DL=yes],
+                   [HAVE_IF_DL=no])
+   AM_CONDITIONAL([HAVE_IF_DL], [test "$HAVE_IF_DL" = yes])
+   if test "$HAVE_IF_DL" = yes; then
+      AC_SEARCH_LIBS([pcap_create], [pcap])
+      AC_DEFINE([HAVE_IF_DL], [1],
+                [Define to 1 if net/if_dl.h is available.])
+   fi])
+
 dnl Checks for buggy strtok_r.
 dnl
 dnl Some versions of glibc 2.7 has a bug in strtok_r when compiling
