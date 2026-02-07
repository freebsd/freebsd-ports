--- SUMA/gts/src/rounding.h.orig	2021-10-21 01:05:53 UTC
+++ SUMA/gts/src/rounding.h
@@ -34,9 +34,14 @@
 #  endif /* not FPU_EXTENDED */
 #else /* not HAVE_FPU_CONTROL_H */
 #  ifdef __FreeBSD__
-#    include <floatingpoint.h>
-#    define FPU_ROUND_DOUBLE  (fpsetprec(FP_PD))
-#    define FPU_RESTORE       (fpsetprec(FP_PE))
+#    if defined(__amd64__) || defined(__i386__)
+#      include <floatingpoint.h>
+#      define FPU_ROUND_DOUBLE  (fpsetprec(FP_PD))
+#      define FPU_RESTORE       (fpsetprec(FP_PE))
+#    else /* not amd64 or i386 */
+#      define FPU_ROUND_DOUBLE
+#      define FPU_RESTORE
+#    endif
 #  else /* not __FreeBSD__ */
 #    ifdef WIN32
 #      ifdef _MSC_VER
