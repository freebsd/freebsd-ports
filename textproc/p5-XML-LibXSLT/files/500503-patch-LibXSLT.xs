--- LibXSLT.xs.orig	Mon Mar  1 21:42:43 2004
+++ LibXSLT.xs	Sun May 16 20:21:57 2004
@@ -29,6 +29,23 @@
 }
 #endif
 
+#ifndef dTHX
+#define dTHX	extern int errno
+#endif
+
+#ifndef SvPV_nolen
+#define SvPV_nolen(sv) \
+        ((SvFLAGS(sv) & (SVf_POK)) == SVf_POK \
+         ? SvPVX(sv) : sv_2pv_nolen(sv))
+
+static char *
+sv_2pv_nolen(register SV *sv)
+{   
+	STRLEN n_a;
+	return sv_2pv(sv, &n_a);
+}
+#endif
+
 #define SET_CB(cb, fld) \
     RETVAL = cb ? newSVsv(cb) : &PL_sv_undef;\
     if (SvOK(fld)) {\
