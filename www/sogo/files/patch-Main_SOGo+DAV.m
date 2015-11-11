--- Main/SOGo+DAV.m.orig	2015-09-16 18:41:29 UTC
+++ Main/SOGo+DAV.m
@@ -267,7 +267,7 @@
   NSObject <DOMNodeList> *list;
   NSObject <DOMNode> *valueNode;
   NSArray *elements;
-  NSString *property, *match;
+  NSString *property=nil, *match=nil;
 
   list = [searchElement getElementsByTagName: @"prop"];
   if ([list length])
