This looks like a gcc 4.2.1 bug.
--- Cbc/src/CbcSolver.cpp.orig	2011-12-23 10:36:33.000000000 -0500
+++ Cbc/src/CbcSolver.cpp	2011-12-23 10:41:57.000000000 -0500
@@ -1665,10 +1665,6 @@
 	    }
 	    sprintf(generalPrint + strlen(generalPrint),
 		    "Build Date: %s \n", __DATE__);
-#ifdef CBC_SVN_REV
-	    sprintf(generalPrint + strlen(generalPrint),
-		    "Revision Number: %d \n", CBC_SVN_REV);
-#endif
             generalMessageHandler->message(CLP_GENERAL, generalMessages)
             << generalPrint
             << CoinMessageEol;
