--- src/.mkmed-data/src/prjlibs-include/diewarn.h.orig	2023-04-05 00:31:59 UTC
+++ src/.mkmed-data/src/prjlibs-include/diewarn.h
@@ -1,14 +1,14 @@
 #ifndef PACKAGE__PROG__PRJLIBS__DIEWARN_H
 #define PACKAGE__PROG__PRJLIBS__DIEWARN_H
 
-#define DIE1X(status,x0)          strerr_die3x((status),PROG,": ",(x0))
-#define DIE2X(status,x0,x1)       strerr_die4x((status),PROG,": ",(x0),(x1))
-#define DIE3X(status,x0,x1,x2)    strerr_die5x((status),PROG,": ",(x0),(x1),\
+#define DIE1X(status,x0)          strerr_die((status),PROG,": ",(x0))
+#define DIE2X(status,x0,x1)       strerr_die((status),PROG,": ",(x0),(x1))
+#define DIE3X(status,x0,x1,x2)    strerr_die((status),PROG,": ",(x0),(x1),\
                                                (x2))
-#define DIE4X(status,x0,x1,x2,x3) strerr_die6x((status),PROG,": ",(x0),(x1),\
+#define DIE4X(status,x0,x1,x2,x3) strerr_die((status),PROG,": ",(x0),(x1),\
                                                (x2),(x3))
 
-#define DIE_USAGE(x0) strerr_die3x(100, "usage: ", PROG, x0)
+#define DIE_USAGE(x0) strerr_dien(100, 3, "usage: ", PROG, x0)
 #define DIE_OVERFLOW() DIE1X(100, "arithmetic overflow")
 #define DIE_NOTSET(x0) DIE2X(100, "variable not set: ", (x0))
 #define DIE_MALFORMED(x0, x1) DIE4X(100, "malformed ", (x0), ": ", (x1))
@@ -76,17 +76,17 @@
 #define WARNTEXT1(op) WARNTEXT_unable(1, op) " "
 #define WARNTEXT2(op) WARNTEXT_unable(2, op) " "
 
-#define WARN0(op)       strerr_warn2sys(PROG, WARNTEXT0(WARNTEXT0_##op))
-#define WARN1(op,x0)    strerr_warn4sys(PROG, WARNTEXT1(WARNTEXT1_##op), \
+#define WARN0(op)       strerr_warnsys(PROG, WARNTEXT0(WARNTEXT0_##op))
+#define WARN1(op,x0)    strerr_warnsys(PROG, WARNTEXT1(WARNTEXT1_##op), \
                                         (x0), ": ")
-#define WARN2(op,x0,x1) strerr_warn6sys(PROG, WARNTEXT2(WARNTEXT2_##op), \
+#define WARN2(op,x0,x1) strerr_warnsys(PROG, WARNTEXT2(WARNTEXT2_##op), \
                                         (x0), WARNSEP2_##op, (x1), ": ")
 
-#define DIE0(op)       strerr_die2sys(DIESTAT(#op), PROG, \
+#define DIE0(op)       strerr_diesys(DIESTAT(#op), PROG, \
                                       WARNTEXT0(WARNTEXT0_##op))
-#define DIE1(op,x0)    strerr_die4sys(DIESTAT(#op), PROG, \
+#define DIE1(op,x0)    strerr_diesys(DIESTAT(#op), PROG, \
                                       WARNTEXT1(WARNTEXT1_##op), (x0), ": ")
-#define DIE2(op,x0,x1) strerr_die6sys(DIESTAT(#op), PROG, \
+#define DIE2(op,x0,x1) strerr_diesys(DIESTAT(#op), PROG, \
                                       WARNTEXT2(WARNTEXT2_##op), (x0),\
                                       WARNSEP2_##op, (x1), ": ")
 
