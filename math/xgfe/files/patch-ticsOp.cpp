diff -u ticsOp.cpp.orig ticsOp.cpp
--- ticsOp.cpp.orig	Sun Jun  7 07:37:48 1998
+++ ticsOp.cpp	Thu Oct 30 21:42:04 2003
@@ -339,9 +339,9 @@
   if (xticsOnRButton->isChecked() == FALSE)
     gnuInt->setXticsOnFlag(0);
 
-  string xticsLocation = xticsLocationCBox->currentText();
-  string xticsMirror = xticsMirrorCBox->currentText();
-  string xticsRotation = xticsRotationCBox->currentText();
+  string xticsLocation = xticsLocationCBox->currentText().ascii();
+  string xticsMirror = xticsMirrorCBox->currentText().ascii();
+  string xticsRotation = xticsRotationCBox->currentText().ascii();
 
   string xticsPositionType;
 
@@ -351,10 +351,10 @@
   if (xticsLabelPosRButton->isChecked() == TRUE)
     xticsPositionType = "LABELS";
 
-  string xticsStartPos = xticsStartPosEdit->text();
-  string xticsIncPos = xticsIncPosEdit->text();
-  string xticsEndPos = xticsEndPosEdit->text();
-  string xticsLabelsPos = xticsLabelsPosEdit->text();
+  string xticsStartPos = xticsStartPosEdit->text().ascii();
+  string xticsIncPos = xticsIncPosEdit->text().ascii();
+  string xticsEndPos = xticsEndPosEdit->text().ascii();
+  string xticsLabelsPos = xticsLabelsPosEdit->text().ascii();
 
   gnuInt->setXticsLocation(xticsLocation);
   gnuInt->setXticsMirror(xticsMirror);
@@ -372,9 +372,9 @@
   if (yticsOnRButton->isChecked() == FALSE)
     gnuInt->setYticsOnFlag(0);
 
-  string yticsLocation = yticsLocationCBox->currentText();
-  string yticsMirror = yticsMirrorCBox->currentText();
-  string yticsRotation = yticsRotationCBox->currentText();
+  string yticsLocation = yticsLocationCBox->currentText().ascii();
+  string yticsMirror = yticsMirrorCBox->currentText().ascii();
+  string yticsRotation = yticsRotationCBox->currentText().ascii();
 
   string yticsPositionType;
 
@@ -384,10 +384,10 @@
   if (yticsLabelPosRButton->isChecked() == TRUE)
     yticsPositionType = "LABELS";
 
-  string yticsStartPos = yticsStartPosEdit->text();
-  string yticsIncPos = yticsIncPosEdit->text();
-  string yticsEndPos = yticsEndPosEdit->text();
-  string yticsLabelsPos = yticsLabelsPosEdit->text();
+  string yticsStartPos = yticsStartPosEdit->text().ascii();
+  string yticsIncPos = yticsIncPosEdit->text().ascii();
+  string yticsEndPos = yticsEndPosEdit->text().ascii();
+  string yticsLabelsPos = yticsLabelsPosEdit->text().ascii();
 
   gnuInt->setYticsLocation(yticsLocation);
   gnuInt->setYticsMirror(yticsMirror);
@@ -405,8 +405,8 @@
   if (zticsOnRButton->isChecked() == FALSE)
     gnuInt->setZticsOnFlag(0);
 
-  string zticsMirror = zticsMirrorCBox->currentText();
-  string zticsRotation = zticsRotationCBox->currentText();
+  string zticsMirror = zticsMirrorCBox->currentText().ascii();
+  string zticsRotation = zticsRotationCBox->currentText().ascii();
 
   string zticsPositionType;
 
@@ -416,10 +416,10 @@
   if (zticsLabelPosRButton->isChecked() == TRUE)
     zticsPositionType = "LABELS";
 
-  string zticsStartPos = zticsStartPosEdit->text();
-  string zticsIncPos = zticsIncPosEdit->text();
-  string zticsEndPos = zticsEndPosEdit->text();
-  string zticsLabelsPos = zticsLabelsPosEdit->text();
+  string zticsStartPos = zticsStartPosEdit->text().ascii();
+  string zticsIncPos = zticsIncPosEdit->text().ascii();
+  string zticsEndPos = zticsEndPosEdit->text().ascii();
+  string zticsLabelsPos = zticsLabelsPosEdit->text().ascii();
 
   gnuInt->setZticsMirror(zticsMirror);
   gnuInt->setZticsRotation(zticsRotation);
@@ -436,9 +436,9 @@
   if (x2ticsOnRButton->isChecked() == FALSE)
     gnuInt->setX2ticsOnFlag(0);
 
-  string x2ticsLocation = x2ticsLocationCBox->currentText();
-  string x2ticsMirror = x2ticsMirrorCBox->currentText();
-  string x2ticsRotation = x2ticsRotationCBox->currentText();
+  string x2ticsLocation = x2ticsLocationCBox->currentText().ascii();
+  string x2ticsMirror = x2ticsMirrorCBox->currentText().ascii();
+  string x2ticsRotation = x2ticsRotationCBox->currentText().ascii();
 
   string x2ticsPositionType;
 
@@ -448,10 +448,10 @@
   if (x2ticsLabelPosRButton->isChecked() == TRUE)
     x2ticsPositionType = "LABELS";
 
-  string x2ticsStartPos = x2ticsStartPosEdit->text();
-  string x2ticsIncPos = x2ticsIncPosEdit->text();
-  string x2ticsEndPos = x2ticsEndPosEdit->text();
-  string x2ticsLabelsPos = x2ticsLabelsPosEdit->text();
+  string x2ticsStartPos = x2ticsStartPosEdit->text().ascii();
+  string x2ticsIncPos = x2ticsIncPosEdit->text().ascii();
+  string x2ticsEndPos = x2ticsEndPosEdit->text().ascii();
+  string x2ticsLabelsPos = x2ticsLabelsPosEdit->text().ascii();
 
   gnuInt->setX2ticsLocation(x2ticsLocation);
   gnuInt->setX2ticsMirror(x2ticsMirror);
@@ -469,9 +469,9 @@
   if (y2ticsOnRButton->isChecked() == FALSE)
     gnuInt->setY2ticsOnFlag(0);
 
-  string y2ticsLocation = y2ticsLocationCBox->currentText();
-  string y2ticsMirror = y2ticsMirrorCBox->currentText();
-  string y2ticsRotation = y2ticsRotationCBox->currentText();
+  string y2ticsLocation = y2ticsLocationCBox->currentText().ascii();
+  string y2ticsMirror = y2ticsMirrorCBox->currentText().ascii();
+  string y2ticsRotation = y2ticsRotationCBox->currentText().ascii();
 
   string y2ticsPositionType;
 
@@ -481,10 +481,10 @@
   if (y2ticsLabelPosRButton->isChecked() == TRUE)
     y2ticsPositionType = "LABELS";
 
-  string y2ticsStartPos = y2ticsStartPosEdit->text();
-  string y2ticsIncPos = y2ticsIncPosEdit->text();
-  string y2ticsEndPos = y2ticsEndPosEdit->text();
-  string y2ticsLabelsPos = y2ticsLabelsPosEdit->text();
+  string y2ticsStartPos = y2ticsStartPosEdit->text().ascii();
+  string y2ticsIncPos = y2ticsIncPosEdit->text().ascii();
+  string y2ticsEndPos = y2ticsEndPosEdit->text().ascii();
+  string y2ticsLabelsPos = y2ticsLabelsPosEdit->text().ascii();
 
   gnuInt->setY2ticsLocation(y2ticsLocation);
   gnuInt->setY2ticsMirror(y2ticsMirror);
