--- src/string_utils.h~	2013-06-01 23:10:50.000000000 +0300
+++ src/string_utils.h	2013-06-01 22:56:43.000000000 +0300
@@ -28,6 +28,9 @@
 #  define STRSTREAM
 #endif  
 
+typedef std::vector<std::string> vec_string;
+std::ostream& operator<<( std::ostream& out, const vec_string &v );
+
 std::string toupper( std::string s );
 std::string strip( const std::string& str, const std::string& what = " \t\n\0" );
 bool is_int( const std::string &s );
