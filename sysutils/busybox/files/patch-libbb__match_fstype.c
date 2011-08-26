--- ./libbb/match_fstype.c.orig	2011-08-11 02:23:58.000000000 +0200
+++ ./libbb/match_fstype.c	2011-08-26 02:10:16.000000000 +0200
@@ -10,6 +10,8 @@
  * Licensed under GPLv2 or later, see file LICENSE in this source tree.
  */
 
+#ifdef HAVE_MNTENT_H
+
 #include "libbb.h"
 
 int FAST_FUNC match_fstype(const struct mntent *mt, const char *t_fstype)
@@ -40,3 +42,5 @@
 
 	return !match;
 }
+
+#endif /* HAVE_MNTENT_H */
