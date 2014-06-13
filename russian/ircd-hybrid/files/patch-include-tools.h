--- include/tools.h.orig	2014-04-01 07:57:16.040161762 +0000
+++ include/tools.h	2014-04-01 07:58:16.339157016 +0000
@@ -91,7 +91,7 @@
 /* forte (and maybe others) dont like these being declared twice,
  * so we dont declare the inlines unless GNUC.
  */
-#ifdef __GNUC__
+#if defined(__GNUC__) && !defined(__clang__)
 
 /* 
  * dlink_ routines are stolen from squid, except for dlinkAddBefore,
