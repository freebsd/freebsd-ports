--- io/hpiod/mlc.cpp.orig	Tue May 23 15:27:16 2006
+++ io/hpiod/mlc.cpp	Tue May 23 15:29:40 2006
@@ -73,6 +73,7 @@
    MLCError *pError;
    MlcChannel *pC;
    int i, len, size;
+   static int cnt=0;
 
    pCmd = (MLCCmd *)buf;
 
@@ -122,7 +123,7 @@
          MlcForwardReply(fd, (unsigned char *)pCreditReply, sizeof(MLCCreditReply)); 
          break;
       case MLC_CREDIT_REQUEST:
-         static int cnt=0;
+	 cnt = 0;
          pCreditReq = (MLCCreditRequest *)buf;
          if (cnt++ < 5)         
             syslog(LOG_ERR, "unexpected MLCCreditRequest: cmd=%x, hid=%x, pid=%x, credit=%d: %s %d\n", pCreditReq->cmd,
