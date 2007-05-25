--- Classes/ScrubbingBar.h.orig	Tue Feb 22 17:07:54 2005
+++ Classes/ScrubbingBar.h	Tue May  1 19:42:53 2007
@@ -22,7 +22,7 @@
 // info dictionary key
 	//	@"SBClickedValue"		NSNumber double
 
-#if MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_2
+#if 1
 typedef enum _NSScrubbingBarStyle {
     NSScrubbingBarEmptyStyle = 0,
 	NSScrubbingBarProgressStyle = 1,
