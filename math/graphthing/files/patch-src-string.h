--- src/string.h.orig	Tue Feb 12 05:28:42 2002
+++ src/string.h	Fri Oct 25 13:44:29 2002
@@ -23,7 +23,7 @@
 		StringRep ();
 		StringRep (unsigned int n);
 		StringRep (const char *s);
-		StringRep (const string &s);
+		StringRep (const std::string &s);
 		~StringRep ();
 	};
 
@@ -34,7 +34,7 @@
 public:
 	String ();
 	String (const char *s);
-	String (const string &s);
+	String (const std::string &s);
 	String (const String &s);
 	~String ();
 
@@ -43,7 +43,7 @@
 	int compare (const char *s) const;
 	int compare (const String &s) const;
 	const char *c_str () const;
-	string std_str () const;
+	std::string std_str () const;
 	bool empty () const;
 
 	String &operator= (const String &other);
@@ -57,7 +57,7 @@
 	char &operator[] (unsigned int i);
 	const char &operator[] (unsigned int i) const;
 
-	friend ostream &operator<< (ostream &o, const String &s);
+	friend std::ostream &operator<< (std::ostream &o, const String &s);
 };
 
 
