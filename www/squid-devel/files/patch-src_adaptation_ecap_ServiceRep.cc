--- src/adaptation/ecap/ServiceRep.cc.orig	2016-04-20 13:19:59 UTC
+++ src/adaptation/ecap/ServiceRep.cc
@@ -236,7 +236,7 @@ bool Adaptation::Ecap::ServiceRep::probe
 
 bool Adaptation::Ecap::ServiceRep::up() const
 {
-    return theService;
+    return theService != NULL;
 }
 
 bool Adaptation::Ecap::ServiceRep::wantsUrl(const SBuf &urlPath) const
