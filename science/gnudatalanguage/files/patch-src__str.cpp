--- src/str.cpp.orig	2015-04-22 19:37:22 UTC
+++ src/str.cpp
@@ -178,7 +178,7 @@ string StrUpCase(const string& s)
   ArrayGuard<char> guard( r);
   r[len]=0;
   for(unsigned i=0;i<len;i++)
-    r[i]=toupper(sCStr[i]);
+    r[i]=std::toupper(sCStr[i]);
   return string(r);
 }
 void StrUpCaseInplace( string& s)
@@ -189,7 +189,7 @@ void StrUpCaseInplace( string& s)
 //   ArrayGuard<char> guard( r);
 //   r[len]=0;
   for(unsigned i=0;i<len;i++)
-    s[i]=toupper(s[i]);
+    s[i]=std::toupper(s[i]);
 //   return string(r);
 }
 
@@ -201,7 +201,7 @@ string StrLowCase(const string& s)
   ArrayGuard<char> guard( r);
   r[len]=0;
   for(unsigned i=0;i<len;i++)
-    r[i]=tolower(sCStr[i]);
+    r[i]=std::tolower(sCStr[i]);
   return string(r);
 }
 void StrLowCaseInplace(string& s)
@@ -209,7 +209,7 @@ void StrLowCaseInplace(string& s)
   unsigned len=s.length();
 //   char const *sCStr=s.c_str();
   for(unsigned i=0;i<len;i++)
-    s[i]=tolower(s[i]);
+    s[i]=std::tolower(s[i]);
 //     s[i]=tolower(sCStr[i]);
 }
 
