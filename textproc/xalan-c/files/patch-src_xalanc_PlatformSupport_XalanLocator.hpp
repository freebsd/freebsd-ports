--- src/xalanc/PlatformSupport/XalanLocator.hpp.orig	2012-09-27 06:59:33 UTC
+++ src/xalanc/PlatformSupport/XalanLocator.hpp
@@ -91,7 +91,7 @@ public:
             const XalanDOMChar*     theAlternateId = getEmptyPtr())
     {
         return theLocator == 0 ? theAlternateId : (theLocator->getSystemId() ?
-            theLocator->getPublicId() : theAlternateId);
+            theLocator->getSystemId() : theAlternateId);
     }
 
     /**
