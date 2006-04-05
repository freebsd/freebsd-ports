--- src/acl.c.orig	Tue Apr  4 16:00:04 2006
+++ src/acl.c	Wed Apr  5 20:39:34 2006
@@ -1,4 +1,4 @@
-/* $Cambridge: exim/exim-src/src/acl.c,v 1.57 2006/03/06 16:05:12 ph10 Exp $ */
+/* $Cambridge: exim/exim-src/src/acl.c,v 1.58 2006/04/04 17:05:45 fanf2 Exp $ */
 
 /*************************************************
 *     Exim - an Internet mail transport agent    *
@@ -202,8 +202,8 @@
 checking functions. */
 
 static uschar cond_expand_at_top[] = {
-  TRUE,    /* add_header */
   TRUE,    /* acl */
+  TRUE,    /* add_header */
   FALSE,   /* authenticated */
 #ifdef EXPERIMENTAL_BRIGHTMAIL
   TRUE,    /* bmi_optin */
@@ -260,8 +260,8 @@
 /* Flags to identify the modifiers */
 
 static uschar cond_modifiers[] = {
-  TRUE,    /* add_header */
   FALSE,   /* acl */
+  TRUE,    /* add_header */
   FALSE,   /* authenticated */
 #ifdef EXPERIMENTAL_BRIGHTMAIL
   TRUE,    /* bmi_optin */
