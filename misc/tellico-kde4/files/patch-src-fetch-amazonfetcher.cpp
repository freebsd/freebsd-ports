--- src/fetch/amazonfetcher.cpp.orig	Sat Oct 16 00:23:06 2004
+++ src/fetch/amazonfetcher.cpp	Sat Oct 16 00:23:48 2004
@@ -428,7 +428,7 @@
 //    emit signalStatus(i18n("<qt>The cover image for <i>%1</i> could not be loaded.</qt>").arg(
 //                            entry->field(QString::fromLatin1("title"))));
     emit signalStatus(i18n("The cover image could not be loaded."));
-  } else if(img.width() > 1 and img.height() > 1) { // amazon serves up 1x1 gifs occasionally
+  } else if(img.width() > 1 && img.height() > 1) { // amazon serves up 1x1 gifs occasionally
     // all relevant collection types have cover fields
     entry->setField(QString::fromLatin1("cover"), img.id());
   }
