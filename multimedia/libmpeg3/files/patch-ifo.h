--- ifo.h.orig
+++ ifo.h
@@ -15,6 +15,8 @@
 #define IFO_OFFSET_SUBPIC	0x0250
 
 
+typedef off_t __off64_t;
+
 // for debug and error output
 
 /**
