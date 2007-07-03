--- ./incu/incu/time.hh.orig	2001-09-24 22:26:52.000000000 +0800
+++ ./incu/incu/time.hh	2007-07-03 16:56:32.818772107 +0800
@@ -27,6 +27,8 @@
 
     friend std::ostream& operator << (std::ostream& out, const Time& t);
   };
+
+  std::ostream& operator << (std::ostream& out, const Time& t);
 };
 
 #endif // INCU_TIME
