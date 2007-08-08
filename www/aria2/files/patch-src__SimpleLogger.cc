--- ./src/SimpleLogger.cc.orig	2007-06-12 14:50:40.000000000 +0400
+++ ./src/SimpleLogger.cc	2007-08-06 22:43:59.000000000 +0400
@@ -41,6 +41,14 @@
 #include <stdio.h>
 #include <errno.h>
 
+#if !defined(va_copy)
+# if defined(__va_copy)
+#  define va_copy(dest, src) __va_copy(dest, src)
+# else
+#  define va_copy(dest, src) (dest = src)
+# endif
+#endif
+
 #define WRITE_LOG(LEVEL, MSG) \
 va_list ap;\
 va_start(ap, MSG);\
@@ -86,6 +94,8 @@
 
 void SimpleLogger::writeLog(FILE* file, int level, const char* msg, va_list ap, Exception* e, bool printHeader) const
 {
+  va_list apCopy;
+  va_copy(apCopy, ap);
   string levelStr;
   switch(level) {
   case Logger::DEBUG:
@@ -114,7 +124,7 @@
   if(printHeader) {
     writeHeader(file, datestr, levelStr);
   }
-  vfprintf(file, string(Util::replace(msg, "\r", "")+"\n").c_str(), ap);
+  vfprintf(file, string(Util::replace(msg, "\r", "")+"\n").c_str(), apCopy);
   for(Exception* nestedEx = e; nestedEx; nestedEx = nestedEx->getCause()) {
     // TODO a quick hack not to print header in console
     if(printHeader) {
@@ -123,6 +133,7 @@
     fprintf(file, "exception: %s\n", Util::replace(nestedEx->getMsg(), "\r", "").c_str());
   }
   fflush(file);
+  va_end(apCopy);
 }
 
 void SimpleLogger::writeFile(int level, const char* msg, va_list ap, Exception* e) const {
