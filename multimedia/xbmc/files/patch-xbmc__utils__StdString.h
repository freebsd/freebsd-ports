--- ./xbmc/utils/StdString.h.orig	2011-12-23 04:12:21.000000000 +0100
+++ ./xbmc/utils/StdString.h	2012-01-02 10:14:38.000000000 +0100
@@ -864,7 +864,7 @@
       PWSTR pNextDstW      = pDstW;
       SSCodeCvt::result res  = SSCodeCvt::ok;
       const SSCodeCvt& conv  = SS_USE_FACET(loc, SSCodeCvt);
-#if defined(TARGET_DARWIN)
+#if defined(TARGET_DARWIN) || defined(__FreeBSD__)
       SSCodeCvt::state_type st= { { 0 } };
 #else
       SSCodeCvt::state_type st= { 0 };
@@ -911,7 +911,7 @@
       PCWSTR pNextSrcW    = pSrcW;
       SSCodeCvt::result res  = SSCodeCvt::ok;
       const SSCodeCvt& conv  = SS_USE_FACET(loc, SSCodeCvt);
-#if defined(TARGET_DARWIN)
+#if defined(TARGET_DARWIN) || defined(__FreeBSD__)
       SSCodeCvt::state_type st= { { 0 } };
 #else
       SSCodeCvt::state_type st= { 0 };
