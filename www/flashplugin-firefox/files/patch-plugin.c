*** plugin.c.old	Mon Jun 12 10:24:09 2000
--- plugin.c	Mon Sep 30 00:48:40 2002
***************
*** 193,198 ****
--- 193,207 ----
  			XSync(This->dpy,False);
  			XFreePixmap(This->dpy, This->canvas);
  			shmdt(This->segInfo.shmaddr);
+ #ifndef linux
+ 			{
+ 				struct shmid_ds buf;
+ 
+ 			if (shmctl(This->segInfo.shmid, IPC_RMID, &buf) < 0) {
+ 				perror("shmctl");
+ 				}
+ 			}
+ #endif
  
  			FlashClose(This->fh);
  			This->fh = 0;
