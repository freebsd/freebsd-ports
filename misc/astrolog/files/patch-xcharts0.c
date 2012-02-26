--- xcharts0.c.bak	2002-05-18 22:28:56.000000000 +0400
+++ xcharts0.c	2012-02-26 10:00:57.000000000 +0400
@@ -200,7 +200,7 @@
       SzDate(Mon, Day, Yea, fTrue));
     DrawPrint(sz, gi.kiOn, fFalse);
     DrawPrint(SzTim(Tim), gi.kiOn, fTrue);
-    sprintf(sz, " (%cT %s GMT)", ChDst(Dst), SzZone(Zon));
+    sprintf(sz, " %cT %s GMT", ChDst(Dst), SzZone(Zon));
     DrawPrint(sz, gi.kiOn, fFalse);
   }
   if (*ciMain.loc && us.nRel != rcMidpoint)
@@ -278,7 +278,7 @@
       SzDate(Mon, Day, Yea, fTrue));
     DrawPrint(sz, kYellow, fFalse);
     DrawPrint(SzTim(Tim), kYellow, fTrue);
-    sprintf(sz, " (%cT %s GMT)", ChDst(Dst), SzZone(Zon));
+    sprintf(sz, " %cT %s GMT", ChDst(Dst), SzZone(Zon));
     DrawPrint(sz, kYellow, fFalse);
     if (us.nRel != rcProgress) {  
       if (*ciMain.loc)
