--- src/fetch/z3950connection.h.orig	Fri Jan 12 11:14:04 2007
+++ src/fetch/z3950connection.h	Fri Jan 12 11:14:17 2007
@@ -85,7 +85,7 @@
   void abort() { m_aborted = true; }
 
 private:
-  static QCString iconv(const QCString& text, const QString& fromCharSet, const QString& toCharSet);
+  static QCString iConv(const QCString& text, const QString& fromCharSet, const QString& toCharSet);
   static QString toXML(const QCString& marc, const QString& fromCharSet);
 
   bool makeConnection();
