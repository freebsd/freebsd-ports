--- babble/src/txt2bits.cc.orig	Fri Feb 20 04:31:27 1998
+++ babble/src/txt2bits.cc	Thu Oct 30 18:17:38 2003
@@ -264,8 +264,7 @@
 	if (((dictRecRBT.getCount()==0)&&(getSmallMode()==FALSE))
 	|| (dictRecRAOF==NULL)||(dictRecRAOF->getCount()==0))
 	{
-		errorMsg(EMT_ERROR, "The dictionary specified is empty", "MTCtex
-tToBits::openDictName()");
+		errorMsg(EMT_ERROR, "The dictionary specified is empty", "MTCtextToBits::openDictName()");
 		return FALSE;
 	}
 
