--- src/stty.c.orig	2007-03-18 14:36:43.000000000 -0700
+++ src/stty.c	2008-08-28 04:43:28.000000000 -0700
@@ -45,6 +45,13 @@
 #endif
 #ifdef HAVE_SYS_IOCTL_H
 # include <sys/ioctl.h>
+/*
+ * XXX - Workaround for missing TAB1 and TAB2 bits on 8.0-CURRENT;
+ *       available in src/ioctl_compat.h, only when _KERNEL is defined.
+ */
+# define _KERNEL
+# include <sys/ioctl_compat.h>
+# undef _KERNEL
 #endif
 
 #ifdef WINSIZE_IN_PTEM
