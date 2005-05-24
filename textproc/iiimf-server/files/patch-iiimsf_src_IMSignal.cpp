--- iiimsf/src/IMSignal.cpp.orig	Mon May  9 18:00:02 2005
+++ iiimsf/src/IMSignal.cpp	Mon May  9 18:00:45 2005
@@ -66,11 +66,8 @@
     stringstream s;
     string spid, signum;
 
-    s << getpid();
-    spid = s.str();
-    s.str("");
-    s << num;
-    signum = s.str();
+    s << getpid() << " " << num;
+    s >> spid >> signum;
 
     in_segv++;
 
