--- revealrk.c.orig	2016-05-19 16:24:49 UTC
+++ revealrk.c
@@ -526,7 +526,9 @@ void GetBootTime(void)
         fclose(fsStat);
     }
 }
+#endif
 
+#if defined(OS_LINUX) || defined(OS_BSD)
 char* GetCommand(pid_t tuPID)
 {
     static char acBuf[PATH_MAX];
