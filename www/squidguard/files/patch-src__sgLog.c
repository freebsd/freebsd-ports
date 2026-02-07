--- src/sgLog.c.orig	2007-11-16 16:58:32 UTC
+++ src/sgLog.c
@@ -2,7 +2,7 @@
   By accepting this notice, you agree to be bound by the following
   agreements:
   
-  This software product, squidGuard, is copyrighted (C) 1998-2007
+  This software product, squidGuard, is copyrighted (C) 1998-2009
   by Christine Kronberg, Shalla Secure Services. All rights reserved.
  
   This program is free software; you can redistribute it and/or modify it
@@ -55,8 +55,8 @@ void sgLog(log, format, va_alist)
   char msg[MAX_BUF];
   va_list ap;
   VA_START(ap, format);
-  if(vsprintf(msg, format, ap) > (MAX_BUF - 1)) 
-    fprintf(stderr,"overflow in vsprintf (sgLog): %s",strerror(errno));
+  if(vsnprintf(msg, MAX_BUF, format, ap) > (MAX_BUF - 1)) 
+    fprintf(stderr,"overflow in vsnprintf (sgLog): %s",strerror(errno));
   va_end(ap);
   date = niso(0);
   if(globalDebug || log == NULL) {
@@ -87,8 +87,8 @@ void sgLogError(format, va_alist)
   char msg[MAX_BUF];
   va_list ap;
   VA_START(ap, format);
-  if(vsprintf(msg, format, ap) > (MAX_BUF - 1)) 
-    sgLogFatalError("overflow in vsprintf (sgLogError): %s",strerror(errno));
+  if(vsnprintf(msg, MAX_BUF, format, ap) > (MAX_BUF - 1)) 
+    sgLog(globalErrorLog, "overflow in vsnprintf (sgLogError): %s",strerror(errno));
   va_end(ap);
   sgLog(globalErrorLog,"%s",msg);
 }
@@ -104,8 +104,8 @@ void sgLogFatalError(format, va_alist)
   char msg[MAX_BUF];
   va_list ap;
   VA_START(ap, format);
-  if(vsprintf(msg, format, ap) > (MAX_BUF - 1)) 
-    return;
+  if(vsnprintf(msg, MAX_BUF, format, ap) > (MAX_BUF - 1)) 
+    sgLog(globalErrorLog, "overflow in vsnprintf (sgLogError): %s",strerror(errno));
   va_end(ap);
   sgLog(globalErrorLog,"%s",msg);
   sgEmergency();
