--- pwc-ctrl.c	Thu Jun  8 20:28:32 2006
+++ pwc-ctrl.c	Fri Dec 15 14:37:57 2006
@@ -434,8 +434,9 @@
 		if (ret == -ENOENT)
 			Info("Video mode %s@%d fps is only supported with the decompressor module (pwcx).\n", size2name[size], frames);
 		else {
-			printf("%s: Failed to set video mode to %s@%d fps; return code = %d\n",
-				USBDEVNAME(pdev->sc_dev),size2name[size], frames, -ret);
+			device_printf(pdev->sc_dev, 
+                "Failed to set video mode to %s@%d fps; return code = %d\n",
+				size2name[size], frames, -ret);
 		}
 		return ret;
 	}
