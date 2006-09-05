--- LibXML.xs.orig	Sat Aug 26 20:36:44 2006
+++ LibXML.xs	Tue Sep  5 21:30:37 2006
@@ -74,6 +74,19 @@
 #define TEST_PERL_FLAG(flag) \
     SvTRUE(perl_get_sv(flag, FALSE)) ? 1 : 0
 
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
 /* this should keep the default */
 static xmlExternalEntityLoader LibXML_old_ext_ent_loader = NULL;
 
