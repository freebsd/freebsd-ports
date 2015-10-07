--- modules/app_perl/kamailioxs.xs.orig	2015-07-20 13:16:25 UTC
+++ modules/app_perl/kamailioxs.xs
@@ -402,7 +402,7 @@ char *pv_sprintf(struct sip_msg *m, char
  * - strflag: flag mask to be or-applied for string match
  */
 
-inline int sv2int_str(SV *val, int_str *is,
+static inline int sv2int_str(SV *val, int_str *is,
 		      unsigned short *flags, unsigned short strflag) {
 	char *s;
 	STRLEN len;
