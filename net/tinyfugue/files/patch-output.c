--- src/output.c.orig	2007-01-14 00:44:19 UTC
+++ src/output.c
@@ -2270,6 +2270,7 @@ static void ioutall(int kpos)
         iendx = -kpos + 1;
         kpos = 0;
     }
+    if (keybuf->data == 0) return;
     if (sockecho())
         ioutputs(keybuf->data + kpos, keybuf->len - kpos);
 }
