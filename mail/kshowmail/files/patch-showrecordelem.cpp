--- kshowmail/showrecordelem.cpp.orig	Sun Aug 15 19:13:32 2004
+++ kshowmail/showrecordelem.cpp	Sun Aug 15 19:13:49 2004
@@ -115,7 +115,7 @@
              << i18n("Subject") << " = " << subject() << endl << endl;
     Logger::flush();
   }
-};
+}
 
 
 QString ShowRecordElem::from () const
