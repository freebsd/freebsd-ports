--- src/fetch/z3950connection.cpp.orig	Thu Jan 11 18:50:07 2007
+++ src/fetch/z3950connection.cpp	Fri Jan 12 11:13:31 2007
@@ -340,16 +340,16 @@
 
 inline
 QCString Z3950Connection::toCString(const QString& text_) {
-  return iconv(text_.utf8(), QString::fromLatin1("utf-8"), m_sourceCharSet);
+  return iConv(text_.utf8(), QString::fromLatin1("utf-8"), m_sourceCharSet);
 }
 
 inline
 QString Z3950Connection::toString(const QCString& text_) {
-  return QString::fromUtf8(iconv(text_, m_sourceCharSet, QString::fromLatin1("utf-8")));
+  return QString::fromUtf8(iConv(text_, m_sourceCharSet, QString::fromLatin1("utf-8")));
 }
 
 // static
-QCString Z3950Connection::iconv(const QCString& text_, const QString& fromCharSet_, const QString& toCharSet_) {
+QCString Z3950Connection::iConv(const QCString& text_, const QString& fromCharSet_, const QString& toCharSet_) {
 #if HAVE_YAZ
   if(text_.isEmpty()) {
     return text_;
@@ -365,9 +365,9 @@
     QString charSetLower = fromCharSet_.lower();
     charSetLower.remove('-').remove(' ');
     if(charSetLower == Latin1Literal("iso5426")) {
-      return iconv(Iso5426Converter::toUtf8(text_).utf8(), QString::fromLatin1("utf-8"), toCharSet_);
+      return iConv(Iso5426Converter::toUtf8(text_).utf8(), QString::fromLatin1("utf-8"), toCharSet_);
     } else if(charSetLower == Latin1Literal("iso6937")) {
-      return iconv(Iso6937Converter::toUtf8(text_).utf8(), QString::fromLatin1("utf-8"), toCharSet_);
+      return iConv(Iso6937Converter::toUtf8(text_).utf8(), QString::fromLatin1("utf-8"), toCharSet_);
     }
     kdWarning() << "Z3950Fetcher::iconv() - conversion from " << fromCharSet_
                 << " to " << toCharSet_ << " is unsupported" << endl;
