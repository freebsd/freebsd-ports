--- netscript.c.orig	2002-10-08 02:59:06 UTC
+++ netscript.c
@@ -633,7 +633,7 @@ U SH isudp=0;
 U SH isudpr=0;
 U SH isvhost=0;
 U SH lnum=0;
-U SH log=0;
+U SH islog=0;
 U SH nofrom=0;
 U SH norrecv=0;
 U SH norsend=0;
@@ -1551,7 +1551,7 @@ V wro(C *output,U I size,U SH io){
   /* make sure the socket is really there. */
   IF(SE((sock+1),0,&cfd,0,&tv)>0) 
    WR(sock,output,size);
-  IF(log&&tnetraw)
+  IF(islog&&tnetraw)
    logdata(output,3);
  }
  IF(setroute){
@@ -1978,7 +1978,7 @@ V dumpexecline(C *line){
   wro(dump,SL(dump),0);
   wro("\n",1,0);
   /* add the output to the log, if enabled. (-l option) */
-  IF(log&&!tnetraw)
+  IF(islog&&!tnetraw)
    logdata(dump,0);
   /* last use of dump for this run. */
   FR(dump);
@@ -2113,8 +2113,10 @@ V parsesocket(C *host,U I port){
   /* unless udp mode is active, then will rebind. */
   IF(bindmode!=2||isudp){
    /* main server sockaddr structure. */
-   (isudp?sock:ssock)=SK(AF_INET,(isudp?SOCK_DGRAM:SOCK_STREAM),(isudp?
-   IPPROTO_UDP:IPPROTO_TCP));
+   if(isudp)
+     sock=SK(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
+   else
+     ssock=SK(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    parsesocketopt(1,(isudp?sock:ssock));
    B((V *)&sns,SO(sns));
    sns.sin_family=AF_INET;
@@ -2379,7 +2381,7 @@ V parsesocket(C *host,U I port){
   }
  }
  /* states log start time, and ip that was used.  if enabled. (-l option) */
- IF(log&&!tnetraw){
+ IF(islog&&!tnetraw){
   logdata("NEW NETSCRIPT SESSION STARTED.",2);
   /* logging of the ip used. */
   logdata(
@@ -2468,7 +2470,7 @@ V parsesocket(C *host,U I port){
        pd(iread,0,columns);
       wro(iread,SL(iread),0);
       wro("\n",1,0);
-      IF(log&&!tnetraw)
+      IF(islog&&!tnetraw)
        logdata(iread,0);
      }
      FC(ifd);
@@ -2484,7 +2486,7 @@ V parsesocket(C *host,U I port){
    wro(iswrite,SL(iswrite),0);
    wro("\n",1,0);
    /* add the initial data to the log, if enabled. (-i, and -l option) */
-   IF(log&&!tnetraw)
+   IF(islog&&!tnetraw)
     logdata(iswrite,0);
   }
  }
@@ -2501,7 +2503,7 @@ V parsesocket(C *host,U I port){
   }
   /* handle incoming telnet dumping. (-y, and -Y options) */
   dumptelnet(sread);
-  IF(log&&tnetraw)
+  IF(islog&&tnetraw)
    logdata(sread,3);
   /* check, and use the ns_incoming_raw() symbol.  it passes the raw dump of */
   /* the socket read buffer, the size of the buffer, and the length of the */
@@ -2578,7 +2580,7 @@ V parsesocket(C *host,U I port){
     IF(!nosrecv)
      pd(sreadl,1,columns);
     /* add the output to the log, if enabled. (-l option) */
-    IF(log&&!tnetraw)
+    IF(islog&&!tnetraw)
      logdata(sreadl,1);
     /* reset the temporary variable. */
     IF(stoprules==2)
@@ -2705,7 +2707,7 @@ V parsesocket(C *host,U I port){
           pd(iwrite,0,columns);
          wro(iwrite,SL(iwrite),0);
          wro("\n",1,0);
-         IF(log&&!tnetraw)
+         IF(islog&&!tnetraw)
           logdata(iwrite,0);
          FC(ifd);
         }
@@ -3036,7 +3038,7 @@ V parsesocket(C *host,U I port){
        wro(swrite,SL(swrite),0);
        wro("\n",1,0);
        /* add the input to the log, if enabled. (-l option) */
-       IF(log&&!tnetraw)
+       IF(islog&&!tnetraw)
         logdata(swrite,0);
       }
      }
@@ -3400,14 +3402,14 @@ V iface(C *base){
     nsprint("logfile: can not log data to a file with privileged access.\n");
    E{
     IF(!parameter(iread,1,0x20)){
-     IF(log)
+     IF(islog)
       FR(logfile);
      parsecmdline(parm);
      IF(!(logfile=(C *)SDU(parsedline)))
       pe("iface(): duplication of memory error",1);
-     log=1;
+     islog=1;
     }
-    nsprint("logfile: %s\n",(log?logfile:IFACE_UNSET));
+    nsprint("logfile: %s\n",(islog?logfile:IFACE_UNSET));
    }
   }
 #ifdef NCURSES
@@ -3995,7 +3997,7 @@ V nsexit(SH i,U SH type){
  IF(tnetraw&&truetnet){
   nsprint("\n");
   /* same goes for logging. */
-  IF(log)
+  IF(islog)
    logdata("\n",3);
  }
  closesocket(0);
@@ -4075,7 +4077,7 @@ V gtkec(GW *gw,GW *ge){
    wro(et,SL(et),0);
    wro("\n",1,0);
    /* log if requested. */
-   IF(log)
+   IF(islog)
     logdata(et,0);
    /* reset waiting loop. */
    isguiwait=0;
@@ -4926,11 +4928,11 @@ I main(I ac,C **av){
      IF(isprivileged)
       pe("can not log data to a file with privileged access",0);
      E
-      IF(!log){
+      IF(!islog){
        parsecmdline(optarg);
        IF(!(logfile=(C *)SDU(parsedline)))
         pe("main(): duplication of memory error",1);
-       log=1;
+       islog=1;
       }
      BR;
 #ifdef GTK
