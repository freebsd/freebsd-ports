diff -ru --exclude *.in iceb-5.35.old/libscr/init_screen.c iceb-5.35/libscr/init_screen.c
--- libscr/init_screen.c	Thu Jul 25 06:12:01 2002
+++ libscr/init_screen.c	Wed Dec 25 22:43:06 2002
@@ -16,6 +16,39 @@
 long		cklav,cstr; /*Для helstr.c свет клавиши и строки*/
 int		iscolor; /*0-черно-белый монитор*/
 
+#ifdef __FreeBSD__
+static void InitFreeBSDShift() {
+
+// Если по крайней мере одна функциональная клавиша
+// уже определена (например в termcap) то 
+// не переопределять их вообще
+char fkey[] = "kf  ";
+for (int i=13; i<13+12; i++) {
+	sprintf(fkey+2, "%d", i);
+	if (tigetstr(fkey) != NULL)
+		return;
+}
+
+// Порядок, задаем Shift+Fn
+static char* shiftedFKeys[] = {
+	"\033[Y",	// Shift+F1
+	"\033[Z",
+	"\033[a",
+	"\033[b",
+	"\033[c",
+	"\033[d",
+	"\033[e",
+	"\033[f",
+	"\033[g",
+	"\033[h",
+	"\033[i",
+	"\033[j"	// Shift+F12
+	};
+for (int i=0; i<12; i++)
+	define_key(shiftedFKeys[i], KEY_F(13+i));
+}
+#endif
+
 int init_screen() 
 {
 unsigned short		i,i1;
@@ -58,6 +91,10 @@
  }
 
 mousemask(ALL_MOUSE_EVENTS,NULL);
+
+#ifdef __FreeBSD__
+InitFreeBSDShift();
+#endif
 
 return(0);
 }     
