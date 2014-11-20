commit 641aa7c75631084260ae89aecbdb625e918c6689
Author: Albert Astals Cid <aacid@kde.org>
Date:   Thu Nov 13 15:06:01 2014 +0100

    Sanitize html
    
    As discussed by the security team

--- src/webpage.cpp
+++ src/webpage.cpp
@@ -226,23 +226,26 @@ QString WebPage::errorPage(int code, const QString& text, const KUrl& reqUrl) co
     doc += QL1S( "<h3>" );
     doc += i18n( "Details of the Request:" );
     doc += QL1S( "</h3><ul><li>" );
-    doc += i18n( "URL: %1", reqUrl.url() );
+    // escape URL twice: once for i18n, and once for HTML.
+    doc += i18n( "URL: %1", Qt::escape( Qt::escape( reqUrl.prettyUrl() ) ) );
     doc += QL1S( "</li><li>" );
 
     const QString protocol (reqUrl.protocol());
     if ( !protocol.isNull() ) {
-        doc += i18n( "Protocol: %1", protocol );
+        // escape protocol twice: once for i18n, and once for HTML.
+        doc += i18n( "Protocol: %1", Qt::escape( Qt::escape( protocol ) ) );
         doc += QL1S( "</li><li>" );
     }
 
     doc += i18n( "Date and Time: %1",
                  KGlobal::locale()->formatDateTime(QDateTime::currentDateTime(), KLocale::LongDate) );
     doc += QL1S( "</li><li>" );
-    doc += i18n( "Additional Information: %1" ,  text );
+    // escape text twice: once for i18n, and once for HTML.
+    doc += i18n( "Additional Information: %1", Qt::escape( Qt::escape( text ) ) );
     doc += QL1S( "</li></ul><h3>" );
     doc += i18n( "Description:" );
     doc += QL1S( "</h3><p>" );
-    doc += description;
+    doc += Qt::escape( description );
     doc += QL1S( "</p>" );
 
     if ( causes.count() ) {
