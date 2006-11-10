--- src/context/XPath2ContextImpl.cpp.orig	Mon Aug  9 20:19:54 2004
+++ src/context/XPath2ContextImpl.cpp	Fri Nov  3 11:51:57 2006
@@ -8,6 +8,7 @@
 #include <assert.h>
 #include <iostream>
 #include <memory>
+#include <time.h>
 #include <pathan/VariableStore.hpp>
 #include <pathan/simpleVariables/VariableTypeStore.hpp>
 #include <pathan/XPath2NSUtils.hpp>
@@ -41,6 +42,13 @@
 
 static CodepointCollation g_codepointCollation;
 
+inline int gettimezone()
+{ 
+    time_t tt; 
+    time(&tt);
+    struct tm *tm_p = gmtime(&tt);
+    return (int)mktime(tm_p) - (int)tt;
+}
 XPath2ContextImpl::XPath2ContextImpl(XPath2MemoryManager* memMgr,
                                      XERCES_CPP_NAMESPACE_QUALIFIER XMLGrammarPool* xmlgr,
                                      XERCES_CPP_NAMESPACE_QUALIFIER DOMNode* contextNode) :  
@@ -177,7 +185,7 @@
     tz = _timezone;
   #else /*WIN32*/
     tzset ();
-    tz = timezone;
+    tz = gettimezone();
   #endif
     // validate tzone
     Timezone tzone(tz);
