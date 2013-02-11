--- src/DirList.cpp.orig	2013-02-11 08:59:54.000000000 +0100
+++ src/DirList.cpp	2013-02-11 09:03:05.000000000 +0100
@@ -1954,8 +1954,10 @@
 	if (prevMinimized == FALSE && minimized == TRUE)
 	{
 		onCmdRefreshTimer(0,0,0);
+#if defined(linux)
 		onMtdevicesRefresh(0,0,0);
 		onUpdevicesRefresh(0,0,0);
+#endif
 	}
 
     return 1;
