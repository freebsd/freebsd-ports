--- Xvnc/programs/Xserver/cfb/stipsparc.s.orig	Wed Mar 24 16:34:12 2004
+++ Xvnc/programs/Xserver/cfb/stipsparc.s	Wed Mar 24 16:34:49 2004
@@ -85,7 +85,7 @@
 #define ForEachBits	LY4
 #define NextBits	LY5
 
-#ifdef SVR4
+#if defined(SVR4) || defined(__ELF__)
 #ifdef TETEXT
 #define	_cfbStippleStack	cfbStippleStackTE
 #else
