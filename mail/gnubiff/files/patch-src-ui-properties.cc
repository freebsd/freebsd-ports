--- src/ui-properties.cc.orig	Tue Feb  8 00:02:37 2005
+++ src/ui-properties.cc	Wed Apr  6 00:40:23 2005
@@ -594,7 +594,7 @@
 #ifndef HAVE_LIBSSL
 	if ((auth == AUTH_SSL) || (auth == AUTH_CERTIFICATE))
 #  ifdef HAVE_CRYPTO
-		if (selected_type == TYPE_POP)
+		if (selected_type_ == TYPE_POP)
 			auth = AUTH_APOP;
 #  else
 		auth = AUTH_USER_PASS;
