
$FreeBSD$

--- vnc-viewer.c.orig	Sun Aug 22 15:47:19 2004
+++ vnc-viewer.c	Sun Aug 22 15:47:52 2004
@@ -391,7 +391,7 @@
       g_free(text);
       break;
     }
-  default:
+  default: break;
   }
   g_free(msg);
 }
@@ -781,7 +781,7 @@
   case 1: vnc->button_mask |= rfbButton1Mask; break;
   case 2: vnc->button_mask |= rfbButton2Mask; break;
   case 3: vnc->button_mask |= rfbButton3Mask; break;
-  default:
+  default: break;
   }
 
   x = vnc->hadj->value + (guint16)event->x;
@@ -801,7 +801,7 @@
   case 1: vnc->button_mask &= ~rfbButton1Mask; break;
   case 2: vnc->button_mask &= ~rfbButton2Mask; break;
   case 3: vnc->button_mask &= ~rfbButton3Mask; break;
-  default:
+  default: break;
   }
 
   x = vnc->hadj->value + (guint16)event->x;
