--- plugin.c.orig	Wed Jan 19 19:30:52 2005
+++ plugin.c	Wed Apr 20 14:10:14 2005
@@ -194,6 +194,15 @@
 			XSync(This->dpy,False);
 			XFreePixmap(This->dpy, This->canvas);
 			shmdt(This->segInfo.shmaddr);
+#ifndef linux
+			{
+				struct shmid_ds buf;
+
+			if (shmctl(This->segInfo.shmid, IPC_RMID, &buf) < 0) {
+				perror("shmctl");
+				}
+			}
+#endif
 
 			FlashClose(This->fh);
 			This->fh = 0;
@@ -257,10 +266,10 @@
 static void
 flashWakeUp(XtPointer client_data, XtIntervalId *id)
 {
-	pthread_mutex_lock(&synchro);
 	PluginInstance* This;
 	long cmd;
 	long wakeUp;
+	pthread_mutex_lock(&synchro);
 
 	This = (PluginInstance*)client_data;
 
