
$FreeBSD$

--- ehnt.h.orig	Thu Oct  4 22:18:29 2001
+++ ehnt.h	Thu May 20 16:07:24 2004
@@ -93,7 +93,7 @@
 int ProcessFlow(struct flow_ver5_rec *, struct in_addr *, struct ehnt_struct *);
 int Init_ASN_Lookups(void);
 char * ASN_Lookup(int);
-char * prettybytes(int);
+char * prettybytes(unsigned);
 void DisplayReport(time_t, struct ehnt_data *);
 
 /* these EM_ defines are for the mode config variable */
