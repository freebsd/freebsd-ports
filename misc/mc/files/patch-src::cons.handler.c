--- src/cons.handler.c.orig	Mon Sep 23 13:43:23 2002
+++ src/cons.handler.c	Wed Feb 26 22:09:57 2003
@@ -186,9 +186,8 @@
     }
 }
 
-#endif /* #ifdef linux */
+#elif defined(SCO_FLAVOR)
 
-#ifdef SCO_FLAVOR
 /* 
 **	SCO console save/restore handling routines
 **	Copyright (C) 1997 Alex Tkachenko <alex@bcs.zaporizhzhe.ua>
@@ -393,10 +392,212 @@
 	}
 }
 
-#endif /* SCO_FLAVOR */
+#elif defined(__FreeBSD__)
 
+/*
+ * FreeBSD support copyright (C) 2003 Alexander Serkov <serkov@ukrpost.net>.
+ * Support for screenmaps by Max Khon <fjoe@FreeBSD.org>
+ */
+
+#include <sys/consio.h>
+#include <sys/errno.h>
+#include <sys/fcntl.h>
+#include <sys/ioctl.h>
 
-#if !defined(linux) && !defined(__linux__) && !defined(SCO_FLAVOR)
+#include <stdarg.h>
+#include <stdio.h>
+#include <syslog.h>
+#include <unistd.h>
+#include <osreldate.h>
+
+#include "dialog.h"
+#include "wtools.h"
+
+#define FD_OUT 1
+
+static struct scrshot screen_shot;
+static struct vid_info screen_info;
+/*
+ * Color indexes returned by SCRSHOT differ from that ones VT220 accepts.
+ * color_map defines mapping from SCRSHOT colors to VT220.
+ */
+static int color_map[8] = { 0, 4, 2, 6, 1, 5, 3, 7 };
+
+static void
+console_init(void)
+{
+	if (console_flag)
+		return;
+
+	screen_info.size = sizeof(screen_info);
+	if (ioctl(FD_OUT, CONS_GETINFO, &screen_info) == -1)
+		return;
+
+#if __FreeBSD_version >= 500000
+	screen_shot.x = 0;
+	screen_shot.y = 0;
+#endif
+	screen_shot.xsize = screen_info.mv_csz;
+	screen_shot.ysize = screen_info.mv_rsz;
+	if ((screen_shot.buf = malloc(
+	    screen_info.mv_csz * screen_info.mv_rsz)) == NULL)
+		return;
+
+	console_flag = 1;
+}
+
+static void
+set_attr(unsigned attr)
+{
+	char cmd[17];
+	int bc, tc;
+
+	tc = attr & 0xF;
+	bc = (attr >> 4) & 0xF;
+
+	strcpy(cmd, "\x1B[");
+	strcat(cmd, (bc & 8) ? "5;" : "25;");
+	strcat(cmd, (tc & 8) ? "1;" : "22;");
+	strcat(cmd, "3%d;4%dm");
+	printf(cmd, color_map[tc & 7], color_map[bc & 7]);
+}
+
+#define cursor_to(x, y) do {				\
+	printf("\x1B[%d;%df", (y) + 1, (x) + 1);	\
+	fflush(stdout);					\
+} while (0)
+
+static void
+console_restore(void)
+{
+	int i, last;
+
+	if (!console_flag)
+		return;
+
+	cursor_to(0, 0);
+
+	/* restoring all content up to cursor position */
+	last = screen_info.mv_row * screen_info.mv_csz + screen_info.mv_col;
+	for (i = 0; i < last; ++i) {
+		set_attr((screen_shot.buf[i] >> 8) & 0xFF);
+		putc(screen_shot.buf[i] & 0xFF, stdout);
+	}
+
+	/* restoring cursor color */
+	set_attr((screen_shot.buf[last] >> 8) & 0xFF);
+
+	fflush(stdout);
+}
+
+static void
+console_shutdown(void)
+{
+	if (!console_flag)
+		return;
+
+	free(screen_shot.buf);
+
+	console_flag = 0;
+}
+
+static void
+console_save(void)
+{
+	int i;
+	scrmap_t map;
+	scrmap_t revmap;
+
+	if (!console_flag)
+		return;
+
+	/* screen_info.size is already set in console_init() */
+	if (ioctl(FD_OUT, CONS_GETINFO, &screen_info) == -1) {
+		console_shutdown();
+		return;
+	}
+
+	/* handle console resize */
+	if (screen_info.mv_csz != screen_shot.xsize
+	    || screen_info.mv_rsz != screen_shot.ysize) {
+		console_shutdown();
+		console_init();
+	}
+
+	if (ioctl(FD_OUT, CONS_SCRSHOT, &screen_shot) == -1) {
+		console_shutdown();
+		return;
+	}
+
+	if (ioctl(FD_OUT, GIO_SCRNMAP, &map) == -1) {
+		console_shutdown();
+		exit(1);
+	}
+
+	for (i = 0; i < 256; i++) {
+		char *p = memchr(map.scrmap, i, 256);
+		revmap.scrmap[i] = p ? p - map.scrmap : i;
+	}
+
+	for (i = 0; i < screen_shot.xsize * screen_shot.ysize; i++) {
+		screen_shot.buf[i] =
+		    (screen_shot.buf[i] & 0xff00) |
+		    (unsigned char) revmap.scrmap[screen_shot.buf[i] & 0xff];
+	}
+}
+
+void
+show_console_contents(int starty, unsigned char begin_line,
+    unsigned char end_line)
+{
+	int i, first, last;
+
+	if (look_for_rxvt_extensions()) {
+		show_rxvt_contents(starty, begin_line, end_line);
+		return;
+	}
+
+	if (!console_flag)
+		return;
+
+	cursor_to(0, starty);
+
+	first = starty * screen_info.mv_csz;
+	last = first + (end_line - begin_line + 1) * screen_info.mv_csz - 1;
+	for (i = first; i <= last; ++i) {
+		set_attr((screen_shot.buf[i] >> 8) & 0xFF);
+		putc(screen_shot.buf[i] & 0xFF, stdout);
+	}
+
+	fflush(stdout);
+}
+
+void
+handle_console(unsigned char action)
+{
+	if (look_for_rxvt_extensions())
+		return;
+
+	switch (action) {
+	case CONSOLE_INIT:
+		console_init();
+		break;
+
+	case CONSOLE_DONE:
+		console_shutdown();
+		break;
+
+	case CONSOLE_SAVE:
+		console_save();
+		break;
+
+	case CONSOLE_RESTORE:
+		console_restore();
+		break;
+	}
+}
+
+#else
 
 #include "tty.h"
 
@@ -416,6 +617,4 @@
     look_for_rxvt_extensions ();
 }
 
-#endif				/* !defined(linux) && !defined(__linux__) && !defined(SCO_FLAVOR) */
-
-
+#endif /* !defined(linux) && !defined(__linux__) && !defined(SCO_FLAVOR) && !defined(__FreeBSD__) */
