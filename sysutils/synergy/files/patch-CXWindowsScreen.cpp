--- lib/platform/CXWindowsScreen.cpp.orig	Sun Jul 20 09:21:19 2003
+++ lib/platform/CXWindowsScreen.cpp	Fri Oct 17 14:28:26 2003
@@ -293,7 +293,7 @@
 			}
 		}
 #if HAVE_POLL
-		int timeout = static_cast<int>(1000.0 * dtimeout);
+		int timeout = (dtimeout < 0) ? -1 :  static_cast<int>(1000.0 * dtimeout);
 #else
 		struct timeval timeout;
 		struct timeval* timeoutPtr;
