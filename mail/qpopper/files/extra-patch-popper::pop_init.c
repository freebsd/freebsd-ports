--- popper/pop_init.c.orig	Sun Dec  1 13:49:35 2002
+++ popper/pop_init.c	Sun Dec  1 13:51:24 2002
@@ -907,6 +907,7 @@
                 fprintf ( stderr, "Error setting '-y' to %s\n", optarg );
                 errflag++;
             }
+            break;
 
         default: /*  Unknown option received */
             errflag++;
@@ -979,6 +980,7 @@
                           "[-u] "
                           "[-U] "
                           "[-v] "
+                          "[-y log-facility] "
                           "\n",
                   argmessage[0],
                   xB,                   /* -B (or not) */
