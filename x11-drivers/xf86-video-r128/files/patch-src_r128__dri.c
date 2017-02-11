# Correct type in format strings
#
--- src/r128_dri.c.orig	2017-01-17 22:42:44 UTC
+++ src/r128_dri.c
@@ -500,7 +500,7 @@ static Bool R128DRIAgpInit(R128InfoPtr i
 	return FALSE;
     }
     xf86DrvMsg(pScreen->myNum, X_INFO,
-	       "[agp] %d kB allocated with handle 0x%08x\n",
+	       "[agp] %d kB allocated with handle 0x%08lx\n",
 	       info->agpSize*1024, info->agpMemHandle);
 
     if (drmAgpBind(info->drmFD, info->agpMemHandle, info->agpOffset) < 0) {
@@ -540,7 +540,7 @@ static Bool R128DRIAgpInit(R128InfoPtr i
 	return FALSE;
     }
     xf86DrvMsg(pScreen->myNum, X_INFO,
-	       "[agp] ring handle = 0x%08x\n", info->ringHandle);
+	       "[agp] ring handle = 0x%08lx\n", info->ringHandle);
 
     if (drmMap(info->drmFD, info->ringHandle, info->ringMapSize,
 	       &info->ring) < 0) {
@@ -558,7 +558,7 @@ static Bool R128DRIAgpInit(R128InfoPtr i
 	return FALSE;
     }
     xf86DrvMsg(pScreen->myNum, X_INFO,
- 	       "[agp] ring read ptr handle = 0x%08x\n",
+ 	       "[agp] ring read ptr handle = 0x%08lx\n",
 	       info->ringReadPtrHandle);
 
     if (drmMap(info->drmFD, info->ringReadPtrHandle, info->ringReadMapSize,
@@ -578,7 +578,7 @@ static Bool R128DRIAgpInit(R128InfoPtr i
 	return FALSE;
     }
     xf86DrvMsg(pScreen->myNum, X_INFO,
-	       "[agp] vertex/indirect buffers handle = 0x%08x\n",
+	       "[agp] vertex/indirect buffers handle = 0x%08lx\n",
 	       info->bufHandle);
 
     if (drmMap(info->drmFD, info->bufHandle, info->bufMapSize,
@@ -598,7 +598,7 @@ static Bool R128DRIAgpInit(R128InfoPtr i
 	return FALSE;
     }
     xf86DrvMsg(pScreen->myNum, X_INFO,
-	       "[agp] AGP texture map handle = 0x%08x\n",
+	       "[agp] AGP texture map handle = 0x%08lx\n",
 	       info->agpTexHandle);
 
     if (drmMap(info->drmFD, info->agpTexHandle, info->agpTexMapSize,
@@ -660,7 +660,7 @@ static Bool R128DRIPciInit(R128InfoPtr i
 	return FALSE;
     }
     xf86DrvMsg(pScreen->myNum, X_INFO,
-	       "[pci] %d kB allocated with handle 0x%08x\n",
+	       "[pci] %d kB allocated with handle 0x%08lx\n",
 	       info->agpSize*1024, info->pciMemHandle);
 
 				/* Initialize the CCE ring buffer data */
@@ -684,7 +684,7 @@ static Bool R128DRIPciInit(R128InfoPtr i
 	return FALSE;
     }
     xf86DrvMsg(pScreen->myNum, X_INFO,
-	       "[pci] ring handle = 0x%08x\n", info->ringHandle);
+	       "[pci] ring handle = 0x%08lx\n", info->ringHandle);
 
     if (drmMap(info->drmFD, info->ringHandle, info->ringMapSize,
 	       &info->ring) < 0) {
@@ -705,7 +705,7 @@ static Bool R128DRIPciInit(R128InfoPtr i
 	return FALSE;
     }
     xf86DrvMsg(pScreen->myNum, X_INFO,
-	       "[pci] ring read ptr handle = 0x%08x\n",
+	       "[pci] ring read ptr handle = 0x%08lx\n",
 	       info->ringReadPtrHandle);
 
     if (drmMap(info->drmFD, info->ringReadPtrHandle, info->ringReadMapSize,
@@ -728,7 +728,7 @@ static Bool R128DRIPciInit(R128InfoPtr i
 	return FALSE;
     }
     xf86DrvMsg(pScreen->myNum, X_INFO,
-	       "[pci] vertex/indirect buffers handle = 0x%08x\n",
+	       "[pci] vertex/indirect buffers handle = 0x%08lx\n",
 	       info->bufHandle);
 
     if (drmMap(info->drmFD, info->bufHandle, info->bufMapSize,
@@ -829,7 +829,7 @@ static Bool R128DRIMapInit(R128InfoPtr i
 	return FALSE;
     }
     xf86DrvMsg(pScreen->myNum, X_INFO,
-	       "[drm] register handle = 0x%08x\n", info->registerHandle);
+	       "[drm] register handle = 0x%08lx\n", info->registerHandle);
 
     return TRUE;
 }
