--- Src/Zle/zle.h.orig	Tue May 23 17:20:57 2000
+++ Src/Zle/zle.h	Thu May  9 06:49:30 2002
@@ -194,3 +194,8 @@
 /* Invalidate the completion list. */
 
 #define invalidatelist() runhookdef(INVALIDATELISTHOOK, NULL)
+
+#ifdef ZSH_EUC
+#define _MB1 0x01
+#define _MB2 0x02
+#endif
