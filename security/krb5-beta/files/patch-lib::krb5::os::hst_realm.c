--- lib/krb5/os/hst_realm.c.orig	Tue Oct 15 15:51:50 2002
+++ lib/krb5/os/hst_realm.c	Sat Jan 24 20:11:05 2004
@@ -438,9 +438,11 @@
 	return EAFNOSUPPORT;
     case EAI_MEMORY:
 	return ENOMEM;
+#ifdef EAI_NODATA
 #if EAI_NODATA != EAI_NONAME
     case EAI_NODATA:
 	return KRB5_EAI_NODATA;
+#endif
 #endif
     case EAI_NONAME:
 	return KRB5_EAI_NONAME;
