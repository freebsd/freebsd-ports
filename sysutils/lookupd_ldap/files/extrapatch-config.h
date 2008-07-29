--- config.h.orig	2004-06-24 01:17:16.000000000 -0700
+++ config.h	2008-07-24 13:58:30.013821799 -0700
@@ -98,7 +98,7 @@
 #define HAVE_LDAP_CREATE_CONTROL 1
 
 /* Define to 1 if you have the `ldap_create_page_control' function. */
-/* #undef HAVE_LDAP_CREATE_PAGE_CONTROL */
+#define HAVE_LDAP_CREATE_PAGE_CONTROL
 
 /* Define to 1 if you have the `ldap_explode_rdn' function. */
 #define HAVE_LDAP_EXPLODE_RDN 1
@@ -125,7 +125,7 @@
 #define HAVE_LDAP_MEMFREE 1
 
 /* Define to 1 if you have the `ldap_parse_page_control' function. */
-/* #undef HAVE_LDAP_PARSE_PAGE_CONTROL */
+#define HAVE_LDAP_PARSE_PAGE_CONTROL
 
 /* Define to 1 if you have the `ldap_parse_result' function. */
 #define HAVE_LDAP_PARSE_RESULT 1
