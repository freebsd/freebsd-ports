--- xpcom/reflect/xptcall/public/xptcstubsdecl.inc.orig	Sun Jul 20 11:45:41 2003
+++ xpcom/reflect/xptcall/public/xptcstubsdecl.inc	Sun Jul 20 11:49:09 2003
@@ -8,7 +8,7 @@
 *  1 is AddRef
 *  2 is Release
 */
-#if !defined(__ia64) || (!defined(__hpux) && !defined(__linux__))
+#if !defined(__ia64)
 XPTC_EXPORT NS_IMETHOD Stub3();
 XPTC_EXPORT NS_IMETHOD Stub4();
 XPTC_EXPORT NS_IMETHOD Stub5();
