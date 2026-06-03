Index: src/bsd_kbd.c
@@ -237,6 +237,12 @@
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
 
