Index: src/bsd_kbd.c
@@ -205,6 +205,12 @@
 #endif
         }
     }
+/*
+ * Switch keyboards which are not attached to console in RAW mode
+ */
+#if defined (SYSCONS_SUPPORT) || defined (PCVT_SUPPORT)
+	ioctl(pInfo->fd, KDSKBMODE, K_RAW);
+#endif
     return Success;
 }
 
