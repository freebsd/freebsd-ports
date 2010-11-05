--- src/CLucene/jstreams/stringreader.h	Sat Feb 10 13:56:34 2007
+++ src/CLucene/jstreams/stringreader.h.orig	Sat Nov 25 11:03:58 2006
@@ -1,6 +1,18 @@
+/*------------------------------------------------------------------------------
+* Copyright (C) 2003-2006 Jos van den Oever
+* 
+* Distributable under the terms of either the Apache License (Version 2.0) or 
+* the GNU Lesser General Public License, as specified in the COPYING file.
+------------------------------------------------------------------------------*/
 #ifndef STRINGREADER_H
 #define STRINGREADER_H
 
+/**
+ * Author: Jos van den Oever
+ *         Ben van Klinken
+ **/
+
+
 #include "streambase.h"
 
 namespace jstreams {
@@ -18,18 +30,18 @@
     ~StringReader();
     int32_t read(const T*& start, int32_t min, int32_t max);
     int64_t skip(int64_t ntoskip);
-    int64_t mark(int32_t readlimit);
     int64_t reset(int64_t pos);
 };
 
+typedef StringReader<char> StringInputStream;
+
 template <class T>
 StringReader<T>::StringReader(const T* value, int32_t length, bool copy)
         : markpt(0), dataowner(copy) {
     if (length < 0) {
-        if (sizeof(T) > 1) {
-            length = wcslen((const wchar_t*)value);
-        } else {
-            length = strlen((const char*)value);
+        length = 0;
+        while (value[length] != '\0') {
+            length++;
         }
     }
     StreamBase<T>::size = length;
@@ -71,12 +83,6 @@
 StringReader<T>::skip(int64_t ntoskip) {
     const T* start;
     return read(start, ntoskip, ntoskip);
-}
-template <class T>
-int64_t
-StringReader<T>::mark(int32_t /*readlimit*/) {
-    markpt = StreamBase<T>::position;
-    return markpt;
 }
 template <class T>
 int64_t
