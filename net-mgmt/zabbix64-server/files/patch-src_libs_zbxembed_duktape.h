--- src/libs/zbxembed/duktape.h.orig	2022-02-14 01:54:29.000000000 -0800
+++ src/libs/zbxembed/duktape.h	2022-02-15 13:48:15.058093000 -0800
@@ -160,7 +160,7 @@
 #if !defined(DUKTAPE_H_INCLUDED)
 #define DUKTAPE_H_INCLUDED
 
-#define DUK_SINGLE_FILE
+#undef DUK_SINGLE_FILE
 
 /*
  *  BEGIN PUBLIC API
