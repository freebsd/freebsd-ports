--- Src/Zle/zle_utils.c.orig	Mon Mar 26 17:58:34 2001
+++ Src/Zle/zle_utils.c	Thu May  9 17:57:20 2002
@@ -197,6 +197,17 @@
 mod_export void
 backdel(int ct)
 {
+#ifdef ZSH_EUC
+    if (locale_is_euc) {
+	if (ct == 1) {
+	    if (_mbmap_euc[line[cs-1]] & _MB2 &&
+	      cs-2 >=0 &&
+	      _mbmap_euc[line[cs-2]] & _MB1) {
+		ct = 2;
+	    }
+	}
+    }
+#endif
     shiftchars(cs -= ct, ct);
 }
 
