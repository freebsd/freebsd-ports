--- src/translators/alexandriaexporter.cpp.orig	Sat Oct 16 00:18:34 2004
+++ src/translators/alexandriaexporter.cpp	Sat Oct 16 00:19:10 2004
@@ -111,7 +111,7 @@
                   entry_->field(QString::fromLatin1("publisher"));
   pub.replace('"', QString::fromLatin1("\\\""));
   // publisher uses n/a when empty
-  ts << "publisher: \"" << (pub.isEmpty() ? "n/a" : pub) << "\"\n";
+  ts << "publisher: \"" << (pub.isEmpty() ? QString::fromLatin1("n/a") : pub) << "\"\n";
   QString rating = entry_->field(QString::fromLatin1("rating"));
   for(uint pos = 0; pos < rating.length(); ++pos) {
     if(rating[pos].isDigit()) {
