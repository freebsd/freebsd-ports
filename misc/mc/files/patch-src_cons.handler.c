Created by: Ben Woods <woodsb02@FreeBSD.org> (FreeBSD port maintainer)
Logged upstream: https://www.midnight-commander.org/ticket/3643

--- src/cons.handler.c.orig	2016-05-11 09:47:32 UTC
+++ src/cons.handler.c
@@ -408,7 +408,7 @@ show_console_contents_freebsd (int start
     for (line = begin_line; line <= end_line; line++)
     {
         tty_gotoyx (starty + line - begin_line, 0);
-        for (col = 0; col < min (COLS, screen_info.mv_csz); col++)
+        for (col = 0; col < MIN (COLS, screen_info.mv_csz); col++)
         {
             c = screen_shot.buf[line * screen_info.mv_csz + col] & 0xFF;
             tty_print_char (c);
