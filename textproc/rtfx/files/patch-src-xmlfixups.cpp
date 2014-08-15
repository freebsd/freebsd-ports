--- src/xmlfixups.cpp~
+++ src/xmlfixups.cpp
@@ -453,7 +453,7 @@ void XmlFixups::runPassTwo(const DOM::Do
 
         // Mark each node as we've seen it so we don't 
         // do a given element twice
-        if((int)el.getUserData() == PASS_TWO)
+        if((intptr_t)el.getUserData() == (intptr_t)PASS_TWO)
             continue;
 
         el.setUserData((void*)PASS_TWO);
