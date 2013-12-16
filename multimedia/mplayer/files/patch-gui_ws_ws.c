--- gui/wm/ws.c.orig	2013-08-03 00:42:05.000000000 +0200
+++ gui/wm/ws.c	2013-12-16 10:13:26.000000000 +0100
@@ -1322,6 +1322,7 @@
         win->xImage->data     = win->Shminfo.shmaddr;
         win->Shminfo.readOnly = False;
         XShmAttach(wsDisplay, &win->Shminfo);
+	XSync(wsDisplay, False);
         shmctl(win->Shminfo.shmid, IPC_RMID, 0);
     } else
 #endif
