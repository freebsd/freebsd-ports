--- Xvnc/programs/Xserver/cfb/stipsprc32.s.orig	Thu Mar 25 10:28:07 2004
+++ Xvnc/programs/Xserver/cfb/stipsprc32.s	Thu Mar 25 10:29:02 2004
@@ -81,7 +81,7 @@
 #define ForEachBits	LY4
 #define NextBits	LY5
 
-#ifdef SVR4
+#if defined(SVR4) || defined(__ELF__)
 #ifdef TETEXT
 #define	_cfb32StippleStack	cfb32StippleStackTE
 #else
