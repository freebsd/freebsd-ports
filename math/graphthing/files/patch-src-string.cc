--- src/string.cc.orig	Fri Oct 25 16:04:09 2002
+++ src/string.cc	Fri Oct 25 16:09:45 2002
@@ -38,7 +38,7 @@
 	strcpy (data, s);
 }
 
-String::StringRep::StringRep (const string &s)
+String::StringRep::StringRep (const std::string &s)
 {
 	len = s.size ();
 	size = (len + 8) & ~7;
@@ -71,7 +71,7 @@
 	++rep->ref;
 }
 
-String::String (const string &s)
+String::String (const std::string &s)
 {
 	rep = new StringRep (s);
 	++rep->ref;
@@ -156,9 +156,9 @@
 	return rep->data;
 }
 
-string String::std_str () const
+std::string String::std_str () const
 {
-	return string (rep->data);
+	return std::string (rep->data);
 }
 
 bool String::empty () const
