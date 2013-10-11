--- src/plotting.cpp.orig	2013-09-22 05:09:11.000000000 +0200
+++ src/plotting.cpp	2013-10-11 10:55:14.000000000 +0200
@@ -1891,7 +1891,7 @@
       DFloatGDL* charthickVect=e->GetKWAs<DFloatGDL>( charthickIx );
       charthick=(*charthickVect)[0];
     }
-    a->wid(charthick);
+    a->width(charthick);
   }
 
   void gdlSetAxisCharsize(EnvT *e, GDLGStream *a, string axis)
@@ -1919,7 +1919,7 @@
 
     e->AssureFloatScalarKWIfPresent("THICK", thick);
     if ( thick<=0.0 ) thick=1.0;
-    a->wid(static_cast<PLINT>(floor(thick-0.5)));
+    a->width(static_cast<PLINT>(floor(thick-0.5)));
   }
 
   //LINESTYLE
@@ -2936,7 +2936,7 @@
         a->smaj((PLFLT)OtherAxisSizeInMm, 1.0); //set base ticks to default 0.02 viewport converted to mm.
         a->smin((PLFLT)OtherAxisSizeInMm/2.0,1.0); //idem min (plplt defaults)
         //thick for box and ticks.
-        a->wid(Thick);
+        a->width(Thick);
         //ticks or grid eventually with style and length:
         if (abs(TickLen)<1e-6) Opt=""; else Opt="st"; //remove ticks if ticklen=0
         if (TickLen<0) {Opt+="i"; TickLen=-TickLen;}
@@ -2981,7 +2981,7 @@
         else if (axis=="Y") a->box("", 0.0, 0 , Opt.c_str(), 0.0, 0);
       }
       //reset charsize & thick
-      a->wid(1);
+      a->width(1);
       a->sizeChar(1.0);
     }
 	return 0;
@@ -3124,7 +3124,7 @@
         a->smaj((PLFLT)OtherAxisSizeInMm, 1.0); //set base ticks to default 0.02 viewport converted to mm.
         a->smin((PLFLT)OtherAxisSizeInMm/2.0,1.0); //idem min (plplt defaults)
         //thick for box and ticks.
-        a->wid(Thick);
+        a->width(Thick);
         //ticks or grid eventually with style and length:
         if (abs(TickLen)<1e-6) Opt=""; else Opt="st"; //remove ticks if ticklen=0
         if (TickLen<0) {Opt+="i"; TickLen=-TickLen;}
@@ -3149,7 +3149,7 @@
         else if (axis=="Z") a->box3("","",0,0,"","",0,0, Opt.c_str(), "", TickInterval, Minor);
       }
       //reset charsize & thick
-      a->wid(1);
+      a->width(1);
       a->sizeChar(1.0);
     }
 	return 0;
