--- jit/jit/wp_client.cpp.orig	2004-11-10 18:23:27.000000000 +0000
+++ jit/jit/wp_client.cpp	2007-10-31 03:39:39.000000000 +0000
@@ -152,22 +152,31 @@
   
   switch(ev->getReason()){
   case DisconnectedEvent::FAILED_BADUSERNAME:
+    {
     e = (terror){400,"Bad username"};
+    }
     break;
 
   case DisconnectedEvent::FAILED_TURBOING:
+    {
     e = (terror){503,"Turboing, connect later"};
+    }
     break;
 
   case DisconnectedEvent::FAILED_BADPASSWORD:
+    {
     e = (terror){400,"Bad (non mismatched) registration password"};
+    }
     break;
 
   case DisconnectedEvent::FAILED_MISMATCH_PASSWD:
+    {
     e = (terror){401,"Password does not match"};
+    }
     break;
 
   case DisconnectedEvent::FAILED_DUALLOGIN: {
+    {
     /* maybe we should explicitly notify due importance */
     char *body=LNG_DUAL_LOGIN;
 
@@ -180,21 +189,28 @@
     it_deliver(sesja->ti,msg);
 
     e = (terror){409,"Dual login"};
+    }
     break;
   }
 
   case DisconnectedEvent::FAILED_LOWLEVEL:
+    {
     e = (terror){502,"Low level network error"};
+    }
     break;
 
   case DisconnectedEvent::REQUESTED:
+    {
     log_debug(ZONE,"Disconnected on request");
     e = (terror){0,""};
+    }
     break;    
 
   case DisconnectedEvent::FAILED_UNKNOWN:
   default:
+    {
     e = (terror){502,"Disconnected by unknown reason"};
+    }
     break;
   }
   
