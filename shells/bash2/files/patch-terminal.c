--- lib/readline/terminal.c.orig	Tue Feb  6 12:39:22 2001
+++ lib/readline/terminal.c	Wed Apr 11 09:43:44 2001
@@ -297,7 +297,11 @@
   { "im", &_rl_term_im },
   { "kd", &_rl_term_kd },
   { "kh", &_rl_term_kh },	/* home */
+#ifdef __FreeBSD__
+  { "@7", &_rl_term_kH },	/* end */
+#else
   { "kH", &_rl_term_kH },	/* end */
+#endif
   { "kl", &_rl_term_kl },
   { "kr", &_rl_term_kr },
   { "ku", &_rl_term_ku },
