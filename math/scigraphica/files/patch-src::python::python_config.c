--- src/python/python_config.c.orig	Mon Mar  7 22:00:46 2005
+++ src/python/python_config.c	Mon Mar  7 22:00:53 2005
@@ -236,6 +236,7 @@
          }
          break;
       default:
+         break; /* do nothing */;
      }
   } 
 #ifdef WITH_GNOME
@@ -610,6 +611,7 @@
     break;
 
     default:
+      break;/* do nothing */;
     }
   }
 
