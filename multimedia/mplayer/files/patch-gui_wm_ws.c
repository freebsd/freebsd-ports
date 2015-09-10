--- gui/wm/ws.c.orig	2015-08-01 07:44:07 UTC
+++ gui/wm/ws.c
@@ -1322,6 +1322,7 @@ void wsImageCreate(wsWindow *win, int w,
         win->xImage->data     = win->Shminfo.shmaddr;
         win->Shminfo.readOnly = False;
         XShmAttach(wsDisplay, &win->Shminfo);
+	XSync(wsDisplay, False);
         shmctl(win->Shminfo.shmid, IPC_RMID, 0);
     } else
 #endif
