--- callbacks.c.orig	2000-07-19 06:20:36 UTC
+++ callbacks.c
@@ -31,8 +31,8 @@
 /* Macro for pushing the SMFICTX * argument */
 
 #define XPUSHs_Sendmail_Milter_Context	\
-	(XPUSHs(sv_2mortal(sv_setref_iv(NEWSV(25, 0), \
-		"Sendmail::Milter::Context", (IV) ctx))))
+	XPUSHs(sv_2mortal(sv_setref_iv(NEWSV(25, 0), \
+		"Sendmail::Milter::Context", (IV) ctx)))
 
 /* Global callback variable names */
 
@@ -489,6 +489,11 @@ callback_ssockaddr(pTHX_ SV *callback, SMFICTX *ctx, c
 	{
 		XPUSHs(sv_2mortal(newSVpvn((char *)arg_sa,
 					   sizeof(_SOCK_ADDR))));
+	}
+	else if (arg_sa->sa_family == AF_INET6)
+	{
+		XPUSHs(sv_2mortal(newSVpvn((char *)arg_sa,
+				   sizeof(struct sockaddr_in6))));
 	}
 	else
 	{
