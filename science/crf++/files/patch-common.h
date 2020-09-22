--- common.h.orig	2020-09-22 21:00:58 UTC
+++ common.h
@@ -211,7 +211,7 @@ class string_buffer: public std::string {
   string_buffer& operator<<(int _n)                { _ITOA(_n); }
   string_buffer& operator<<(long int _n)           { _ITOA(_n); }
   string_buffer& operator<<(unsigned short int _n) { _UITOA(_n); }
-  string_buffer& operator<<(unsigned int _n)       { _UITOA(_n); }
+  // string_buffer& operator<<(unsigned int _n)       { _UITOA(_n); }
   //  string_buffer& operator<<(unsigned long int _n)  { _UITOA(_n); }
   string_buffer& operator<<(size_t _n)             { _UITOA(_n); }
   string_buffer& operator<<(char _n) {
