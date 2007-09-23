--- common/video/iso-mpeg4/src/type_basic.cpp.orig	2007-09-23 17:04:08.000000000 -0400
+++ common/video/iso-mpeg4/src/type_basic.cpp	2007-09-23 17:04:39.000000000 -0400
@@ -317,10 +317,12 @@
 	iHalfY = m_vctTrueHalfPel.y - iMVY * 2;
 }
 
+/*
 Void CMotionVector::setToZero (Void)
 {
 	memset (this, 0, sizeof (*this));
 }
+*/
 
 // RRV insertion
 Void CMotionVector::scaleup ()
