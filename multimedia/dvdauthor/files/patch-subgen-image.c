--- src/subgen-image.c.orig     Sun Dec 19 22:38:27 2004
+++ src/subgen-image.c  Sun Dec 19 22:38:44 2004
@@ -177,7 +177,7 @@
             p.r=pdata[x*4];
             p.g=pdata[x*4+1];
             p.b=pdata[x*4+2];
-            p.t=255-pdata[x*4+3];
+            p.t=pdata[x*4+3];
             putpixel(s,y*s->width+x,&p);
         }
     }
