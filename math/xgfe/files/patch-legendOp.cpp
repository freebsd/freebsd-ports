diff -u legendOp.cpp.orig legendOp.cpp
--- legendOp.cpp.orig	Mon Feb 23 23:36:08 1998
+++ legendOp.cpp	Thu Oct 30 21:42:04 2003
@@ -203,36 +203,36 @@
     gnuInt->setLegendPositionBelow(0);  
 
 
-  string legendPositionXVal = positionXEdit->text();
-  string legendPositionYVal = positionYEdit->text();
-  string legendPositionZVal = positionZEdit->text();
+  string legendPositionXVal = string(positionXEdit->text());
+  string legendPositionYVal = string(positionYEdit->text());
+  string legendPositionZVal = string(positionZEdit->text());
 
   gnuInt->setLegendPositionXVal(legendPositionXVal);
   gnuInt->setLegendPositionYVal(legendPositionYVal);
   gnuInt->setLegendPositionZVal(legendPositionZVal);
 
-  string justify = textJustifyList->currentText();
+  string justify = string(textJustifyList->currentText());
   gnuInt->setLegendTextJustify(justify);
 
-  string reverse = reverseList->currentText();
+  string reverse = string(reverseList->currentText());
   gnuInt->setLegendReverse(reverse);
   
-  string box = boxList->currentText();
+  string box = string(boxList->currentText());
   gnuInt->setLegendBox(box);
 
-  string linetype = lineTypeEdit->text();
+  string linetype = string(lineTypeEdit->text());
   gnuInt->setLegendLinetype(linetype);
   
-  string sample = sampleLengthEdit->text();
+  string sample = string(sampleLengthEdit->text());
   gnuInt->setLegendSampleLength(sample);
   
-  string spacing = spacingEdit->text();
+  string spacing = string(spacingEdit->text());
   gnuInt->setLegendSpacing(spacing);
   
-  string width = widthIncrementEdit->text();
+  string width = string(widthIncrementEdit->text());
   gnuInt->setLegendWidthIncrement(width);
   
-  string title = legendTitleEdit->text();
+  string title = string(legendTitleEdit->text());
   gnuInt->setLegendTitle(title);
   
   QDialog::accept();
