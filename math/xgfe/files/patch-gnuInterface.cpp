diff -u gnuInterface.cpp.orig gnuInterface.cpp
--- gnuInterface.cpp.orig	Wed Sep 30 04:25:51 1998
+++ gnuInterface.cpp	Thu Oct 30 21:42:04 2003
@@ -3626,7 +3626,7 @@
         tempint = 0;
         
         infile.getline(buffer,buffsize,';');
-        istrstream temp(buffer);
+        istringstream temp(buffer);
 
         if (temp >> tempint)
           setPlotFileFlag(tempint);
@@ -3636,7 +3636,7 @@
         tempint = 0;
         
         infile.getline(buffer,buffsize,';');
-        istrstream temp(buffer);
+        istringstream temp(buffer);
         
         if (temp >> tempint)
           setPlotFuncFlag(tempint);
@@ -3646,7 +3646,7 @@
         tempint = 0;
         
         infile.getline(buffer,buffsize,';');
-        istrstream temp(buffer);
+        istringstream temp(buffer);
 
         if (temp >> tempint)
           setPlotMultipleFileFlag(tempint);
@@ -3656,7 +3656,7 @@
         tempint = 0;
         
         infile.getline(buffer,buffsize,';');
-        istrstream temp(buffer);
+        istringstream temp(buffer);
 
         if (temp >> tempint)
           setPlotMultipleFuncFlag(tempint);
@@ -4114,7 +4114,7 @@
         tempint = 0;
         
         infile.getline(buffer,buffsize,';');
-        istrstream temp(buffer);
+        istringstream temp(buffer);
 
         if (temp >> tempint)
           setLegendPositionLeft(tempint);
@@ -4124,7 +4124,7 @@
         tempint = 0;
         
         infile.getline(buffer,buffsize,';');
-        istrstream temp(buffer);
+        istringstream temp(buffer);
 
         if (temp >> tempint)
           setLegendPositionRight(tempint);
@@ -4134,7 +4134,7 @@
         tempint = 0;
         
         infile.getline(buffer,buffsize,';');
-        istrstream temp(buffer);
+        istringstream temp(buffer);
 
         if (temp >> tempint)
           setLegendPositionTop(tempint);
@@ -4144,7 +4144,7 @@
         tempint = 0;
         
         infile.getline(buffer,buffsize,';');
-        istrstream temp(buffer);
+        istringstream temp(buffer);
 
         if (temp >> tempint)
           setLegendPositionBottom(tempint);
@@ -4154,7 +4154,7 @@
         tempint = 0;
         
         infile.getline(buffer,buffsize,';');
-        istrstream temp(buffer);
+        istringstream temp(buffer);
 
         if (temp >> tempint)
           setLegendPositionOutside(tempint);
@@ -4164,7 +4164,7 @@
         tempint = 0;
         
         infile.getline(buffer,buffsize,';');
-        istrstream temp(buffer);
+        istringstream temp(buffer);
 
         if (temp >> tempint)
           setLegendPositionBelow(tempint);
@@ -4251,7 +4251,7 @@
         tempint = 0;
         
         infile.getline(buffer,buffsize,';');
-        istrstream temp(buffer);
+        istringstream temp(buffer);
 
         if (temp >> tempint)
           setLogScaleBase(tempint);
@@ -4261,7 +4261,7 @@
         tempint = 0;
         
         infile.getline(buffer,buffsize,';');
-        istrstream temp(buffer);
+        istringstream temp(buffer);
 
         if (temp >> tempint)
           setLogScaleYAxis(tempint);
@@ -4271,7 +4271,7 @@
         tempint = 0;
         
         infile.getline(buffer,buffsize,';');
-        istrstream temp(buffer);
+        istringstream temp(buffer);
 
         if (temp >> tempint)
           setLogScaleYAxis(tempint);
@@ -4281,7 +4281,7 @@
         tempint = 0;
         
         infile.getline(buffer,buffsize,';');
-        istrstream temp(buffer);
+        istringstream temp(buffer);
 
         if (temp >> tempint)
           setLogScaleZAxis(tempint);
@@ -4291,7 +4291,7 @@
         tempint = 0;
         
         infile.getline(buffer,buffsize,';');
-        istrstream temp(buffer);
+        istringstream temp(buffer);
 
         if (temp >> tempint)
           setLogScaleX2Axis(tempint);
@@ -4301,7 +4301,7 @@
         tempint = 0;
         
         infile.getline(buffer,buffsize,';');
-        istrstream temp(buffer);
+        istringstream temp(buffer);
 
         if (temp >> tempint)
           setLogScaleY2Axis(tempint);
@@ -4325,7 +4325,7 @@
         tempint = 0;
         
         infile.getline(buffer,buffsize,';');
-        istrstream temp(buffer);
+        istringstream temp(buffer);
         
         if (temp >> tempint)
           setXticsOnFlag(tempint);
@@ -4391,7 +4391,7 @@
         tempint = 0;
         
         infile.getline(buffer,buffsize,';');
-        istrstream temp(buffer);
+        istringstream temp(buffer);
         
         if (temp >> tempint)
           setYticsOnFlag(tempint);
@@ -4457,7 +4457,7 @@
         tempint = 0;
         
         infile.getline(buffer,buffsize,';');
-        istrstream temp(buffer);
+        istringstream temp(buffer);
         
         if (temp >> tempint)
           setZticsOnFlag(tempint);
@@ -4516,7 +4516,7 @@
         tempint = 0;
         
         infile.getline(buffer,buffsize,';');
-        istrstream temp(buffer);
+        istringstream temp(buffer);
         
         if (temp >> tempint)
           setX2ticsOnFlag(tempint);
@@ -4582,7 +4582,7 @@
         tempint = 0;
         
         infile.getline(buffer,buffsize,';');
-        istrstream temp(buffer);
+        istringstream temp(buffer);
         
         if (temp >> tempint)
           setY2ticsOnFlag(tempint);        
@@ -4648,7 +4648,7 @@
         tempint = 0;
         
         infile.getline(buffer,buffsize,';');
-        istrstream temp(buffer);
+        istringstream temp(buffer);
         
         if (temp >> tempint)
           setRotationXAxis(tempint);
@@ -4658,7 +4658,7 @@
         tempint = 0;
         
         infile.getline(buffer,buffsize,';');
-        istrstream temp(buffer);
+        istringstream temp(buffer);
         
         if (temp >> tempint)
           setRotationZAxis(tempint);
@@ -4689,7 +4689,7 @@
         tempint = 0;
         
         infile.getline(buffer,buffsize,';');
-        istrstream temp(buffer);
+        istringstream temp(buffer);
         
         if (temp >> tempint)
           setd3HiddenLineFlag(tempint);
