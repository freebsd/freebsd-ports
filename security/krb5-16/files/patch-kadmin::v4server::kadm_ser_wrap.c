--- kadmin/v4server/kadm_ser_wrap.c.orig	Tue May 23 14:44:50 2000
+++ kadmin/v4server/kadm_ser_wrap.c	Wed Oct 23 15:15:24 2002
@@ -170,14 +170,21 @@
     u_char *retdat, *tmpdat;
     int retval, retlen;
 
-    if (strncmp(KADM_VERSTR, (char *)*dat, KADM_VERSIZE)) {
+    if ((*dat_len < KADM_VERSIZE + sizeof(krb5_ui_4))
+	|| strncmp(KADM_VERSTR, (char *)*dat, KADM_VERSIZE)) {
 	errpkt(dat, dat_len, KADM_BAD_VER);
 	return KADM_BAD_VER;
     }
     in_len = KADM_VERSIZE;
     /* get the length */
-    if ((retc = stv_long(*dat, &r_len, in_len, *dat_len)) < 0)
+    if ((retc = stv_long(*dat, &r_len, in_len, *dat_len)) < 0
+	|| (r_len > *dat_len - KADM_VERSIZE - sizeof(krb5_ui_4))
+	|| (*dat_len - r_len - KADM_VERSIZE -
+	    sizeof(krb5_ui_4) > sizeof(authent.dat))) {
+	errpkt(dat, dat_len, KADM_LENGTH_ERROR);
 	return KADM_LENGTH_ERROR;
+    }
+
     in_len += retc;
     authent.length = *dat_len - r_len - KADM_VERSIZE - sizeof(krb5_ui_4);
     memcpy((char *)authent.dat, (char *)(*dat) + in_len, authent.length);
