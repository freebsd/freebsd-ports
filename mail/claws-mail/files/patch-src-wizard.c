Index: src/wizard.c
===================================================================
RCS file: //claws/src/Attic/wizard.c,v
retrieving revision 1.1.2.83
retrieving revision 1.1.2.84
diff -u -r1.1.2.83 -r1.1.2.84
--- src/wizard.c	2 Mar 2011 21:23:38 -0000	1.1.2.83
+++ src/wizard.c	3 Jul 2011 17:24:06 -0000	1.1.2.84
@@ -1253,8 +1253,8 @@
 	GtkWidget *hbox;
 	GtkWidget *hbox_spc;
 	GtkWidget *smtp_auth_table;
-#ifdef USE_GNUTLS
 	GtkWidget *label;
+#ifdef USE_GNUTLS
 	GtkWidget *button;
 	GtkWidget *smtp_cert_table;
 #endif

