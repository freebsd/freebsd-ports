--- menu.c.orig	Mon Aug 21 08:47:47 2000
+++ menu.c	Sat Feb 10 05:32:41 2001
@@ -33,6 +33,10 @@
 #include <stdio.h>
 #include <signal.h>
 
+#ifndef NO_VIETNAMESE
+#include "vnvars.h"
+#endif /* NO_VIETNAMESE */
+
 extern void FindFontSelection();
 
 Arg menuArgs[2] = {{ XtNleftBitmap, (XtArgVal) 0 },
@@ -57,12 +61,20 @@
     do_tektextlarge(), do_tektext2(), do_tektext3(), do_tektextsmall(), 
     do_tekpage(), do_tekreset(), do_tekcopy(), do_vtshow(), do_vtmode(), 
     do_tekhide(), do_vtfont();
+#ifndef NO_VIETNAMESE
+static void do_vnfilterkeyboard(), do_vnfilterscreen();
+#endif /* NO_VIETNAMESE */
 
 
 /*
  * The order entries MUST match the values given in menu.h
  */
 MenuEntry mainMenuEntries[] = {
+#ifndef NO_VIETNAMESE
+    { "Enable Vietnamese keys",do_vnfilterkeyboard, NULL },   /*  0 */
+    { "Use Vietnamese screen",        do_vnfilterscreen, NULL },      /*  1 */
+    { "line3",                NULL, NULL },                   /*  2 */
+#endif /* NO_VIETNAMESE */
     { "securekbd",	do_securekbd, NULL },		/*  0 */
     { "allowsends",	do_allowsends, NULL },		/*  1 */
 #ifdef ALLOWLOGGING
@@ -80,6 +92,11 @@
     { "quit",		do_quit, NULL }};		/* 12 */
 
 MenuEntry vtMenuEntries[] = {
+#ifndef NO_VIETNAMESE
+    { "Enable Vietnamese keys",do_vnfilterkeyboard, NULL },     /*  0 */
+    { "Use Vietnamese screen",  do_vnfilterscreen, NULL },      /*  1 */
+    { "line3",          NULL, NULL },                   /*  2 */
+#endif /* NO_VIETNAMESE */
     { "scrollbar",	do_scrollbar, NULL },		/*  0 */
     { "jumpscroll",	do_jumpscroll, NULL },		/*  1 */
     { "reversevideo",	do_reversevideo, NULL },	/*  2 */
@@ -160,6 +177,10 @@
     Cardinal *param_count;      /* 0 or 1 */
 {
     TScreen *screen = &term->screen;
+#ifndef NO_VIETNAMESE
+	extern Boolean    vn_filter_keyboard;
+	extern Boolean    vn_filter_screen;
+#endif
 
     if (*param_count != 1) {
 	Bell(XkbBI_MinorError,0);
@@ -209,6 +230,10 @@
 	    update_cursesemul();
 	    update_visualbell();
 	    update_marginbell();
+#ifndef NO_VIETNAMESE
+	update_vnfilterkeyboard();
+	update_vnfilterscreen();
+#endif
 #ifndef NO_ACTIVE_ICON
 	    if (!screen->fnt_icon || !screen->iconVwin.window) {
 		set_sensitivity (screen->vtmenu,
@@ -1277,3 +1302,42 @@
 }
 
 
+#ifndef NO_VIETNAMESE
+
+static void do_vnfilterkeyboard (gw, closure, data)
+    Widget gw;
+    caddr_t closure, data;
+{
+    unsigned char     buf[5];
+    int                       count;
+
+    vn_filter_keyboard = !vn_filter_keyboard;
+    if (vn_filter_keyboard) {
+        vn_keyboard_id = vk_init(VK_ST_VIETNAMESE, VK_DEFAULT_ESC, vn_erase_char);
+    } else {
+      vk_end(vn_keyboard_id, buf, &count);
+    }
+    _Set_Vn_Title(VK_ST_VIETNAMESE);
+    update_vnfilterkeyboard();
+}
+
+
+static void do_vnfilterscreen (gw, closure, data)
+    Widget gw;
+    caddr_t closure, data;
+{
+    unsigned char     buf[5];
+    int                       count;
+
+    vn_filter_screen = !vn_filter_screen;
+    if (vn_filter_screen) {
+        vn_screen_id = vk_init(VK_ST_VIETNAMESE, VK_DEFAULT_ESC, vn_erase_char);
+      /* set it in batch mode so we don't get backspaces in immediate mode */
+      vk_set(vn_screen_id, 1, VK_SET_BATCH);
+    } else {
+      vk_end(vn_screen_id, buf, &count);
+    }
+    update_vnfilterscreen();
+}
+
+#endif /* NO_VIETNAMESE */
