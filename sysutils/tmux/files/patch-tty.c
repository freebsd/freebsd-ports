$FreeBSD$

Apply upstream commit cbee283c26968304b473e2191d2bb5f52208b58d to prevent
OS X's Terminal.app turning on underlining when the status bar contains
bold characters.

--- tty.c
+++ tty.c
@@ -220,7 +220,7 @@ tty_start_tty(struct tty *tty)
 		tty_puts(tty, "\033[?1000l\033[?1006l\033[?1005l");
 
 	if (tty_term_has(tty->term, TTYC_XT))
-		tty_puts(tty, "\033[c\033[>4;1m\033[?1004h");
+		tty_puts(tty, "\033[c\033[>4;1m\033[?1004h\033[m");
 
 	tty->cx = UINT_MAX;
 	tty->cy = UINT_MAX;
@@ -283,7 +283,7 @@ tty_stop_tty(struct tty *tty)
 		tty_raw(tty, "\033[?1000l\033[?1006l\033[?1005l");
 
 	if (tty_term_has(tty->term, TTYC_XT))
-		tty_raw(tty, "\033[>4m\033[?1004l");
+		tty_raw(tty, "\033[>4m\033[?1004l\033[m");
 
 	tty_raw(tty, tty_term_string(tty->term, TTYC_RMCUP));
