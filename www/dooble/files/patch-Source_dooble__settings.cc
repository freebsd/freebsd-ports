--- Source/dooble_settings.cc.orig	2026-08-21 03:55:17 UTC
+++ Source/dooble_settings.cc
@@ -2862,34 +2862,6 @@ void dooble_settings::show_qtwebengine_dictionaries_wa
 
   auto const bytes(qEnvironmentVariable("QTWEBENGINE_DICTIONARIES_PATH"));
 
-  if(bytes.trimmed().isEmpty())
-    {
-      auto const directory
-	(QDir::currentPath() + QDir::separator() + "qtwebengine_dictionaries");
-
-      m_ui.qtwebengine_dictionaries_warning_label->setText
-	(tr("<b>Warning!</b> "
-	    "The directory qtwebengine_dictionaries cannot be accessed. "
-	    "Dooble searched %1. Please read %2, line %3.").
-	 arg(directory).arg(__FILE__).arg(__LINE__));
-
-      if(!QFileInfo(directory).isReadable())
-	{
-	  m_ui.qtwebengine_dictionaries_warning_label->setVisible(true);
-	  return;
-	}
-    }
-  else if(!QFileInfo(bytes).isReadable())
-    {
-      m_ui.qtwebengine_dictionaries_warning_label->setText
-	(tr("<b>Warning!</b> "
-	    "The directory qtwebengine_dictionaries cannot be accessed. "
-	    "Dooble searched %1. Please read %2, line %3.").
-	 arg(bytes.constData()).arg(__FILE__).arg(__LINE__));
-      m_ui.qtwebengine_dictionaries_warning_label->setVisible(true);
-      return;
-    }
-
   for(int i = 0; i < m_ui.dictionaries->count(); i++)
     {
       auto item = m_ui.dictionaries->item(i);
