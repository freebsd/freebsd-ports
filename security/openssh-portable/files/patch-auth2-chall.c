--- auth2-chall.c.orig	Wed Jun 26 15:58:40 2002
+++ auth2-chall.c	Sun Jun 30 07:12:43 2002
@@ -41,6 +42,9 @@
 #ifdef BSD_AUTH
 extern KbdintDevice bsdauth_device;
 #else
+#ifdef USE_PAM
+extern KbdintDevice pam_device;
+#endif
 #ifdef SKEY
 extern KbdintDevice skey_device;
 #endif
@@ -50,6 +54,9 @@
 #ifdef BSD_AUTH
 	&bsdauth_device,
 #else
+#ifdef USE_PAM
+	&pam_device,
+#endif
 #ifdef SKEY
 	&skey_device,
 #endif
@@ -323,15 +330,22 @@
 #ifdef BSD_AUTH
 	extern KbdintDevice mm_bsdauth_device;
 #endif
+#ifdef USE_PAM
+	extern KbdintDevice mm_pam_device;
+#endif
 #ifdef SKEY
 	extern KbdintDevice mm_skey_device;
 #endif
-	/* As long as SSHv1 has devices[0] hard coded this is fine */
+	int n = 0;
+
 #ifdef BSD_AUTH
-	devices[0] = &mm_bsdauth_device;
+	devices[n++] = &mm_bsdauth_device;
 #else
+#ifdef USE_PAM
+	devices[n++] = &mm_pam_device;
+#endif
 #ifdef SKEY
-	devices[0] = &mm_skey_device;
+	devices[n++] = &mm_skey_device;
 #endif
 #endif
 }
