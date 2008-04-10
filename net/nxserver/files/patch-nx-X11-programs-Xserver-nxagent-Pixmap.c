--- nx-X11/programs/Xserver/hw/nxagent/Pixmap.c.orig	2006-11-09 12:18:00.000000000 -0455
+++ nx-X11/programs/Xserver/hw/nxagent/Pixmap.c
@@ -1115,6 +1115,7 @@
     {
       FatalError("XGetImage: Failed.\n");
 
+      free(data);
       return False;
     }
 
@@ -1600,6 +1601,7 @@
         fprintf(stderr, "nxagentSynchronizeDrawableData: WARNING! Failed to create the temporary GC.\n");
         #endif
 
+        xfree(data);
         return 0;
       }
 
@@ -1661,6 +1663,7 @@
           fprintf(stderr, "nxagentSynchronizeDrawableData: WARNING! Failed to create the temporary GC.\n");
           #endif
 
+          xfree(data);
           return 0;
         }
 
@@ -1772,6 +1775,7 @@
   int useExtents;
   int imageLength, corruptedLength;
   int corruptedWidth, corruptedHeight;
+  int ret = 0; /* Used by error handling. 0 is error(?, based on previous code) */
 
   #ifdef TEST
   static int totalLength;
@@ -1812,7 +1816,7 @@
                             (void *) pDrawable);
     #endif
 
-    return 0;
+    goto SR_FREE_CLIP;
   }
 
   /*
@@ -1836,7 +1840,7 @@
                               (void *) pDrawable);
       #endif
 
-      return 0;
+      goto SR_FREE_CLIP;
     }
   }
 
@@ -1861,7 +1865,7 @@
     fprintf(stderr, "nxagentSynchronizeRegion: WARNING! Failed to allocate memory for the operation.\n");
     #endif
 
-    return 0;
+    goto SR_FREE_CLIP;
   }
 
   pSrcDrawable = (pDrawable -> type == DRAWABLE_PIXMAP ?
@@ -1876,7 +1880,7 @@
     fprintf(stderr, "nxagentSynchronizeRegion: WARNING! Failed to create the temporary GC.\n");
     #endif
 
-    return 0;
+    goto SR_FREE_XALLOC;
   }
 
   ValidateGC(pDrawable, pGC);
@@ -1935,7 +1939,7 @@
 
     #endif
 
-    return 1;
+    goto SR_FREE_GC;
   }
 
   /*
@@ -2029,13 +2033,17 @@
 
   nxagentGCTrap = saveTrap;
 
-  nxagentFreeRegion(pDrawable, clipRegion);
+SR_FREE_GC:
+  ret = 1;
+  FreeScratchGC(pGC);
 
+SR_FREE_XALLOC:
   xfree(data);
 
-  FreeScratchGC(pGC);
+SR_FREE_CLIP:
+  nxagentFreeRegion(pDrawable, clipRegion);
 
-  return 1;
+  return ret;
 }
 
 void nxagentSynchronizeBox(DrawablePtr pDrawable, BoxPtr pBox)
