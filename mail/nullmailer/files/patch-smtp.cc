--- protocols/smtp.cc
+++ protocols/smtp.cc
@@ -120,9 +120,8 @@
   docmd("DATA", 300);
   mystring tmp;
   while(msg->getline(tmp)) {
-    if((tmp[0] == '.' && tmp[1] == 0 && !(out << ".")) ||
-       !(out << tmp << "\r\n"))
-      exit(ERR_MSG_WRITE);
+    if(tmp[0] == '.' && !(out << ".")) exit(ERR_MSG_WRITE);
+    if(!(out << tmp << "\r\n")) exit(ERR_MSG_WRITE);
   }
   docmd(".", 200);
 }
