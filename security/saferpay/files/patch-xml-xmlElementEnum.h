--- saferpay/xml/xmlElementEnum.h.orig	Mon Sep  9 21:43:38 2002
+++ saferpay/xml/xmlElementEnum.h	Mon Sep  9 21:43:41 2002
@@ -11,7 +11,7 @@
 
 class xmlElementEnum : public SxObject
 {
-	friend xmlElement;
+	friend class xmlElement;
 
 public:
 	xmlElementEnum() : SxObject() {;}
