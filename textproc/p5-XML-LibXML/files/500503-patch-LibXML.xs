--- LibXML.xs.orig	Sun May 16 19:56:30 2004
+++ LibXML.xs	Sun May 16 19:57:29 2004
@@ -75,6 +75,19 @@
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
 static SV * LibXML_match_cb = NULL;
 static SV * LibXML_read_cb  = NULL;
 static SV * LibXML_open_cb  = NULL;
