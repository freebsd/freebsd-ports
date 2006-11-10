--- src/context/DynamicContextImpl.cpp.orig	Mon Aug  9 20:19:54 2004
+++ src/context/DynamicContextImpl.cpp	Fri Nov  3 11:52:11 2006
@@ -39,6 +39,13 @@
 
 static CodepointCollation g_codepointCollation;
 
+inline int gettimezone()
+{ 
+    time_t tt; 
+    time(&tt);
+    struct tm *tm_p = gmtime(&tt);
+    return (int)mktime(tm_p) - (int)tt;
+}
 DynamicContextImpl::DynamicContextImpl(const StaticContext *staticContext, XPath2MemoryManager* memMgr)
   : _staticContext(staticContext),
     _nsResolver(staticContext->getNSResolver()),
@@ -148,7 +155,7 @@
     tz = _timezone;
   #else /*WIN32*/
     tzset ();
-    tz = timezone;
+    tz = gettimezone();
   #endif
     // validate tzone
     Timezone tzone(tz);
