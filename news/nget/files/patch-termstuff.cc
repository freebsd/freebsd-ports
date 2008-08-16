--- termstuff.cc	2004-05-29 16:00:07.000000000 -0700
+++ termstuff.cc	2008-03-02 23:38:19.000000000 -0800
@@ -23,7 +23,15 @@
 #include <stdio.h>
 #include <stdlib.h>
 
-#ifdef HAVE_WORKING_TERMSTUFF
+#ifdef HAVE_NETBSD_CURSES
+#include <termcap.h>
+static struct tinfo *info;
+static char *clr_bol;
+static void my_putchar(char c, void *d) { putchar((int)c); }
+#elif HAVE_NEW_CURSES
+#include <term.h>
+#elif HAVE_OLD_CURSES
+#include <curses.h>
 #include <term.h>
 #endif
 
@@ -32,15 +40,22 @@
 //Fake clr_bol function incase we can't use termcap.  Assumes that we will be
 //writing another line of near the same length after clearing, thus we don't
 //really need to clear the whole line, only the end of it.
-void generic_clr_bol(void) {
+static void generic_clr_bol(void) {
 	printf("\b\b\b\b    ");
 }
 
-voidfunc *clr_bol_func = generic_clr_bol;
+static voidfunc *clr_bol_func = generic_clr_bol;
 
-#ifdef HAVE_WORKING_TERMSTUFF
-void tputs_clr_bol(void) {
-	if (tputs(clr_bol, 1, putchar)<0) {
+#if defined(HAVE_NETBSD_CURSES) || defined(HAVE_NEW_CURSES) || defined(HAVE_OLD_CURSES)
+static void tputs_clr_bol(void) {
+# ifdef HAVE_NETBSD_CURSES
+	if (t_puts(info, clr_bol, 1, my_putchar, NULL)<0)
+# elif HAVE_NEW_CURSES
+	if (tputs(clr_bol, 1, putchar)<0)
+# elif HAVE_OLD_CURSES
+	if (putp(clr_bol)<0)
+# endif 
+	{
 		generic_clr_bol();
 		PDEBUG(DEBUG_MIN, "tputs_clr_bol: error");
 	}
@@ -48,18 +63,38 @@
 #endif
 
 void init_term_stuff(void) {
-#ifdef HAVE_WORKING_TERMSTUFF
+#if defined(HAVE_NETBSD_CURSES) || defined(HAVE_NEW_CURSES) || defined(HAVE_OLD_CURSES)
+# ifdef HAVE_NEW_CURSES
 	char tbuf[1024];
+# elif HAVE_OLD_CURSES
+	int err;
+# endif
 	char *term = getenv("TERM");
 	if (!term){
 		PDEBUG(DEBUG_MIN, "init_term_stuff: TERM env not set");
 		return;
 	}
-	if (tgetent(tbuf, term) != 1){
+# ifdef HAVE_NETBSD_CURSES
+	if (t_getent(&info, term) != 1) {
+		PDEBUG(DEBUG_MIN, "init_term_stuff: t_getent failure");
+		return;
+	}
+	if (!(clr_bol = t_agetstr(info, "ce"))) {
+		PDEBUG(DEBUG_MIN, "init_term_stuff: t_agetstr failure");
+		return;
+	}
+# elif HAVE_NEW_CURSES
+	if (tgetent(tbuf, term) != 1) {
 		PDEBUG(DEBUG_MIN, "init_term_stuff: tgetent failure");
-//		err(2, "tgetent failure");
 		return;
 	}
+# else /* HAVE_OLD_CURSES */
+       setupterm(term, 1, &err);
+       if (err != 1) {
+		PDEBUG(DEBUG_MIN, "init_term_stuff: setupterm failure");
+		return;
+	}
+# endif
 	clr_bol_func = tputs_clr_bol;
 	PDEBUG(DEBUG_MIN, "init_term_stuff: using tputs_clr_bol");
 #else
