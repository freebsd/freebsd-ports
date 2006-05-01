--- XMLParser.H.orig	Sun Apr 30 18:27:46 2006
+++ XMLParser.H	Sun Apr 30 18:28:29 2006
@@ -140,6 +140,9 @@
   bool inFolder;
   bool inDesc;
   bool inTitle;
+  bool inAdded;
+  bool inVisited;
+  bool inModified;
 	
 public:
 
@@ -152,6 +155,9 @@
     inFolder = false;
     inDesc = false;
     inTitle = false;
+    inAdded = false;
+    inVisited = false;
+    inModified = false;
   };
   
   XBELParser(referenceTree * r) {
@@ -165,6 +171,9 @@
     inFolder = false;
     inDesc = false;
     inTitle = false;
+    inAdded = false;
+    inVisited = false;
+    inModified = false;
   };
 	
   void startTag(string &tagName, map<string,string> & attributes);
