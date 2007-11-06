--- hpp/pktbase.hpp.orig	2007-11-05 16:01:21.000000000 +0600
+++ hpp/pktbase.hpp	2007-11-05 16:01:27.000000000 +0600
@@ -30,7 +30,7 @@
    int CopyTail(FILE *tf);
    int CopyMessages(FILE *tf);
    int CopyOneMessage(FILE *tf);
-   int PKTBASE::ReadHeader(FILE *tf, char *Buff);
+   int ReadHeader(FILE *tf, char *Buff);
 public:
    int WriteOneMsg(unsigned int Num, cMSG &m);
    PKTBASE();
