--- xpcom/reflect/xptcall/public/xptcstubsdecl.inc.orig	Sun Feb  1 15:39:59 2004
+++ xpcom/reflect/xptcall/public/xptcstubsdecl.inc	Sun Feb  1 15:40:11 2004
@@ -8,7 +8,7 @@
 *  1 is AddRef
 *  2 is Release
 */
-#if !defined(__ia64) || (!defined(__hpux) && !defined(__linux__))
+#if !defined(__ia64)
 XPTC_EXPORT NS_IMETHOD Stub3();
 XPTC_EXPORT NS_IMETHOD Stub4();
 XPTC_EXPORT NS_IMETHOD Stub5();
