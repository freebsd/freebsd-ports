--- searcher.c.orig	Wed Sep 17 17:49:46 2003
+++ searcher.c	Thu Jun 24 11:46:14 2004
@@ -27,6 +27,7 @@
 #include <errno.h>
 #include "sary.h"
 #include "ruby.h"
+#include "version.h"
 
 #define GET_Searcher(obj, dat) Data_Get_Struct(obj, SarySearcher, dat)
 
@@ -76,14 +77,24 @@
   
     rb_scan_args(argc, argv, "11", &file_name, &array_name);
 
+#if RUBY_VERSION_CODE < 180
     Check_SafeStr(file_name);
     file_name_ptr = STR2CSTR(file_name);
+#else
+    SafeStringValue(file_name);
+    file_name_ptr = RSTRING(file_name)->ptr;
+#endif
   
     if (array_name == Qnil)
         searcher = sary_searcher_new(file_name_ptr);
     else {
+#if RUBY_VERSION_CODE < 180
         Check_SafeStr(array_name);
         array_name_ptr = STR2CSTR(array_name);
+#else
+        SafeStringValue(array_name);
+        array_name_ptr = RSTRING(array_name)->ptr;
+#endif
         searcher = sary_searcher_new2(file_name_ptr, array_name_ptr);
     }
     if (searcher == NULL)
@@ -118,8 +129,14 @@
 
     GET_Searcher(klass, searcher);
 
+#if RUBY_VERSION_CODE < 180
     Check_SafeStr(pattern);
     pat = str2cstr(pattern, &len);
+#else
+    SafeStringValue(pattern);
+    pat = RSTRING(pattern)->ptr;
+    len = RSTRING(pattern)->len;
+#endif
 
     if (sary_searcher_search2(searcher, pat, len))
 	return Qtrue;
@@ -145,8 +162,13 @@
     pat = ALLOCA_N(char*, len);
     for (i = 0; i < len; i++) {
 	pattern = rb_ary_entry(pattern_array, (long)i);
+#if RUBY_VERSION_CODE < 180
 	Check_SafeStr(pattern);
 	pat[i] = STR2CSTR(pattern);
+#else
+	SafeStringValue(pattern);
+	pat[i] = RSTRING(pattern)->ptr;
+#endif
     }
 
     if (sary_searcher_multi_search(searcher, pat, len))
@@ -164,8 +186,13 @@
 
     GET_Searcher(klass, searcher);
 
+#if RUBY_VERSION_CODE < 180
     Check_SafeStr(pattern);
     pat = STR2CSTR(pattern);
+#else
+    SafeStringValue(pattern);
+    pat = RSTRING(pattern)->ptr;
+#endif
 
     if (sary_searcher_isearch(searcher, pat, NUM2INT(len)))
 	return Qtrue;
@@ -194,8 +221,14 @@
 
     GET_Searcher(klass, searcher);
 
+#if RUBY_VERSION_CODE < 180
     Check_SafeStr(pattern);
     pat = str2cstr(pattern, &len);
+#else
+    SafeStringValue(pattern);
+    pat = RSTRING(pattern)->ptr;
+    len = RSTRING(pattern)->len;
+#endif
 
     if (sary_searcher_icase_search2(searcher, pat, len))
 	return Qtrue;
@@ -239,10 +272,19 @@
     if (sary_searcher_count_occurrences(searcher) == 0)
   	return Qnil;
 
+#if RUBY_VERSION_CODE < 180
     Check_SafeStr(start_tag);
     Check_SafeStr(end_tag);
     stag = rb_str2cstr(start_tag, &slen);
     etag = rb_str2cstr(end_tag, &elen);
+#else
+    SafeStringValue(start_tag);
+    SafeStringValue(end_tag);
+    stag = RSTRING(start_tag)->ptr;
+    slen = RSTRING(start_tag)->len;
+    etag = RSTRING(end_tag)->ptr;
+    elen = RSTRING(end_tag)->len;
+#endif
 
     region = sary_searcher_get_next_tagged_region2(searcher, stag, slen,
 					    etag, elen, &rlen);
