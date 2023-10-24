--- tools/rsyslogd.c.orig	2023-10-09 07:12:48 UTC
+++ tools/rsyslogd.c
@@ -460,19 +460,24 @@ prepareBackground(const int parentPipeFD)
 		/* try MacOS, FreeBSD */
 		if(close_unneeded_open_files("/proc/fd", beginClose, parentPipeFD) != 0) {
 			/* did not work out, so let's close everything... */
-			const int endClose = getdtablesize();
-#		if defined(HAVE_CLOSE_RANGE)
-			if(close_range(beginClose, endClose, 0) != 0) {
+			int endClose = (parentPipeFD > dbgGetDbglogFd()) ? parentPipeFD : dbgGetDbglogFd();
+			for(int i = beginClose ; i <= endClose ; ++i) {
+				if((i != dbgGetDbglogFd()) && (i != parentPipeFD)) {
+					aix_close_it(i); /* AIXPORT */
+				}
+			}
+			beginClose = endClose + 1;
+			endClose = getdtablesize();
+#if defined(HAVE_CLOSE_RANGE)
+			if(close_range(beginClose, endClose, 0) !=0) {
 				dbgprintf("errno %d after close_range(), fallback to loop\n", errno);
-#		endif
+#endif
 				for(int i = beginClose ; i <= endClose ; ++i) {
-					if((i != dbgGetDbglogFd()) && (i != parentPipeFD)) {
-						  aix_close_it(i); /* AIXPORT */
-					}
+					aix_close_it(i); /* AIXPORT */
 				}
-#		if defined(HAVE_CLOSE_RANGE)
+#if defined(HAVE_CLOSE_RANGE)
 			}
-#		endif
+#endif
 		}
 	}
 	seedRandomNumberForChild();
