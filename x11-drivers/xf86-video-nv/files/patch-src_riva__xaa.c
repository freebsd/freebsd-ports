# ifdef away this XAA function call as done above
#
--- src/riva_xaa.c.orig	2013-02-07 07:56:01 UTC
+++ src/riva_xaa.c
@@ -91,7 +91,9 @@ RivaSetRopPattern(RivaPtr pRiva, int rop
     if (pRiva->currentRop != (rop + 16)) {
         pRiva->currentRop = rop + 16; /* +16 is important */
         RIVA_FIFO_FREE(pRiva->riva, Rop, 1);
+#ifdef HAVE_XAA_H
         pRiva->riva.Rop->Rop3 = XAAGetPatternROP(rop);
+#endif
     }
 }
 #ifdef HAVE_XAA_H
