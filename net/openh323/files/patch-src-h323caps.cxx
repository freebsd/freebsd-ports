--- src/h323caps.cxx.orig	2006-05-16 07:36:01.000000000 -0400
+++ src/h323caps.cxx	2007-12-31 15:28:02.000000000 -0500
@@ -2076,7 +2076,7 @@
                                             PINDEX simultaneous,
                                             const PString & name)
 {
-  PINDEX reply = descriptorNum == P_MAX_INDEX ? P_MAX_INDEX : simultaneous;
+/*  PINDEX reply = descriptorNum == P_MAX_INDEX ? P_MAX_INDEX : simultaneous;
 
   PStringArray wildcard = name.Tokenise('*', FALSE);
 
@@ -2109,6 +2109,46 @@
   }
 
   return reply;
+*/
+
+
+
+
+  PINDEX reply = descriptorNum == P_MAX_INDEX ? P_MAX_INDEX : simultaneous;
+
+  PStringArray wildcard = name.Tokenise('*', FALSE);
+
+  H323CapabilityFactory::KeyList_T stdCaps = H323CapabilityFactory::GetKeyList();
+
+  for (unsigned session = OpalMediaFormat::FirstSessionID; session <= OpalMediaFormat::LastSessionID; session++) {
+    for (H323CapabilityFactory::KeyList_T::const_iterator r = stdCaps.begin(); r != stdCaps.end(); ++r) {
+      PString capName(*r);
+      if (MatchWildcard(capName, wildcard) && (FindCapability(capName) == NULL)) {
+        OpalMediaFormat mediaFormat(capName);
+        if (!mediaFormat.IsValid() && (capName.Right(4) == "{sw}") && capName.GetLength() > 4)
+          mediaFormat = OpalMediaFormat(capName.Left(capName.GetLength()-4));
+        if (mediaFormat.IsValid() && mediaFormat.GetDefaultSessionID() == session) {
+          // add the capability
+          H323Capability * capability = H323Capability::Create(capName);
+          PINDEX num = SetCapability(descriptorNum, simultaneous, capability);
+          if (descriptorNum == P_MAX_INDEX) {
+            reply = num;
+            descriptorNum = num;
+            simultaneous = P_MAX_INDEX;
+          }
+          else if (simultaneous == P_MAX_INDEX) {
+            if (reply == P_MAX_INDEX)
+              reply = num;
+            simultaneous = num;
+          }
+        }
+      }
+    }
+    simultaneous = P_MAX_INDEX;
+  }
+
+  return reply;
+
 }
 
 
