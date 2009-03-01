--- gui/wm/ws.c.orgi	2009-03-01 14:37:10.000000000 +0100
+++ gui/wm/ws.c	2009-03-01 14:37:30.000000000 +0100
@@ -1157,6 +1157,7 @@
    win->xImage->data=win->Shminfo.shmaddr;
    win->Shminfo.readOnly=0;
    XShmAttach( wsDisplay,&win->Shminfo );
+   XSync(wsDisplay, False);
    shmctl( win->Shminfo.shmid,IPC_RMID,0 );
   }
   else
