--- libmpdemux/tvi_bsdbt848.c.orig	Tue Jan 14 19:20:17 2003
+++ libmpdemux/tvi_bsdbt848.c	Fri Aug 29 11:08:51 2003
@@ -357,6 +357,12 @@
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
