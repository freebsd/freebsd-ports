diff -u ticsOp.cpp.orig ticsOp.cpp
--- ticsOp.cpp.orig	Sun Jun  7 07:37:48 1998
+++ ticsOp.cpp	Thu Oct 30 21:42:04 2003
@@ -339,9 +339,9 @@
   if (xticsOnRButton->isChecked() == FALSE)
     gnuInt->setXticsOnFlag(0);
 
-  string xticsLocation = xticsLocationCBox->currentText();
-  string xticsMirror = xticsMirrorCBox->currentText();
-  string xticsRotation = xticsRotationCBox->currentText();
+  string xticsLocation = string(xticsLocationCBox->currentText());
+  string xticsMirror = string(xticsMirrorCBox->currentText());
+  string xticsRotation = string(xticsRotationCBox->currentText());
 
   string xticsPositionType;
 
@@ -351,10 +351,10 @@
   if (xticsLabelPosRButton->isChecked() == TRUE)
     xticsPositionType = "LABELS";
 
-  string xticsStartPos = xticsStartPosEdit->text();
-  string xticsIncPos = xticsIncPosEdit->text();
-  string xticsEndPos = xticsEndPosEdit->text();
-  string xticsLabelsPos = xticsLabelsPosEdit->text();
+  string xticsStartPos = string(xticsStartPosEdit->text());
+  string xticsIncPos = string(xticsIncPosEdit->text());
+  string xticsEndPos = string(xticsEndPosEdit->text());
+  string xticsLabelsPos = string(xticsLabelsPosEdit->text());
 
   gnuInt->setXticsLocation(xticsLocation);
   gnuInt->setXticsMirror(xticsMirror);
@@ -372,9 +372,9 @@
   if (yticsOnRButton->isChecked() == FALSE)
     gnuInt->setYticsOnFlag(0);
 
-  string yticsLocation = yticsLocationCBox->currentText();
-  string yticsMirror = yticsMirrorCBox->currentText();
-  string yticsRotation = yticsRotationCBox->currentText();
+  string yticsLocation = string(yticsLocationCBox->currentText());
+  string yticsMirror = string(yticsMirrorCBox->currentText());
+  string yticsRotation = string(yticsRotationCBox->currentText());
 
   string yticsPositionType;
 
@@ -384,10 +384,10 @@
   if (yticsLabelPosRButton->isChecked() == TRUE)
     yticsPositionType = "LABELS";
 
-  string yticsStartPos = yticsStartPosEdit->text();
-  string yticsIncPos = yticsIncPosEdit->text();
-  string yticsEndPos = yticsEndPosEdit->text();
-  string yticsLabelsPos = yticsLabelsPosEdit->text();
+  string yticsStartPos = string(yticsStartPosEdit->text());
+  string yticsIncPos = string(yticsIncPosEdit->text());
+  string yticsEndPos = string(yticsEndPosEdit->text());
+  string yticsLabelsPos = string(yticsLabelsPosEdit->text());
 
   gnuInt->setYticsLocation(yticsLocation);
   gnuInt->setYticsMirror(yticsMirror);
@@ -405,8 +405,8 @@
   if (zticsOnRButton->isChecked() == FALSE)
     gnuInt->setZticsOnFlag(0);
 
-  string zticsMirror = zticsMirrorCBox->currentText();
-  string zticsRotation = zticsRotationCBox->currentText();
+  string zticsMirror = string(zticsMirrorCBox->currentText());
+  string zticsRotation = string(zticsRotationCBox->currentText());
 
   string zticsPositionType;
 
@@ -416,10 +416,10 @@
   if (zticsLabelPosRButton->isChecked() == TRUE)
     zticsPositionType = "LABELS";
 
-  string zticsStartPos = zticsStartPosEdit->text();
-  string zticsIncPos = zticsIncPosEdit->text();
-  string zticsEndPos = zticsEndPosEdit->text();
-  string zticsLabelsPos = zticsLabelsPosEdit->text();
+  string zticsStartPos = string(zticsStartPosEdit->text());
+  string zticsIncPos = string(zticsIncPosEdit->text());
+  string zticsEndPos = string(zticsEndPosEdit->text());
+  string zticsLabelsPos = string(zticsLabelsPosEdit->text());
 
   gnuInt->setZticsMirror(zticsMirror);
   gnuInt->setZticsRotation(zticsRotation);
@@ -436,9 +436,9 @@
   if (x2ticsOnRButton->isChecked() == FALSE)
     gnuInt->setX2ticsOnFlag(0);
 
-  string x2ticsLocation = x2ticsLocationCBox->currentText();
-  string x2ticsMirror = x2ticsMirrorCBox->currentText();
-  string x2ticsRotation = x2ticsRotationCBox->currentText();
+  string x2ticsLocation = string(x2ticsLocationCBox->currentText());
+  string x2ticsMirror = string(x2ticsMirrorCBox->currentText());
+  string x2ticsRotation = string(x2ticsRotationCBox->currentText());
 
   string x2ticsPositionType;
 
@@ -448,10 +448,10 @@
   if (x2ticsLabelPosRButton->isChecked() == TRUE)
     x2ticsPositionType = "LABELS";
 
-  string x2ticsStartPos = x2ticsStartPosEdit->text();
-  string x2ticsIncPos = x2ticsIncPosEdit->text();
-  string x2ticsEndPos = x2ticsEndPosEdit->text();
-  string x2ticsLabelsPos = x2ticsLabelsPosEdit->text();
+  string x2ticsStartPos = string(x2ticsStartPosEdit->text());
+  string x2ticsIncPos = string(x2ticsIncPosEdit->text());
+  string x2ticsEndPos = string(x2ticsEndPosEdit->text());
+  string x2ticsLabelsPos = string(x2ticsLabelsPosEdit->text());
 
   gnuInt->setX2ticsLocation(x2ticsLocation);
   gnuInt->setX2ticsMirror(x2ticsMirror);
@@ -469,9 +469,9 @@
   if (y2ticsOnRButton->isChecked() == FALSE)
     gnuInt->setY2ticsOnFlag(0);
 
-  string y2ticsLocation = y2ticsLocationCBox->currentText();
-  string y2ticsMirror = y2ticsMirrorCBox->currentText();
-  string y2ticsRotation = y2ticsRotationCBox->currentText();
+  string y2ticsLocation = string(y2ticsLocationCBox->currentText());
+  string y2ticsMirror = string(y2ticsMirrorCBox->currentText());
+  string y2ticsRotation = string(y2ticsRotationCBox->currentText());
 
   string y2ticsPositionType;
 
@@ -481,10 +481,10 @@
   if (y2ticsLabelPosRButton->isChecked() == TRUE)
     y2ticsPositionType = "LABELS";
 
-  string y2ticsStartPos = y2ticsStartPosEdit->text();
-  string y2ticsIncPos = y2ticsIncPosEdit->text();
-  string y2ticsEndPos = y2ticsEndPosEdit->text();
-  string y2ticsLabelsPos = y2ticsLabelsPosEdit->text();
+  string y2ticsStartPos = string(y2ticsStartPosEdit->text());
+  string y2ticsIncPos = string(y2ticsIncPosEdit->text());
+  string y2ticsEndPos = string(y2ticsEndPosEdit->text());
+  string y2ticsLabelsPos = string(y2ticsLabelsPosEdit->text());
 
   gnuInt->setY2ticsLocation(y2ticsLocation);
   gnuInt->setY2ticsMirror(y2ticsMirror);
