--- ump/UnixShell.c.orig	Thu Nov 15 20:47:15 2001
+++ ump/UnixShell.c	Thu Nov 15 20:50:37 2001
@@ -38,7 +38,7 @@
 /*
 ** Stuff for the NPP_SetWindow method:
 */
-#ifdef XP_UNIX
+#if 0
 #include <X11/Xlib.h>                            /* Xlib */
 #include <X11/Intrinsic.h>                       /* Xt */
 #include <X11/StringDefs.h>                      /* "callback" */
--- ump/UnixShell.c.orig	Fri Feb 15 02:42:28 2002
+++ ump/UnixShell.c	Fri Feb 15 02:42:48 2002
@@ -144,8 +144,8 @@
 	int argc = 0;
 
 	argv[argc++] = "timidity";
-#ifdef AU_ALSA
-	argv[argc++] = "-Os";
+#ifdef AU_ESD
+	argv[argc++] = "-Oe";
 #else
 	argv[argc++] = "-Od";
 #endif
@@ -151,7 +151,7 @@
 #endif
 
 	if(timid_ump_rate <= 0)
-		argv[argc++] = eightKFlag ? "-s8000": "-s22050"; /* check if the user specified 8K rate */
+		argv[argc++] = eightKFlag ? "-s8000": "-s44100"; /* check if the user specified 8K rate */
 	else
 	{
 	  sprintf(opt_rate, "-s%d", timid_ump_rate);
@@ -230,7 +230,7 @@
   int loop; /* 0 means play only once, non-zero means loop forever */
   
   /* UNIX data members */
-#ifdef XP_UNIX
+#if 0
   Widget play, pause, stop, plus, minus; /* button widgets, and their pictures, as well as the logo picture */
   Pixmap logoPixmap, playupPixmap, playdnPixmap, pauseupPixmap, pausednPixmap, stopupPixmap, stopdnPixmap, plusupPixmap, plusdnPixmap, minusupPixmap, minusdnPixmap;
   Display *display; /* needed for XFreePixmap() */
@@ -344,6 +344,7 @@
     This->pid = -1;
     This->pipes[1] = -1;
     This->pipes[0] = -1;
+#if 0
     This->logoPixmap = -1;
     This->playupPixmap = -1;
     This->playdnPixmap = -1;
@@ -355,6 +356,7 @@
     This->plusdnPixmap = -1;
     This->minusupPixmap = -1;
     This->minusdnPixmap = -1;
+#endif
     This->pluginState = PLUGIN_PLAYING;
     This->loop = 0;
   }
@@ -422,7 +424,7 @@
     close(This->pipes[1]);
     close(This->pipes[0]);
     
-#ifdef XP_UNIX
+#if 0
     if(This->logoPixmap != -1)XFreePixmap(This->display, This->logoPixmap);
     if(This->playupPixmap != -1)XFreePixmap(This->display, This->playupPixmap);
     if(This->playdnPixmap != -1)XFreePixmap(This->display, This->playdnPixmap);
@@ -446,6 +448,7 @@
   return NPERR_NO_ERROR;
 }
 
+#if 0
 /* give buttons the right look for the state of the plugin */
 
 static void setButtons(PluginInstance* This, pluginPlayState state){
@@ -610,6 +613,7 @@
   *b = False;
   
 }
+#endif
 
 
 NPError 
@@ -633,7 +637,7 @@
    *	size changes, etc.
    */
   
-#ifdef XP_UNIX
+#if 0
   {
     
     
@@ -1050,6 +1054,7 @@
   unuse_UMP(NPN_GetJavaEnv());
 }
 
+#if 0
 /* functions for LiveConnect */
 
 static void stopSelectedCallback(XtPointer This, XtIntervalId* id){ stopSelected(NULL, This, NULL); }
@@ -1109,6 +1114,7 @@
   (void) XtAppAddTimeOut(XtWidgetToApplicationContext(Ump->stop), 1, minusSelectedCallback, (XtPointer) This);
   
 }
+#endif
 
 
 
