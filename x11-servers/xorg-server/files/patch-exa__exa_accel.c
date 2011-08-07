diff --git a/exa/exa_accel.c b/exa/exa_accel.c
index 6c677c7..b4c0f83 100644
--- exa/exa_accel.c
+++ exa/exa_accel.c
@@ -1057,6 +1057,8 @@ exaFillRegionSolid (DrawablePtr	pDrawable, RegionPtr pRegion, Pixel pixel,
 		*(CARD16*)pExaPixmap->sys_ptr = pixel;
 		break;
 	    case 8:
+	    case 4:
+	    case 1:
 		*(CARD8*)pExaPixmap->sys_ptr = pixel;
 	    }
 
diff --git a/exa/exa_unaccel.c b/exa/exa_unaccel.c
index a078cc1..855146b 100644
--- exa/exa_unaccel.c
+++ exa/exa_unaccel.c
@@ -748,6 +757,8 @@ exaGetPixmapFirstPixel (PixmapPtr pPixmap)
 	    return pixel;
 	}
     case 8:
+    case 4:
+    case 1:
 	{
 	    CARD8 pixel;
 
