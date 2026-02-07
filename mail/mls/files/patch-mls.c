--- mls.c.orig	2003-05-27 21:47:26 UTC
+++ mls.c
@@ -51,6 +51,16 @@ time_t t;          // actual time - to be added to out
 time_t t_oldest,
        t_newest;   // date of oldest/newest message found
 
+// Reg. expressions
+regex_t r_from, r_time, r_re, r_date, r_dow, r_mail,
+        r_m_ims, r_m_bat, r_m_lot, r_m_oue, r_m_ouc, r_m_oum, r_m_out,
+        r_m_cal, r_m_moz, r_m_peg, r_m_eud, r_m_ope, r_m_opw, r_m_pos,
+        r_m_pob, r_m_kma, r_m_imp, r_m_mut, r_m_pin, r_m_pi2, r_m_syl,
+        r_m_pan, r_m_4td, r_m_fag, r_m_mpg, r_m_xws, r_m_knd, r_m_hst,
+        r_m_nnr;
+
+regex_t r_qp, r_base64, r_hex;
+
 /* ************************************************* Other * FUNCTIONS *** */
 /* ***** banner ********************************************************** */
 void banner() { // print greeting banner
