--- src/fco/parsergenreutil.h.orig	2011-11-21 17:06:56.000000000 +0100
+++ src/fco/parsergenreutil.h	2014-06-15 01:55:46.000000000 +0200
@@ -53,6 +53,7 @@ class cFCOName;
 class iParserGenreUtil
 {
 public:
+    virtual ~iParserGenreUtil() {}
     virtual bool MapStringToProperty( const TSTRING& str, int& propIndex ) const = 0;
         // maps the given string  to an index into a property vector for the genre
     virtual void AddSubTypeProps( cFCOPropVector& v ) const = 0;
