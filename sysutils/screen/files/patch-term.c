--- term.c.orig	2019-10-01 15:08:00.000000000 -0700
+++ term.c	2019-10-28 19:37:41.585983000 -0700
@@ -197,6 +197,7 @@
   { "F1", T_STR  }, KMAPDEF("\033[23~")
   { "F2", T_STR  }, KMAPDEF("\033[24~")
   /* extra keys for vt220 (David.Leonard@it.uq.edu.au) */
+/* define T_FEXTRA */
   { "F3", T_STR  },
   { "F4", T_STR  },
   { "F5", T_STR  },
