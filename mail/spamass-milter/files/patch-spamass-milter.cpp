Index: spamass-milter.cpp
diff -u spamass-milter.cpp.orig spamass-milter.cpp
--- spamass-milter.cpp.orig	Sat Feb  5 16:03:22 2005
+++ spamass-milter.cpp	Fri Mar 24 11:10:53 2006
@@ -678,9 +678,16 @@
   if (header[field_end-1] == '\r')
   	field_end--;
 
-  //  Maybe remove the whitespace picked up when a header wraps - this
-  //  might actually be a requirement
-  return header.substr( field_start, field_end - field_start );
+  string data = header.substr( field_start, field_end - field_start );
+ 
+  /* Replace all CRLF pairs with LF */
+  idx = 0;
+  while ( (idx = data.find("\r\n", idx)) != string::npos )
+  {
+       data.replace(idx,2,"\n");
+  }
+
+  return data;
 }
 
 
