--- src/File-Date-StringUtils/Format.h.orig	Fri Apr  9 23:41:38 2004
+++ src/File-Date-StringUtils/Format.h	Fri Dec 22 16:20:15 2006
@@ -53,7 +53,7 @@
 private:
 
    template<typename T>
-   void DecimalFormat::format_internal( char* buffer, T value, std::string typeString);
+   void format_internal( char* buffer, T value, std::string typeString);
    
 
    
@@ -65,6 +65,6 @@
     text-containing string to be output on a terminal 
    */
   std::string clean( std::string s);
-
+  std::string getLengthString( int length);
 
 #endif
