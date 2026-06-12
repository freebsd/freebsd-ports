Fix conflicting types between declaration and implementation for
gavl_http_response_get_status_int().

http.c:595:11: error: conflicting types for 'gavl_http_response_from_string'
  595 | const int gavl_http_response_from_string(gavl_dictionary_t * res, const char * buf)
      |           ^
../include/gavl/http.h:120:5: note: previous declaration is here
  120 | int gavl_http_response_from_string(gavl_dictionary_t * res, const char * buf);
      |     ^
http.c:634:5: error: conflicting types for 'gavl_http_response_get_status_int'
  634 | int gavl_http_response_get_status_int(const gavl_dictionary_t * res)
      |     ^
../include/gavl/http.h:133:11: note: previous declaration is here
  133 | const int gavl_http_response_get_status_int(const gavl_dictionary_t * res);
      |           ^

--- gavl/http.c.orig	2026-06-03 09:06:45 UTC
+++ gavl/http.c
@@ -631,7 +631,7 @@ const char * gavl_http_response_get_protocol(const gav
   return gavl_dictionary_get_string(res, GAVL_HTTP_META_PROTOCOL);
   }
 
-int gavl_http_response_get_status_int(const gavl_dictionary_t * res)
+const int gavl_http_response_get_status_int(const gavl_dictionary_t * res)
   {
   int ret = 0;
   gavl_dictionary_get_int(res, GAVL_HTTP_META_STATUS_INT, &ret);
