--- libmpdemux/tvi_bsdbt848.c.orig	Mon Jun  2 00:30:37 2003
+++ libmpdemux/tvi_bsdbt848.c	Sun Jan 18 21:26:15 2004
@@ -39,8 +39,12 @@
 #include <signal.h>
 #include <string.h>
 
+#include <sys/param.h>
 #ifdef __NetBSD__
 #include <dev/ic/bt8xx.h>
+#elif __FreeBSD_version >= 502100
+#include <dev/bktr/ioctl_meteor.h>
+#include <dev/bktr/ioctl_bt848.h>
 #else
 #include <machine/ioctl_meteor.h>
 #include <machine/ioctl_bt848.h>
@@ -287,6 +291,7 @@
 
     case TVI_CONTROL_TUN_SET_NORM:
         {
+	u_short tmp_fps;
         int req_mode = (int)*(void **)arg;
 
         priv->iformat = METEOR_FMT_AUTOMODE;
@@ -352,11 +357,18 @@
             return(0);
             }
 
-        if(ioctl(priv->btfd, METEORSFPS, &priv->fps) < 0) 
+	tmp_fps=priv->fps;
+	if(ioctl(priv->btfd, METEORSFPS, &tmp_fps) < 0)
             {
             perror("fps:ioctl");
             return(0);
             }
+	//set audioid after norm has been set    
+	if(priv->tunerready == TRUE &&
+	    ioctl(priv->tunerfd,BT848_SAUDIO, &tv_param_audio_id)<0)
+	    {
+		perror("Unable to set audioid");
+	    }
 
         return(TVI_CONTROL_TRUE);
         }
@@ -453,6 +465,7 @@
 {
 int marg;
 int count;
+u_short tmp_fps;
 
 G_private = priv; /* Oooh, sick */
 
@@ -497,8 +510,9 @@
     perror("SINPUT:ioctl");
     }
 
+tmp_fps=priv->fps;
 if(priv->videoready == TRUE &&
-   ioctl(priv->btfd, METEORSFPS, &priv->fps) < 0) 
+   ioctl(priv->btfd, METEORSFPS, &tmp_fps) < 0) 
     {
     perror("SFPS:ioctl");
     }
