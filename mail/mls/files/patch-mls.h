--- mls.h.orig	2003-06-02 11:26:34 UTC
+++ mls.h
@@ -75,6 +75,9 @@
 #define EXIT_NOMEM  4
 #define EXIT_REGEX  5
 
+// because we must specify it when 2dimensional array is passed to function
+#define SNUMB_LEN   4
+
 /* *** structures for BEST messages *** */
 typedef struct bestQUOTE* nQptr;
 struct bestQUOTE {
@@ -104,7 +107,7 @@ struct bestTEXT {
 };
 
 // Reg. expressions
-regex_t r_from, r_time, r_re, r_date, r_dow, r_mail,
+extern regex_t r_from, r_time, r_re, r_date, r_dow, r_mail,
         r_m_ims, r_m_bat, r_m_lot, r_m_oue, r_m_ouc, r_m_oum, r_m_out,
 	r_m_cal, r_m_moz, r_m_peg, r_m_eud, r_m_ope, r_m_opw, r_m_pos,
 	r_m_pob, r_m_kma, r_m_imp, r_m_mut, r_m_pin, r_m_pi2, r_m_syl,
