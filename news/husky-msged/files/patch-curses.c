--- curses.c.orig	Wed Jan 29 00:48:13 2003
+++ curses.c	Wed Jan 29 01:37:29 2003
@@ -22,6 +22,7 @@
 #include "winsys.h"
 #include "unused.h"
 #include "keys.h"
+#include "readtc.h"
 #include "specch.h"
 
 int color;
@@ -40,6 +41,7 @@
     0
 };
 
+static int tcflags = 0;         /* what we want to extract from termcap */
 
 #define EBUFSZ 100
 static EVT EVent[EBUFSZ];	/* event circular queue */
@@ -436,6 +438,8 @@
     Key_A_5, Key_A_6, Key_A_7, Key_A_8, Key_A_9
 };
 
+void TTSendMsg(int msg, int x, int y, int msgtype);
+
 unsigned int TTGetKey(void)
 {
     int ch;
@@ -443,6 +447,11 @@
     ch = getch();
     switch (ch)
     {
+    case KEY_RESIZE:
+        term.NRow = getmaxy(stdscr);
+	term.NCol = getmaxx(stdscr);
+        TTSendMsg(1, 0, 0, WND_WM_RESIZE);
+	return -1;
     case KEY_LEFT:
         return Key_Lft;
     case KEY_RIGHT:
@@ -566,6 +575,7 @@
         case '0':
             return Key_F10;
         }
+	break;
     }
 
     if (ch >= 127)    /* Treat special characters */
@@ -611,7 +621,7 @@
     return ch;
 }
 
-void TTSendMsg(unsigned int msg, int x, int y, unsigned int msgtype)
+void TTSendMsg(int msg, int x, int y, int msgtype)
 {
     if (((ebufin + 1) % EBUFSZ) != ebufout)
     {
@@ -633,6 +643,7 @@
     meta(stdscr, TRUE);
     intrflush(stdscr, FALSE);
     raw();
+    query_termcap(tcflags);
     return 0;
 }
 
@@ -660,30 +671,47 @@
     return 0;
 }
 
+static void
+collect_events(void)
+{
+    int ch = TTGetKey();
+    if (ch < 0)
+	return;
+
+    TTSendMsg(ch, 0, 0, WND_WM_CHAR);
+}
+
 int TTGetMsg(EVT * e)
 {
-    e->msg = TTGetKey();
-    e->x = 0;
-    e->y = 0;
-    e->msgtype = WND_WM_CHAR;
+    while (ebufin == ebufout)
+	collect_events();
+
+    e->msg = EVent[ebufout].msg;
+    e->x = EVent[ebufout].x;
+    e->y = EVent[ebufout].y;
+    e->msgtype = EVent[ebufout].msgtype;
     e->id = 0;
+    ebufout = (ebufout + 1) % EBUFSZ;
     return e->msg;
 }
 
 int TTPeekQue(void)
 {
-    return kbhit();
+    if (kbhit())
+	collect_events();
+    return ebufin != ebufout;
 }
 
 void TTClearQue(void)
 {
-    while (TTPeekQue())
-        TTGetKey();
+    ebufin = ebufout;
 }
 
 int TTGetChr(void)
 {
-    return TTGetKey();
+    EVT e;
+    TTGetMsg(&e);
+    return e.msg;
 }
 
 static char ansi2curses[8] = {
@@ -754,6 +782,18 @@
         allowed_special_characters =
             (unsigned char *) malloc(l = (strlen(value) + 1));
         memcpy(allowed_special_characters, value, l);
+    }
+    else if (!strcmp(keyword,"pseudographics"))
+    {
+        if (atoi(value))
+        {
+            tcflags |= QUERY_ALTCHARSET;
+        }
+        else
+        {
+            tcflags &= ~QUERY_ALTCHARSET;
+        }
+        query_termcap(tcflags);
     }
     else
     {
