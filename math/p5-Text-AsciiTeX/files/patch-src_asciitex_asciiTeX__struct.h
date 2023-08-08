--- src/asciitex/asciiTeX_struct.h.orig	2023-04-16 15:11:41 UTC
+++ src/asciitex/asciiTeX_struct.h
@@ -56,5 +56,5 @@ struct Tgraph {			/* the order of fields is important-
 };
 
 typedef enum {S_NOERR, S_WARN, S_ERR} STAT;
-STAT SYNTAX_ERR_FLAG;
+extern STAT SYNTAX_ERR_FLAG;
 #endif
