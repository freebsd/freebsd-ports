--- libmpdemux/tvi_bsdbt848.c.orig	Mon Jun  2 00:30:37 2003
+++ libmpdemux/tvi_bsdbt848.c	Tue Dec 16 00:55:43 2003
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
@@ -357,6 +361,12 @@
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
