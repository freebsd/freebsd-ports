--- main.c.orig	Mon Aug 21 08:47:47 2000
+++ main.c	Sun Sep  8 19:35:54 2002
@@ -76,6 +76,9 @@
 #include "data.h"
 #include "error.h"
 #include "menu.h"
+#ifndef NO_VIETNAMESE
+#include "vnvars.h"
+#endif /* NO_VIETNAMESE */
 
 #ifdef att
 #define ATT
@@ -279,6 +282,10 @@
 #endif
 #include <sys/param.h>	/* for NOFILE */
 
+#if (defined(BSD) && (BSD >= 199103))
+#define USE_POSIX_WAIT
+#endif
+
 #ifdef  PUCC_PTYD
 #include <local/openpty.h>
 int	Ptyfd;
@@ -421,7 +428,11 @@
         CFLUSH, CWERASE, CLNEXT
 };
 static int d_disipline = NTTYDISC;
+#ifndef NO_VIETNAMESE
+static long int d_lmode = LCRTBS|LCRTERA|LCRTKIL|LPASS8;
+#else /* NO_VIETNAMESE */
 static long int d_lmode = LCRTBS|LCRTERA|LCRTKIL|LCTLECH;
+#endif /* NO_VIETNAMESE */
 #ifdef sony
 static long int d_jmode = KM_SYSSJIS|KM_ASCII;
 static struct jtchars d_jtc = {
@@ -586,6 +597,11 @@
     Boolean sunFunctionKeys;	/* %%% should be widget resource? */
     Boolean wait_for_map;
     Boolean useInsertMode;
+#ifndef NO_VIETNAMESE
+    Boolean vn_filter_keyboard;
+    Boolean vn_filter_screen;
+    unsigned int vn_erase_character;
+#endif /* NO_VIETNAMESE */
 } resource;
 
 /* used by VT (charproc.c) */
@@ -613,6 +629,14 @@
         offset(wait_for_map), XtRString, "false"},
     {"useInsertMode", "UseInsertMode", XtRBoolean, sizeof (Boolean),
         offset(useInsertMode), XtRString, "false"},
+#ifndef NO_VIETNAMESE
+    {"vnFilterKeyboard", "VnFilterKeyboard", XtRBoolean, sizeof (Boolean),
+        offset(vn_filter_keyboard), XtRString, "true"},
+    {"vnFilterScreen", "VnFilterScreen", XtRBoolean, sizeof (Boolean),
+        offset(vn_filter_screen), XtRString, "false"},
+    {"vnEraseCharacter", "VnEraseCharacter", XtRInt, sizeof (unsigned int),
+        offset(vn_erase_character), XtRString, "0"},
+#endif /* NO_VIETNAMESE */
 };
 #undef offset
 
@@ -621,7 +645,7 @@
     "XTerm*SimpleMenu*HorizontalMargins: 16",
     "XTerm*SimpleMenu*Sme.height: 16",
     "XTerm*SimpleMenu*Cursor: left_ptr",
-    "XTerm*mainMenu.Label:  Main Options (no app-defaults)",
+    "XTerm*mainMenu.Label:  VNTERM v2.1.1 (SGI version by Tin Le)",
     "XTerm*vtMenu.Label:  VT Options (no app-defaults)",
     "XTerm*fontMenu.Label:  VT Fonts (no app-defaults)",
     "XTerm*tekMenu.Label:  Tek Options (no app-defaults)",
@@ -693,6 +717,13 @@
 {"+im",		"*useInsertMode", XrmoptionNoArg,	(caddr_t) "off"},
 {"-vb",		"*visualBell",	XrmoptionNoArg,		(caddr_t) "on"},
 {"+vb",		"*visualBell",	XrmoptionNoArg,		(caddr_t) "off"},
+#ifndef NO_VIETNAMESE
+{"-vnk",      "*vnFilterKeyboard",    XrmoptionNoArg, (caddr_t) "on"},
+{"+vnk",      "*vnFilterKeyboard",    XrmoptionNoArg, (caddr_t) "off"},
+{"-vns",      "*vnFilterScreen",      XrmoptionNoArg, (caddr_t) "on"},
+{"+vns",      "*vnFilterScreen",      XrmoptionNoArg, (caddr_t) "off"},
+{"-vne",      "*vnEraseCharacter",    XrmoptionSepArg, (caddr_t) "0"},
+#endif /* NO_VIETNAMESE */
 {"-wf",		"*waitForMap",	XrmoptionNoArg,		(caddr_t) "on"},
 {"+wf",		"*waitForMap",	XrmoptionNoArg,		(caddr_t) "off"},
 /* bogus old compatibility stuff for which there are
@@ -770,6 +801,11 @@
 #endif
 { "-/+vb",                 "turn on/off visual bell" },
 { "-/+wf",                 "turn on/off wait for map before command exec" },
+#ifndef NO_VIETNAMESE
+{ "-/+vnk",                 "turn on/off Vietnamese keyboard filter" },
+{ "-/+vns",                 "turn on/off Vietnamese screen filter" },
+{ "-vne ASCII_code",        "specify erase character for Vietnamese typing" },
+#endif /* NO_VIETNAMESE */
 { "-e command args ...",   "command to execute" },
 { "%geom",                 "Tek window geometry" },
 { "#geom",                 "icon window geometry" },
@@ -815,6 +851,11 @@
 
     fprintf (stderr, "\r\n\nType %s -help for a full description.\r\n\n",
 	     ProgramName);
+fprintf(stderr, "\n");
+fprintf(stderr, "Version:   VISCII & VIQR 1.1\n");
+fprintf(stderr, "Ported by: Cuong T. Nguyen (cuong@haydn.Stanford.EDU\n");
+fprintf(stderr, "           TriChlor Software Group\n");
+fprintf(stderr, "Ported to 4.4BSD and X11R6.5.1 by: David E. O'Brien <obrien@NUXI.com>\n");
     exit (1);
 }
 
@@ -836,6 +877,11 @@
 	putc ('\n', stderr);
     }
     putc ('\n', stderr);
+fprintf(stderr, "\n");
+fprintf(stderr, "Version:   VISCII & VIQR 1.1\n");
+fprintf(stderr, "Ported by: Cuong T. Nguyen (cuong@haydn.Stanford.EDU\n");
+fprintf(stderr, "           TriChlor Software Group\n");
+fprintf(stderr, "Ported to 4.4BSD and X11R6.5.1 by: David E. O'Brien <obrien@NUXI.com>\n");
 
     exit (0);
 }
@@ -926,6 +972,11 @@
 	int mode;
 	char *base_name();
 	int xerror(), xioerror();
+#ifndef NO_VIETNAMESE
+#ifdef USE_SYSV_TERMIO
+	struct termio deftio;
+#endif /* USE_SYSV_TERMIO */
+#endif /* NO_VIETNAMESE */
 
 	XtSetLanguageProc (NULL, NULL, NULL);
 
@@ -1150,6 +1201,39 @@
 				  XtNumber(application_resources), NULL, 0);
 
 	waiting_for_initial_map = resource.wait_for_map;
+#ifndef NO_VIETNAMESE
+{
+	vn_filter_keyboard = resource.vn_filter_keyboard;
+	vn_filter_screen = resource.vn_filter_screen;
+	vn_erase_character = resource.vn_erase_character;
+
+	vn_keyboard_id = vk_init(VK_ST_VIETNAMESE, VK_DEFAULT_ESC, VK_DEFAULT_BS);
+	_Set_Vn_Title(VK_ST_VIETNAMESE);
+
+#ifdef USE_SYSV_TERMIO /* deftio has been initialized above */
+	vn_erase_char = deftio.c_cc[VERASE];
+#else /* USE_SYSV_TERMIO */
+	{
+		struct sgttyb       attr;
+
+		if (ioctl (0, TIOCGETP, (char *)&attr) >= 0) {
+			vn_erase_char = attr.sg_erase;
+		} else {
+			vn_erase_char = VK_DEFAULT_BS;
+		}
+	}
+#endif /* USE_SYSV_TERMIO */
+	if (vn_erase_character != 0) { /* not specified by user, take from tty characteristics */
+		vn_erase_char = (unsigned int) vn_erase_character;
+	}
+	vk_set(vn_keyboard_id,  (unsigned int) vn_erase_char, (int)VK_SET_BS);
+
+	vn_screen_id = vk_init(VK_ST_VIETNAMESE, VK_DEFAULT_ESC, VK_DEFAULT_BS);
+	/* screen filter is batch mode, as we don't want to spew backspaces
+	   all over the true drawing screen */
+	vk_set(vn_screen_id, 1, VK_SET_BATCH);
+}
+#endif /* NO_VIETNAMESE */
 
 	/*
 	 * ICCCM delete_window.
@@ -1255,6 +1339,11 @@
 
 	if (screen->savelines < 0) screen->savelines = 0;
 
+#ifndef NO_VIETNAMESE
+	update_vnfilterkeyboard();
+	update_vnfilterscreen();
+#endif /* NO_VIETNAMESE */
+
 	term->flags = 0;
 	if (!screen->jumpscroll) {
 	    term->flags |= SMOOTHSCROLL;
@@ -2417,6 +2506,10 @@
 			    HsSysError(cp_pipe[1], ERROR_TIOCSETC);
 #endif	/* TIOCSLTC */
 #ifdef TIOCLSET
+#ifndef NO_VIETNAMESE
+		lmode |= LPASS8;
+		lmode &= ~LCTLECH;
+#endif /* NO_VIETNAMESE */
 		    if (ioctl (tty, TIOCLSET, (char *)&lmode) == -1)
 			    HsSysError(cp_pipe[1], ERROR_TIOCLSET);
 #endif	/* TIOCLSET */
