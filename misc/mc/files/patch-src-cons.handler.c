--- src/cons.handler.c.orig	Mon Sep 23 13:43:23 2002
+++ src/cons.handler.c	Tue Jun 15 03:14:17 2004
@@ -15,8 +15,6 @@
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
 
-/* The cons saver can't have a pid of 1, used to prevent bunches of */
-/*#ifdef linux */
 #include <config.h>
 
 #ifdef HAVE_UNISTD_H
@@ -24,6 +22,21 @@
 #endif
 #include <sys/types.h>
 #include <signal.h>
+#include <stdio.h>
+
+#ifdef SCO_FLAVOR
+#include <sys/types.h>
+#include <sys/vid.h>
+#include <sys/console.h>
+#include <sys/vtkd.h>
+#include <memory.h>
+#include <signal.h>
+#endif				/* SCO_FLAVOR */
+
+#ifdef __FreeBSD__
+#include <sys/consio.h>
+#include <sys/ioctl.h>
+#endif				/* __FreeBSD__ */
 
 #include "global.h"
 #include "tty.h"
@@ -31,30 +44,28 @@
 
 signed char console_flag = 0;
 
-#if defined(linux) || defined(__linux__)
-#include "main.h"
+#ifdef __linux__
+
+/* The cons saver can't have a pid of 1, used to prevent bunches of
+ * #ifdef linux */
 
-int    cons_saver_pid = 1;
-static int pipefd1 [2] = {-1, -1}, pipefd2 [2] = {-1, -1};
+int cons_saver_pid = 1;
+static int pipefd1[2] = { -1, -1 };
+static int pipefd2[2] = { -1, -1 };
 
-void show_console_contents (int starty, unsigned char begin_line, unsigned char end_line)
+static void
+show_console_contents_linux (int starty, unsigned char begin_line,
+			     unsigned char end_line)
 {
     unsigned char message = 0;
     unsigned short bytes = 0;
     int i;
 
-    standend ();
-
-    if (look_for_rxvt_extensions ()) {
-	show_rxvt_contents (starty, begin_line, end_line);
-	return;
-    }
-
     /* Is tty console? */
     if (!console_flag)
 	return;
     /* Paranoid: Is the cons.saver still running? */
-    if (cons_saver_pid < 1 || kill (cons_saver_pid, SIGCONT)){
+    if (cons_saver_pid < 1 || kill (cons_saver_pid, SIGCONT)) {
 	cons_saver_pid = 0;
 	console_flag = 0;
 	return;
@@ -75,9 +86,9 @@
     read (pipefd2[0], &bytes, 2);
 
     /* Read the bytes and output them */
-    for (i = 0; i < bytes; i++){
+    for (i = 0; i < bytes; i++) {
 	if ((i % COLS) == 0)
-	    move (starty+(i/COLS), 0);
+	    move (starty + (i / COLS), 0);
 	read (pipefd2[0], &message, 1);
 	addch (message);
     }
@@ -86,16 +97,15 @@
     read (pipefd2[0], &message, 1);
 }
 
-void handle_console (unsigned char action)
+static void
+handle_console_linux (unsigned char action)
 {
     char *tty_name;
     char *mc_conssaver;
     int status;
 
-    switch (action){
+    switch (action) {
     case CONSOLE_INIT:
-	if (look_for_rxvt_extensions ())
-	    return;
 	/* Close old pipe ends in case it is the 2nd time we run cons.saver */
 	close (pipefd1[1]);
 	close (pipefd2[0]);
@@ -104,7 +114,7 @@
 	pipe (pipefd2);
 	/* Get the console saver running */
 	cons_saver_pid = fork ();
-	if (cons_saver_pid < 0){
+	if (cons_saver_pid < 0) {
 	    /* Cannot fork */
 	    /* Delete pipes */
 	    close (pipefd1[1]);
@@ -112,14 +122,14 @@
 	    close (pipefd2[1]);
 	    close (pipefd2[0]);
 	    console_flag = 0;
-	} else if (cons_saver_pid > 0){
+	} else if (cons_saver_pid > 0) {
 	    /* Parent */
 	    /* Close the extra pipe ends */
 	    close (pipefd1[0]);
 	    close (pipefd2[1]);
 	    /* Was the child successful? */
 	    read (pipefd2[0], &console_flag, 1);
-	    if (!console_flag){
+	    if (!console_flag) {
 		close (pipefd1[1]);
 		close (pipefd2[0]);
 		waitpid (cons_saver_pid, &status, 0);
@@ -152,33 +162,31 @@
 	    close (1);
 	    close (0);
 	    _exit (3);
-	} /* if (cons_saver_pid ...) */
+	}			/* if (cons_saver_pid ...) */
 	break;
 
     case CONSOLE_DONE:
     case CONSOLE_SAVE:
     case CONSOLE_RESTORE:
-	if (look_for_rxvt_extensions ())
-	    return;
 	/* Is tty console? */
 	if (!console_flag)
 	    return;
 	/* Paranoid: Is the cons.saver still running? */
-	if (cons_saver_pid < 1 || kill (cons_saver_pid, SIGCONT)){
+	if (cons_saver_pid < 1 || kill (cons_saver_pid, SIGCONT)) {
 	    cons_saver_pid = 0;
 	    console_flag = 0;
 	    return;
 	}
 	/* Send command to the console handler */
 	write (pipefd1[1], &action, 1);
-	if (action != CONSOLE_DONE){
+	if (action != CONSOLE_DONE) {
 	    /* Wait the console handler to do its job */
 	    read (pipefd2[0], &console_flag, 1);
 	}
-	if (action == CONSOLE_DONE || !console_flag){
+	if (action == CONSOLE_DONE || !console_flag) {
 	    /* We are done -> Let's clean up */
-	    close (pipefd1 [1]);
-	    close (pipefd2 [0]);
+	    close (pipefd1[1]);
+	    close (pipefd2[0]);
 	    waitpid (cons_saver_pid, &status, 0);
 	    console_flag = 0;
 	}
@@ -186,221 +194,371 @@
     }
 }
 
-#endif /* #ifdef linux */
+#elif defined(SCO_FLAVOR)
 
-#ifdef SCO_FLAVOR
 /* 
 **	SCO console save/restore handling routines
 **	Copyright (C) 1997 Alex Tkachenko <alex@bcs.zaporizhzhe.ua>
 */
 
-#include <stdio.h>
-#include <sys/types.h>
-#include <sys/vid.h>
-#include <sys/console.h>
-#include <sys/vtkd.h>
-#include <memory.h>
-#include <signal.h>
-#include "tty.h"
-#include "util.h"
 #include "color.h"
-#include "cons.saver.h"
 
 static int FD_OUT = 2;
 
-static unsigned short* vidbuf = NULL;
-static unsigned short* screen = NULL;
+static unsigned short *vidbuf = NULL;
+static unsigned short *screen = NULL;
 static int height = 0, width = 0, saved_attr = 0;
 static int mode = 0;
 
-#define	SIG_ACQUIRE 21 /* originally: handset, line status change (?) */
+#define	SIG_ACQUIRE 21		/* originally: handset, line status change (?) */
 
 static int
-vt_active()
+vt_active ()
+{
+    struct vid_info vi;
+    int adapter = ioctl (FD_OUT, CONS_CURRENT, 0);
+
+    vi.size = sizeof (struct vid_info);
+    ioctl (FD_OUT, CONS_GETINFO, &(vi));
+    return (vi.m_num == ioctl (FD_OUT, CONSADP, adapter));
+}
+
+static void
+console_acquire_vt ()
 {
-	struct vid_info vi;
-	int adapter = ioctl(FD_OUT, CONS_CURRENT, 0);
+    struct vt_mode smode;
 
-	vi.size = sizeof(struct vid_info);
-	ioctl(FD_OUT, CONS_GETINFO, &(vi));
-	return (vi.m_num == ioctl(FD_OUT,CONSADP,adapter));
+    signal (SIG_ACQUIRE, SIG_DFL);
+    smode.mode = VT_AUTO;
+    smode.waitv = smode.relsig = smode.acqsig = smode.frsig = 0;
+    ioctl (FD_OUT, VT_SETMODE, &smode);
+    ioctl (FD_OUT, VT_RELDISP, VT_ACKACQ);
+}
+
+static void
+console_shutdown ()
+{
+    if (!console_flag) {
+	return;
+    }
+    if (screen != NULL) {
+	g_free (screen);
+    }
+    console_flag = 0;
 }
 
 static void
-console_acquire_vt()
+console_save ()
 {
+    struct m6845_info mi;
+
+    if (!console_flag) {
+	return;
+    }
+
+    if (!vt_active ()) {
 	struct vt_mode smode;
 
-	signal(SIG_ACQUIRE, SIG_DFL);
-	smode.mode = VT_AUTO;
-	smode.waitv = smode.relsig = smode.acqsig = smode.frsig = 0;
-	ioctl(FD_OUT, VT_SETMODE, &smode);
-	ioctl(FD_OUT, VT_RELDISP, VT_ACKACQ);
+	/* 
+	 **     User switched out of our vt. Let's wait until we get SIG_ACQUIRE,
+	 **     otherwise we could save wrong screen image
+	 */
+	signal (SIG_ACQUIRE, console_acquire_vt);
+	smode.mode = VT_PROCESS;
+	smode.waitv = 0;
+	smode.waitv = smode.relsig = smode.acqsig = smode.frsig =
+	    SIG_ACQUIRE;
+	ioctl (FD_OUT, VT_SETMODE, &smode);
+
+	pause ();
+    }
+
+    saved_attr = ioctl (FD_OUT, GIO_ATTR, 0);
+
+    vidbuf = (unsigned short *) ioctl (FD_OUT, MAPCONS, 0);
+
+    mi.size = sizeof (struct m6845_info);
+    ioctl (FD_OUT, CONS_6845INFO, &mi);
+
+    {
+	unsigned short *start = vidbuf + mi.screen_top;
+	memcpy (screen, start, width * height * 2);
+    }
+
+    write (FD_OUT, "\0337", 2);	/* save cursor position */
 }
 
 static void
-console_shutdown()
+console_restore ()
 {
-	if (!console_flag)
-	{
-		return;
-	}
-	if (screen != NULL)
-	{
-		g_free (screen);
-	}
-	console_flag = 0;
+    struct m6845_info mi;
+    unsigned short *start;
+
+    if (!console_flag) {
+	return;
+    }
+
+    write (FD_OUT, "\033[2J", 4);
+
+    mi.size = sizeof (struct m6845_info);
+    ioctl (FD_OUT, CONS_6845INFO, &mi);
+
+    start = vidbuf + mi.screen_top;
+    memcpy (start, screen, width * height * 2);
+    write (FD_OUT, "\0338", 2);	/* restore cursor position */
 }
 
 static void
-console_save()
+console_init ()
 {
-	struct m6845_info mi;
+    struct vid_info vi;
+    int adapter = ioctl (FD_OUT, CONS_CURRENT, 0);
 
-	if (!console_flag)
-	{
+    console_flag = 0;
+
+    if (adapter != -1) {
+	vi.size = sizeof (struct vid_info);
+	ioctl (FD_OUT, CONS_GETINFO, &(vi));
+
+	if (vt_active ()) {
+	    console_flag = 1;
+
+	    height = vi.mv_rsz;
+	    width = vi.mv_csz;
+
+	    screen = (unsigned short *) g_malloc (height * width * 2);
+	    if (screen == NULL) {
+		console_shutdown ();
 		return;
+	    }
+	    console_save ();
+	    mode = ioctl (FD_OUT, CONS_GET, 0);
+	    ioctl (FD_OUT, MODESWITCH | mode, 0);
+	    console_restore ();
 	}
+    }
+}
 
-	if (!vt_active())
-	{
-		struct vt_mode smode;
-
-		/* 
-		**	User switched out of our vt. Let's wait until we get SIG_ACQUIRE,
-		**	otherwise we could save wrong screen image
-		*/
-		signal(SIG_ACQUIRE, console_acquire_vt);
-		smode.mode = VT_PROCESS;
-		smode.waitv = 0;
-		smode.waitv = smode.relsig = smode.acqsig = smode.frsig = SIG_ACQUIRE;
-		ioctl(FD_OUT, VT_SETMODE, &smode);
+static void
+handle_console_sco (unsigned char action)
+{
+    switch (action) {
+    case CONSOLE_INIT:
+	console_init ();
+	break;
 
-		pause();
-	}
+    case CONSOLE_DONE:
+	console_shutdown ();
+	break;
+
+    case CONSOLE_SAVE:
+	console_save ();
+	break;
+
+    case CONSOLE_RESTORE:
+	console_restore ();
+	break;
+    default:
+	/* Nothing */ ;
+    }
+}
 
-	saved_attr = ioctl(FD_OUT, GIO_ATTR, 0);
+static void
+show_console_contents_sco (int starty, unsigned char begin_line,
+			   unsigned char end_line)
+{
+    register int i, len = (end_line - begin_line) * width;
 
-	vidbuf = (unsigned short*) ioctl(FD_OUT, MAPCONS, 0);
+    attrset (DEFAULT_COLOR);
+    for (i = 0; i < len; i++) {
+	if ((i % width) == 0)
+	    move (starty + (i / width), 0);
+	addch ((unsigned char) screen[width * starty + i]);
+    }
+}
 
-	mi.size = sizeof(struct m6845_info);
-	ioctl(FD_OUT, CONS_6845INFO, &mi);
+#elif defined(__FreeBSD__)
 
-	{
-		unsigned short* start = vidbuf + mi.screen_top;
-		memcpy(screen, start, width * height * 2);
-	}
+/*
+ * FreeBSD support copyright (C) 2003 Alexander Serkov <serkov@ukrpost.net>.
+ * Support for screenmaps by Max Khon <fjoe@FreeBSD.org>
+ */
+
+#define FD_OUT 1
+
+static struct scrshot screen_shot;
+static struct vid_info screen_info;
 
-	write(FD_OUT,"\0337",2);                        /* save cursor position */
+static void
+console_init (void)
+{
+    if (console_flag)
+	return;
+
+    screen_info.size = sizeof (screen_info);
+    if (ioctl (FD_OUT, CONS_GETINFO, &screen_info) == -1)
+	return;
+
+    memset (&screen_shot, 0, sizeof (screen_shot));
+    screen_shot.xsize = screen_info.mv_csz;
+    screen_shot.ysize = screen_info.mv_rsz;
+    if ((screen_shot.buf =
+	 g_malloc (screen_info.mv_csz * screen_info.mv_rsz * 2)) == NULL)
+	return;
+
+    console_flag = 1;
 }
 
 static void
-console_restore()
+set_attr (unsigned attr)
 {
-	struct m6845_info mi;
-	unsigned short* start;
+    /*
+     * Convert color indices returned by SCRSHOT (red=4, green=2, blue=1)
+     * to indices for ANSI sequences (red=1, green=2, blue=4).
+     */
+    static const int color_map[8] = { 0, 4, 2, 6, 1, 5, 3, 7 };
+    char cmd[17];
+    int bc, tc;
+
+    tc = attr & 0xF;
+    bc = (attr >> 4) & 0xF;
+
+    strcpy (cmd, "\x1B[");
+    strcat (cmd, (bc & 8) ? "5;" : "25;");
+    strcat (cmd, (tc & 8) ? "1;" : "22;");
+    strcat (cmd, "3%d;4%dm");
+    printf (cmd, color_map[tc & 7], color_map[bc & 7]);
+}
+
+#define cursor_to(x, y) do {				\
+	printf("\x1B[%d;%df", (y) + 1, (x) + 1);	\
+	fflush(stdout);					\
+} while (0)
 
-	if (!console_flag)
-	{
-		return;
-	}
+static void
+console_restore (void)
+{
+    int i, last;
 
-    write (FD_OUT, "\033[2J", 4);
+    if (!console_flag)
+	return;
 
-	mi.size = sizeof(struct m6845_info);
-	ioctl(FD_OUT, CONS_6845INFO, &mi);
+    cursor_to (0, 0);
 
-	start = vidbuf + mi.screen_top;
- 	memcpy(start, screen, width * height * 2);
-	write(FD_OUT,"\0338",2);                 /* restore cursor position */
+    /* restoring all content up to cursor position */
+    last = screen_info.mv_row * screen_info.mv_csz + screen_info.mv_col;
+    for (i = 0; i < last; ++i) {
+	set_attr ((screen_shot.buf[i] >> 8) & 0xFF);
+	putc (screen_shot.buf[i] & 0xFF, stdout);
+    }
+
+    /* restoring cursor color */
+    set_attr ((screen_shot.buf[last] >> 8) & 0xFF);
+
+    fflush (stdout);
 }
 
 static void
-console_init()
+console_shutdown (void)
 {
-	struct vid_info vi;
-	int adapter = ioctl(FD_OUT, CONS_CURRENT, 0);
+    if (!console_flag)
+	return;
 
-	console_flag = 0;
+    g_free (screen_shot.buf);
 
-	if (adapter != -1)
-	{
-		vi.size = sizeof(struct vid_info);
-		ioctl(FD_OUT, CONS_GETINFO, &(vi));
-
-		if (vt_active())
-		{
-			console_flag = 1;
-
-			height = vi.mv_rsz;
-			width = vi.mv_csz;
-
-			screen = (unsigned short*) g_malloc (height * width * 2);
-			if (screen == NULL)
-			{
-				console_shutdown();
-				return;
-			}
-			console_save();
-			mode = ioctl(FD_OUT, CONS_GET, 0);
-			ioctl(FD_OUT, MODESWITCH | mode, 0);
-			console_restore();
-		}
-	}
+    console_flag = 0;
 }
 
-void
-handle_console (unsigned char action)
+static void
+console_save (void)
 {
-	if (look_for_rxvt_extensions ())
-		return;
-	switch (action){
-		case CONSOLE_INIT:
-			console_init();
-			break;
-
-		case CONSOLE_DONE: 
-			console_shutdown();
-			break;
-
-		case CONSOLE_SAVE:
-			console_save();
-			break;
-
-		case CONSOLE_RESTORE:
-			console_restore();
-			break;
-		default:
-			/* Nothing */;
+    int i;
+    scrmap_t map;
+    scrmap_t revmap;
+
+    if (!console_flag)
+	return;
+
+    /* screen_info.size is already set in console_init() */
+    if (ioctl (FD_OUT, CONS_GETINFO, &screen_info) == -1) {
+	console_shutdown ();
+	return;
+    }
+
+    /* handle console resize */
+    if (screen_info.mv_csz != screen_shot.xsize
+	|| screen_info.mv_rsz != screen_shot.ysize) {
+	console_shutdown ();
+	console_init ();
+    }
+
+    if (ioctl (FD_OUT, CONS_SCRSHOT, &screen_shot) == -1) {
+	console_shutdown ();
+	return;
+    }
+
+    if (ioctl (FD_OUT, GIO_SCRNMAP, &map) == -1) {
+	console_shutdown ();
+	return;
+    }
+
+    for (i = 0; i < 256; i++) {
+	char *p = memchr (map.scrmap, i, 256);
+	revmap.scrmap[i] = p ? p - map.scrmap : i;
+    }
+
+    for (i = 0; i < screen_shot.xsize * screen_shot.ysize; i++) {
+	screen_shot.buf[i] =
+	    (screen_shot.buf[i] & 0xff00) | (unsigned char) revmap.
+	    scrmap[screen_shot.buf[i] & 0xff];
     }
 }
 
-void
-show_console_contents (int starty, unsigned char begin_line, unsigned char end_line)
+static void
+show_console_contents_freebsd (int starty, unsigned char begin_line,
+			       unsigned char end_line)
 {
-	register int i, len = (end_line - begin_line) * width;
+    int col, line;
+    char c;
 
-	if (look_for_rxvt_extensions ()) {
-		show_rxvt_contents (starty, begin_line, end_line);
-		return;
-	}
-	attrset(DEFAULT_COLOR);
-	for (i = 0; i < len; i++)
-	{
-		if ((i % width) == 0)
-		    move (starty+(i/width), 0);
-		addch ((unsigned char)screen[width*starty + i]);
+    if (!console_flag)
+	return;
+
+    for (line = begin_line; line <= end_line; line++) {
+	move (starty + line - begin_line, 0);
+        for (col = 0; col < min (COLS, screen_info.mv_csz); col++) {
+	    c = screen_shot.buf[line * screen_info.mv_csz + col] & 0xFF;
+	    addch (c);
 	}
+    }
 }
 
-#endif /* SCO_FLAVOR */
+static void
+handle_console_freebsd (unsigned char action)
+{
+    switch (action) {
+    case CONSOLE_INIT:
+	console_init ();
+	break;
 
+    case CONSOLE_DONE:
+	console_shutdown ();
+	break;
 
-#if !defined(linux) && !defined(__linux__) && !defined(SCO_FLAVOR)
+    case CONSOLE_SAVE:
+	console_save ();
+	break;
 
-#include "tty.h"
+    case CONSOLE_RESTORE:
+	console_restore ();
+	break;
+    }
+}
+#endif				/* __FreeBSD__ */
 
-void show_console_contents (int starty, unsigned char begin_line, unsigned char end_line)
+void
+show_console_contents (int starty, unsigned char begin_line,
+		       unsigned char end_line)
 {
     standend ();
 
@@ -408,14 +566,28 @@
 	show_rxvt_contents (starty, begin_line, end_line);
 	return;
     }
+#ifdef __linux__
+    show_console_contents_linux (starty, begin_line, end_line);
+#elif defined (__FreeBSD__)
+    show_console_contents_freebsd (starty, begin_line, end_line);
+#elif defined (SCO_FLAVOR)
+    show_console_contents_sco (starty, begin_line, end_line);
+#else
     console_flag = 0;
+#endif
 }
 
-void handle_console (unsigned char action)
+void
+handle_console (unsigned char action)
 {
-    look_for_rxvt_extensions ();
-}
-
-#endif				/* !defined(linux) && !defined(__linux__) && !defined(SCO_FLAVOR) */
-
+    if (look_for_rxvt_extensions ())
+	return;
 
+#ifdef __linux__
+    handle_console_linux (action);
+#elif defined (__FreeBSD__)
+    handle_console_freebsd (action);
+#elif defined (SCO_FLAVOR)
+    handle_console_sco (action);
+#endif
+}
