--- src/SS5Utils.c.orig	2009-08-02 17:57:19.000000000 +1100
+++ src/SS5Utils.c	2011-02-25 13:34:42.311808628 +1000
@@ -117,6 +117,10 @@
     case ALONE:
       snprintf(logString,256 - 1,"[VERB] Role is ALONE.");
     break;
+    default:
+      fprintf (stderr, "[WARN] - Don't know Role %s\n", logString);
+      return ERR;
+    break;
   }
   LOGUPDATE()
 
