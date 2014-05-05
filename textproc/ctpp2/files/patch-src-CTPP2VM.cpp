--- src/CTPP2VM.cpp.orig	2012-08-02 11:22:44.000000000 +0400
+++ src/CTPP2VM.cpp	2014-05-02 18:06:25.521278402 +0400
@@ -1440,7 +1440,7 @@
 
                                             if (oRegs[iSrcReg].GetType() == CDT::HASH_VAL)
                                             {
-                                                CDT::Iterator it = oRegs[iSrcReg].Begin();
+                                                CDTIterator it = oRegs[iSrcReg].Begin();
                                                 for (INT_32 iI = 0; iI < iIdx; ++iI) { ++it; }
 #ifdef _DEBUG
 fprintf(stderr, "(`%s`): %s\n", it->first.c_str(), it->second.GetString().c_str());
