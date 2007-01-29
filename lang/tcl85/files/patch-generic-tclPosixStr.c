--- ../generic/tclPosixStr.c.orig	Wed Jan 17 13:12:17 2007
+++ ../generic/tclPosixStr.c	Wed Jan 17 13:03:19 2007
@@ -1039,6 +1039,9 @@
 #ifdef SIGXFSZ
     case SIGXFSZ: return "SIGXFSZ";
 #endif
+#ifdef SIGINFO
+    case SIGINFO: return "SIGINFO";
+#endif
     }
     return "unknown signal";
 }
@@ -1169,6 +1172,9 @@
 #endif
 #ifdef SIGXFSZ
     case SIGXFSZ: return "exceeded file size limit";
+#endif
+#ifdef SIGINFO
+    case SIGINFO: return "information/status request";
 #endif
     }
     return "unknown signal";
