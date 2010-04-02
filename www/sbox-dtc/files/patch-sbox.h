--- sbox.h.orig	2005-12-05 23:00:27.000000000 +0200
+++ sbox.h	2010-03-18 19:42:17.032943014 +0200
@@ -1,4 +1,15 @@
 /*
+ * patch by Aldis Berjoza <aldis@bsdroot.lv> 2010-03-18
+ * This will define UID_MAX and GID_MAX macros to match FreeBSD
+ */
+#ifndef __BSD_VISIBLE
+#define __BSD_VISIBLE
+#endif
+#ifndef _SYS_LIMITS_H_
+#include <sys/limits.h>
+#endif
+
+/*
  * sbox.h -- definitions for the script box
  * Copyright 1997-1998, Lincoln D. Stein
  * $Revision: 1.11 $
