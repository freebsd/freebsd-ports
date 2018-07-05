Fix build with Clang6: stringstream doesn't have a viable overload
for ostream::operator<< . It does with Clang5. Use str() explicitly.

--- src/datefilter.cpp.orig	2018-07-04 11:23:09 UTC
+++ src/datefilter.cpp
@@ -130,9 +130,10 @@ string DateFilter::getStartDateAsString () const
   strftime (strbuf, sizeof (strbuf), "%Y-%m-%d", localtime (&_date_start));
   s << strbuf;
 
-  DEBUG (DEBUG8, "[" << this << "->" << __FUNCTION__ << "] = " << s);
+  string r = s.str ();
+  DEBUG (DEBUG8, "[" << this << "->" << __FUNCTION__ << "] = " << r);
 
-  return s.str ();
+  return r;
 }
 
 string DateFilter::getEndDateAsString () const
@@ -143,7 +144,8 @@ string DateFilter::getEndDateAsString () const
   strftime (strbuf, sizeof (strbuf), "%Y-%m-%d", localtime (&_date_end));
   s << strbuf;
 
-  DEBUG (DEBUG8, "[" << this << "->" << __FUNCTION__ << "] = " << s);
+  string r = s.str ();
+  DEBUG (DEBUG8, "[" << this << "->" << __FUNCTION__ << "] = " << r);
 
-  return s.str ();
+  return r;
 }
