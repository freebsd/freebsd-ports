--- lib/krb5/os/locate_kdc.c.orig	Mon Jun  9 14:27:56 2003
+++ lib/krb5/os/locate_kdc.c	Sun Jan 25 13:28:01 2004
@@ -185,8 +185,10 @@
 #ifdef EAI_ADDRFAMILY
     case EAI_ADDRFAMILY:
 #endif
+#ifdef EAI_NODATA
 #if EAI_NODATA != EAI_NONAME
     case EAI_NODATA:
+#endif
 #endif
     case EAI_NONAME:
 	/* Name not known or no address data, but no error.  Do
