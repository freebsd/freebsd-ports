--- screensaver.c~
+++ screensaver.c
@@ -61,7 +61,7 @@
 #define UNBLANK (V_DISPLAY_ON)
 #elif defined (__NetBSD__) || defined (__OpenBSD__)
 #define UNBLANK (WSDISPLAYIO_VIDEO_ON)
-#elif
+#else
 	#error not implement
 #endif
 
