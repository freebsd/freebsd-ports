--- io/hpiod/dot4.cpp.orig	Tue May 23 15:30:04 2006
+++ io/hpiod/dot4.cpp	Tue May 23 15:32:37 2006
@@ -78,6 +78,7 @@
    Dot4Channel *pC=NULL;
    int i, len, size;
    unsigned char socket;
+   static int cnt=0;
 
    pCmd = (DOT4Cmd *)buf;
 
@@ -130,7 +131,7 @@
          Dot4ForwardReply(fd, (unsigned char *)pCreditReply, sizeof(DOT4CreditReply)); 
          break;
       case DOT4_CREDIT_REQUEST:
-         static int cnt=0;
+         cnt=0;
          pCreditReq = (DOT4CreditRequest *)buf;
          if (cnt++ < 5)         
             syslog(LOG_ERR, "unexpected DOT4CreditRequest: cmd=%x, hid=%x, pid=%x, maxcredit=%d: %s %d\n", pCreditReq->cmd,
