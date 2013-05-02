--- ./lib/adium-theme-view.cpp.orig	2013-04-16 19:00:42.000000000 +0200
+++ ./lib/adium-theme-view.cpp	2013-05-02 01:58:37.569417377 +0200
@@ -165,7 +165,8 @@
     QString footerHtml = replaceHeaderKeywords(m_chatStyle->getFooterHtml(), chatInfo);
     QString extraStyleHtml = m_chatStyle->messageViewVersion() < 3 ? QLatin1String("")
                                                                    : QLatin1String("@import url( \"main.css\" );");
-    m_lastContent = AdiumThemeContentInfo();
+    AdiumThemeContentInfo message;
+    m_lastContent = message;
 
     if (templateHtml.isEmpty()) {
         // if templateHtml is empty, we failed to load the fallback template file
@@ -427,7 +428,8 @@
         message.appendMessageClass(QLatin1String("consecutive"));
     }
 
-    m_lastContent = AdiumThemeContentInfo(statusMessage.type());
+    AdiumThemeContentInfo message2(statusMessage.type());
+    m_lastContent = message2;
 
     switch (message.type()) {
     case AdiumThemeMessageInfo::Status:
