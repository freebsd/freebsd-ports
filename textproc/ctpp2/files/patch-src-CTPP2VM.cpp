--- src/CTPP2VM.cpp.orig	2012-08-02 07:22:44 UTC
+++ src/CTPP2VM.cpp
@@ -1440,7 +1440,7 @@ fprintf(stderr, "0x%08X MOVIREG   %cR, %cR[%cR] ", iIP
 
                                             if (oRegs[iSrcReg].GetType() == CDT::HASH_VAL)
                                             {
-                                                CDT::Iterator it = oRegs[iSrcReg].Begin();
+                                                CDTIterator it = oRegs[iSrcReg].Begin();
                                                 for (INT_32 iI = 0; iI < iIdx; ++iI) { ++it; }
 #ifdef _DEBUG
 fprintf(stderr, "(`%s`): %s\n", it->first.c_str(), it->second.GetString().c_str());
