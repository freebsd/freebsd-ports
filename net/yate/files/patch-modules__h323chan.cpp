--- ./modules/h323chan.cpp.orig	2011-03-31 14:30:48.000000000 +0400
+++ ./modules/h323chan.cpp	2011-04-13 15:25:28.000000000 +0400
@@ -646,7 +646,7 @@
 static void ListRegisteredCaps(int level)
 {
     PFactory<H323Capability>::KeyList_T list = PFactory<H323Capability>::GetKeyList();
-#if (OPENH323_NUMVERSION >= 12000)
+#if (OPENH323_NUMVERSION >= 11900)
     for (PFactory<H323Capability>::KeyList_T::const_iterator find = list.begin(); find != list.end(); ++find)
       Debug(level,"Registed capability: '%s'",find->c_str());
 #else
