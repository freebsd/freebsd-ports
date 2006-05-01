--- XMLParser.C.orig	Sun Apr 30 18:27:46 2006
+++ XMLParser.C	Sun Apr 30 18:30:18 2006
@@ -426,6 +426,15 @@
   else if (equalNoCase(tagName,"DESC")){
     inDesc = true;
   }
+  else if (equalNoCase(tagName,"TIME_ADDED")){
+    inAdded = true;
+  }
+  else if (equalNoCase(tagName,"TIME_VISITED")){
+    inVisited = true;
+  }
+  else if (equalNoCase(tagName,"TIME_MODIFIED")){
+    inModified = true;
+  }
 	else if (equalNoCase(tagName,"BOOKMARK")){
 		map<string, string>::const_iterator i;
 		string url = "";
@@ -455,6 +464,15 @@
   else if (equalNoCase(tagName,"DESC")){
     inDesc = false;
   }
+  else if (equalNoCase(tagName,"TIME_ADDED")){
+    inAdded = false;
+  }
+  else if (equalNoCase(tagName,"TIME_VISITED")){
+    inVisited = false;
+  }
+  else if (equalNoCase(tagName,"TIME_MODIFIED")){
+    inModified = false;
+  }
   else if (equalNoCase(tagName,"FOLDER")){
     rtStack.pop_back();
     currentReferenceTree = rtStack.back();
@@ -484,6 +502,15 @@
     else if (inDesc){
       currentFolder->comment = content;
     }
+    else if (inAdded) {
+      currentFolder->creationTime = atoi(content.c_str());
+    }
+    else if (inVisited) {
+      currentFolder->visitTime = atoi(content.c_str());
+    }
+    else if (inModified) {
+      currentFolder->modifiedTime = atoi(content.c_str());
+    }
   }
   else if (inBookmark) {
     if (inTitle) {
@@ -492,6 +519,15 @@
     }
     else if (inDesc){
       currentBookmark->comment = content;
+    }
+    else if (inAdded) {
+      currentBookmark->creationTime = atoi(content.c_str());
+    }
+    else if (inVisited) {
+      currentBookmark->visitTime = atoi(content.c_str());
+    }
+    else if (inModified) {
+      currentBookmark->modifiedTime = atoi(content.c_str());
     }
   }
 }
