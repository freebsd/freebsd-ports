--- lib/readline/terminal.c.orig	Tue Mar  5 02:23:09 2002
+++ lib/readline/terminal.c	Wed Jul 24 05:57:59 2002
@@ -313,7 +313,11 @@
   { "ei", &_rl_term_ei },
   { "ic", &_rl_term_ic },
   { "im", &_rl_term_im },
+#ifdef __FreeBSD__
+  { "@7", &_rl_term_kH },	/* home down ?? */
+#else
   { "kH", &_rl_term_kH },	/* home down ?? */
+#endif
   { "kI", &_rl_term_kI },	/* insert */
   { "kd", &_rl_term_kd },
   { "ke", &_rl_term_ke },	/* end keypad mode */
