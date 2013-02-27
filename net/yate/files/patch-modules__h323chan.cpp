--- ./modules/h323chan.cpp.orig	2012-10-24 15:19:15.000000000 +0400
+++ ./modules/h323chan.cpp	2013-02-14 19:58:02.000000000 +0400
@@ -897,7 +897,7 @@
 static void ListRegisteredCaps(int level)
 {
     PFactory<H323Capability>::KeyList_T list = PFactory<H323Capability>::GetKeyList();
-#if (OPENH323_NUMVERSION >= 12000)
+#if (OPENH323_NUMVERSION >= 11900)
     for (PFactory<H323Capability>::KeyList_T::const_iterator find = list.begin(); find != list.end(); ++find)
       Debug(level,"Registed capability: '%s'",find->c_str());
 #else
