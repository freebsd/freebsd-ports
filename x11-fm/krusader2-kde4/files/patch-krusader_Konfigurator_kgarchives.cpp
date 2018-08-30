--- krusader/Konfigurator/kgarchives.cpp.orig	2018-08-30 09:48:24 UTC
+++ krusader/Konfigurator/kgarchives.cpp
@@ -163,7 +163,7 @@ void KgArchives::slotAutoConfigure()
 
 void KgArchives::disableNonExistingPackers()
 {
-#define PS(x) lst.contains(x)>0
+#define PS(x) bool(lst.contains(x))
 
     // get list of available packers
     QStringList lst = KRarcHandler::supportedPackers();
