--- Src/Zle/zle_move.c.orig	Sat Jul  3 22:18:00 1999
+++ Src/Zle/zle_move.c	Thu May  9 17:55:46 2002
@@ -159,6 +159,17 @@
 int
 forwardchar(char **args)
 {
+#ifdef ZSH_EUC
+    if (locale_is_euc) {
+	if (zmult == 1) {
+	    if (_mbmap_euc[line[cs]] & _MB1 &&
+	      cs+1 <= ll &&
+	      _mbmap_euc[line[cs+1]] & _MB2) {
+		cs++;
+	    }
+	}
+    }
+#endif
     cs += zmult;
     if (cs > ll)
 	cs = ll;
@@ -171,6 +182,17 @@
 int
 backwardchar(char **args)
 {
+#ifdef ZSH_EUC
+    if (locale_is_euc) {
+	if (zmult == 1) {
+	    if (_mbmap_euc[line[cs-1]] & _MB2 &&
+	      cs-2 >=0 &&
+	      _mbmap_euc[line[cs-2]] & _MB1) {
+		cs--;
+	    }
+	}
+    }
+#endif
     cs -= zmult;
     if (cs > ll)
 	cs = ll;
