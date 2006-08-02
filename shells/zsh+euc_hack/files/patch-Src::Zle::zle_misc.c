--- Src/Zle/zle_misc.c.orig	Mon Feb 13 19:58:39 2006
+++ Src/Zle/zle_misc.c	Thu Jul 13 17:52:43 2006
@@ -111,6 +111,14 @@
 	return ret;
     }
     if (zlecs + zmult <= zlell) {
+#ifdef ZSH_EUC
+	if (locale_is_euc) {
+	    if (zmult == 1 &&
+		_mbmap_euc[line[cs]] & _MB1 &&
+		_mbmap_euc[line[cs+1]] & _MB2)
+		cs += 1;
+	}
+#endif
 	zlecs += zmult;
 	backdel(zmult);
 	return 0;
