--- iwebstream.C~	Tue Sep  3 01:05:42 2002
+++ iwebstream.C	Tue Sep  3 01:08:08 2002
@@ -33,7 +33,7 @@
 //#define DEBUG_TIMEOUT
 
 // The constructor.
-iwebstream::iwebstream(string url, int timeout = 30) : defaultTimeout(timeout), data(""), position(0) {
+iwebstream::iwebstream(string url, int timeout) : defaultTimeout(timeout), data(""), position(0) {
   string origurl = url;
   string method;
   string host;
@@ -424,8 +424,8 @@
 // Case is ignored in comparisions.
 // If begin is not found, return "". Move position to point to char after end;
 // If end == "" then just find begin and place position just after it
-string iwebstream::findTag(const string & begin, const string & end, const string & after = "",
-													 const string & before = "") {
+string iwebstream::findTag(const string & begin, const string & end, const string & after,
+													 const string & before) {
 	//   cout << "findTag begin=" << begin << "=" << endl
 	//        << "end=" << end << "=" << endl 
 	//        << "after=" << after << "=" << endl
