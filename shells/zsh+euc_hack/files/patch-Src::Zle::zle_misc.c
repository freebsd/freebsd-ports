--- Src/Zle/zle_misc.c.orig	Mon Sep 10 19:48:51 2001
+++ Src/Zle/zle_misc.c	Thu Mar 25 04:36:46 2004
@@ -94,6 +94,14 @@
 	return ret;
     }
     if (cs + zmult <= ll) {
+#ifdef ZSH_EUC
+	if (locale_is_euc) {
+	    if (zmult == 1 &&
+		_mbmap_euc[line[cs]] & _MB1 &&
+		_mbmap_euc[line[cs+1]] & _MB2)
+		cs += 1;
+	}
+#endif
 	cs += zmult;
 	backdel(zmult);
 	return 0;
