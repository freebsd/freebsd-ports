--- auth2-chall.c.orig	Wed Jun 19 02:27:55 2002
+++ auth2-chall.c	Wed Jun 26 16:59:05 2002
@@ -40,20 +40,20 @@
 
 #ifdef BSD_AUTH
 extern KbdintDevice bsdauth_device;
-#else
-#ifdef SKEY
+#elif defined(USE_PAM)
+extern KbdintDevice pam_device;
+#elif defined(SKEY)
 extern KbdintDevice skey_device;
 #endif
-#endif
 
 KbdintDevice *devices[] = {
 #ifdef BSD_AUTH
 	&bsdauth_device,
-#else
-#ifdef SKEY
+#elif defined(USE_PAM)
+	&pam_device,
+#elif defined(SKEY)
 	&skey_device,
 #endif
-#endif
 	NULL
 };
 
