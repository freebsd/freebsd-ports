src/core/k9tools.cpp:59:54: error: no viable conversion from 'bool' 
    to 'KStandardDirs::SearchOptions' (aka 'QFlags<KStandardDirs::SearchOption>'
    bool res= KStandardDirs::findExe( _progName,NULL,false) !=NULL ;

--- src/core/k9tools.cpp.orig	2018-01-17 11:30:09 UTC
+++ src/core/k9tools.cpp
@@ -56,7 +56,7 @@ bool k9Tools::checkProgram(QString _progName,bool _msg
     }
     return false;
 #else
-    bool res= KStandardDirs::findExe( _progName,NULL,false) !=NULL ;
+    bool res= KStandardDirs::findExe( _progName,NULL, KStandardDirs::NoSearchOptions) !=NULL ;
     if (_msg && !res)
         k9Dialogs::error(i18n("Error starting program %1").arg(_progName),i18n("Running program"));
     return res;
