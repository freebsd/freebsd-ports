--- ./src/str.cpp.orig	2014-04-08 16:53:53.954118000 +0200
+++ ./src/str.cpp	2014-04-08 16:58:59.524163473 +0200
@@ -180,7 +180,7 @@
   ArrayGuard<char> guard( r);
   r[len]=0;
   for(unsigned i=0;i<len;i++)
-    r[i]=toupper(sCStr[i]);
+    r[i]=std::toupper(sCStr[i]);
   return string(r);
 }
 void StrUpCaseInplace( string& s)
@@ -191,7 +191,7 @@
 //   ArrayGuard<char> guard( r);
 //   r[len]=0;
   for(unsigned i=0;i<len;i++)
-    s[i]=toupper(s[i]);
+    s[i]=std::toupper(s[i]);
 //   return string(r);
 }
 
@@ -203,7 +203,7 @@
   ArrayGuard<char> guard( r);
   r[len]=0;
   for(unsigned i=0;i<len;i++)
-    r[i]=tolower(sCStr[i]);
+    r[i]=std::tolower(sCStr[i]);
   return string(r);
 }
 void StrLowCaseInplace(string& s)
@@ -211,7 +211,7 @@
   unsigned len=s.length();
 //   char const *sCStr=s.c_str();
   for(unsigned i=0;i<len;i++)
-    s[i]=tolower(s[i]);
+    s[i]=std::tolower(s[i]);
 //     s[i]=tolower(sCStr[i]);
 }
 
