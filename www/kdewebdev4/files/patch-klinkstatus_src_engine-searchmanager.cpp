--- klinkstatus/src/engine/searchmanager.cpp.orig	Mon Mar 27 18:23:49 2006
+++ klinkstatus/src/engine/searchmanager.cpp	Mon Mar 27 18:24:22 2006
@@ -840,7 +840,7 @@
     // <depth>
     child_element = element.ownerDocument().createElement("depth");
     child_element.appendChild(element.ownerDocument().
-            createTextNode(searchMode() == domain ? "Unlimited" : QString::number(depth_)));
+            createTextNode(searchMode() == domain ? QString("Unlimited") : QString::number(depth_)));
     element.appendChild(child_element);
 
     // <check_parent_folders>
