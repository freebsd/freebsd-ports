--- src/string.cxx.orig	Sun Dec 15 09:27:00 2002
+++ src/string.cxx	Sun Dec 15 09:27:20 2002
@@ -574,7 +574,7 @@
 
 // can this be const STRING& ?
 ostream& operator<<(ostream& os, const STRING& str) {
-  os.write(str.Buffer, str.Length);
+  os.write((char*)str.Buffer, str.Length);
   return os;
 }
 
