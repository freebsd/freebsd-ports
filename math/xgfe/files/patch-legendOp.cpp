diff -u legendOp.cpp.orig legendOp.cpp
--- legendOp.cpp.orig	Mon Feb 23 23:36:08 1998
+++ legendOp.cpp	Thu Oct 30 21:42:04 2003
@@ -203,36 +203,36 @@
     gnuInt->setLegendPositionBelow(0);  
 
 
-  string legendPositionXVal = positionXEdit->text();
-  string legendPositionYVal = positionYEdit->text();
-  string legendPositionZVal = positionZEdit->text();
+  string legendPositionXVal = positionXEdit->text().ascii();
+  string legendPositionYVal = positionYEdit->text().ascii();
+  string legendPositionZVal = positionZEdit->text().ascii();
 
   gnuInt->setLegendPositionXVal(legendPositionXVal);
   gnuInt->setLegendPositionYVal(legendPositionYVal);
   gnuInt->setLegendPositionZVal(legendPositionZVal);
 
-  string justify = textJustifyList->currentText();
+  string justify = textJustifyList->currentText().ascii();
   gnuInt->setLegendTextJustify(justify);
 
-  string reverse = reverseList->currentText();
+  string reverse = reverseList->currentText().ascii();
   gnuInt->setLegendReverse(reverse);
   
-  string box = boxList->currentText();
+  string box = boxList->currentText().ascii();
   gnuInt->setLegendBox(box);
 
-  string linetype = lineTypeEdit->text();
+  string linetype = lineTypeEdit->text().ascii();
   gnuInt->setLegendLinetype(linetype);
   
-  string sample = sampleLengthEdit->text();
+  string sample = sampleLengthEdit->text().ascii();
   gnuInt->setLegendSampleLength(sample);
   
-  string spacing = spacingEdit->text();
+  string spacing = spacingEdit->text().ascii();
   gnuInt->setLegendSpacing(spacing);
   
-  string width = widthIncrementEdit->text();
+  string width = widthIncrementEdit->text().ascii();
   gnuInt->setLegendWidthIncrement(width);
   
-  string title = legendTitleEdit->text();
+  string title = legendTitleEdit->text().ascii();
   gnuInt->setLegendTitle(title);
   
   QDialog::accept();
