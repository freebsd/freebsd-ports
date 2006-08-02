--- Src/Zle/zle_move.c.orig	Tue Nov  1 19:20:25 2005
+++ Src/Zle/zle_move.c	Thu Jul 13 17:57:11 2006
@@ -159,7 +159,18 @@
 int
 forwardchar(UNUSED(char **args))
 {
-    zlecs += zmult;
+#ifdef ZSH_EUC
+    if (locale_is_euc) {
+	if (zmult == 1) {
+	    if (_mbmap_euc[line[zlecs]] & _MB1 &&
+	      zlecs+1 <= zlell &&
+	      _mbmap_euc[line[zlecs+1]] & _MB2) {
+		zlecs++;
+	    }
+	}
+    }
+#endif
+   zlecs += zmult;
     if (zlecs > zlell)
 	zlecs = zlell;
     if (zlecs < 0)
@@ -171,6 +182,17 @@
 int
 backwardchar(UNUSED(char **args))
 {
+#ifdef ZSH_EUC
+    if (locale_is_euc) {
+	if (zmult == 1) {
+	    if (_mbmap_euc[line[zlecs-1]] & _MB2 &&
+	      zlecs-2 >=0 &&
+	      _mbmap_euc[line[zlecs-2]] & _MB1) {
+		zlecs--;
+	    }
+	}
+    }
+#endif
     zlecs -= zmult;
     if (zlecs > zlell)
 	zlecs = zlell;
