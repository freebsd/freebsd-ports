--- src/pythongdl.cpp.orig	Mon Oct 17 10:22:04 2005
+++ src/pythongdl.cpp	Mon Oct 31 10:59:22 2005
@@ -362,7 +362,7 @@
       if( !success) goto ret;
       
       // build the environment
-      EnvT  e( interpreter, NULL, sub);
+      EnvT  e( (EnvT*)interpreter, (DSub*)NULL, (BaseGDL**)sub);
 
       // copy arguments
       success = CopyArgFromPython( parRef, kwRef, e, argTuple, kwDict);
