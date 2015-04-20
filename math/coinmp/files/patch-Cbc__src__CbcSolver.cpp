--- Cbc/src/CbcSolver.cpp.orig	2011-12-23 05:36:33 UTC
+++ Cbc/src/CbcSolver.cpp
@@ -1876,10 +1876,6 @@ int CbcMain1 (int argc, const char *argv
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
