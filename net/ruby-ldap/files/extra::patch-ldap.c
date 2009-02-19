--- ldap.c.orig	2009-02-19 21:53:02.000000000 +0300
+++ ldap.c	2009-02-19 21:53:58.000000000 +0300
@@ -420,8 +420,20 @@
 #ifdef LDAP_OPT_X_TLS
   rb_ldap_define_opt (LDAP_OPT_X_TLS);
 #endif
-#ifdef LDAP_OPT_X_TLS_PROTOCOL
-  rb_ldap_define_opt (LDAP_OPT_X_TLS_PROTOCOL);
+#ifdef LDAP_OPT_X_TLS_PROTOCOL_SSL2
+  rb_ldap_define_opt (LDAP_OPT_X_TLS_PROTOCOL_SSL2);
+#endif
+#ifdef LDAP_OPT_X_TLS_PROTOCOL_SSL3
+  rb_ldap_define_opt (LDAP_OPT_X_TLS_PROTOCOL_SSL3);
+#endif
+#ifdef LDAP_OPT_X_TLS_PROTOCOL_TLS1_0
+  rb_ldap_define_opt (LDAP_OPT_X_TLS_PROTOCOL_TLS1_0);
+#endif
+#ifdef LDAP_OPT_X_TLS_PROTOCOL_TLS1_1
+  rb_ldap_define_opt (LDAP_OPT_X_TLS_PROTOCOL_TLS1_1);
+#endif
+#ifdef LDAP_OPT_X_TLS_PROTOCOL_TLS1_2
+  rb_ldap_define_opt (LDAP_OPT_X_TLS_PROTOCOL_TLS1_2);
 #endif
 #ifdef LDAP_OPT_X_TLS_CIPHER_SUITE
   rb_ldap_define_opt (LDAP_OPT_X_TLS_CIPHER_SUITE);
