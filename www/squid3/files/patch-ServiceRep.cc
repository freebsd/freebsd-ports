--- src/adaptation/ecap/ServiceRep.cc.orig	2018-09-24 18:34:06 UTC
+++ src/adaptation/ecap/ServiceRep.cc
@@ -234,7 +234,7 @@ bool Adaptation::Ecap::ServiceRep::probe
 
 bool Adaptation::Ecap::ServiceRep::up() const
 {
-    return theService;
+    return bool(theService);
 }
 
 bool Adaptation::Ecap::ServiceRep::wantsUrl(const String &urlPath) const
