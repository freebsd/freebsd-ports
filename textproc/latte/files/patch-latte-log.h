--- latte-log.h.orig	Fri Oct 22 13:02:36 1999
+++ latte-log.h	Fri Mar 19 01:17:52 2004
@@ -21,7 +21,7 @@
 # define LATTE_LOG_H
 
 #include <latte.h>
-#include <iostream.h>
+#include <iostream>
 
 enum LatteLogFlags {
   latte_log_EVAL =  1 << 0,
@@ -30,8 +30,8 @@
 
 extern unsigned long latte_log_flags;
 
-class DevNull : public ostream {
-  class DevNullBuf : public streambuf {
+class DevNull : public std::ostream {
+  class DevNullBuf : public std::streambuf {
    public:
     DevNullBuf();
 
@@ -42,13 +42,13 @@
   };
 
  public:
-  DevNull() : ostream(0) { ostream::init(&buf); }
+  DevNull() : std::ostream(0) { std::ostream::init(&buf); }
 
  private:
   DevNullBuf buf;
 };
 
-extern ostream &LatteLog(unsigned long = ~((unsigned long) 0));
-extern ostream &LatteLog(unsigned long, const Latte_FileLoc &);
+extern std::ostream &LatteLog(unsigned long = ~((unsigned long) 0));
+extern std::ostream &LatteLog(unsigned long, const Latte_FileLoc &);
 
 #endif // LATTE_LOG_H
