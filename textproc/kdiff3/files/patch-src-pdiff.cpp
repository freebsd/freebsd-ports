--- src/pdiff.cpp.orig	Sat May 29 22:22:15 2004
+++ src/pdiff.cpp	Mon May 31 10:59:57 2004
@@ -462,12 +462,12 @@
       // 2. If the files don't have the same name then show all names
       if ( caption.isEmpty() && (!f1.isEmpty() || !f2.isEmpty() || !f3.isEmpty()) )
       {
-         caption = ( f1.isEmpty()? "" : ".../"+f1 );
-         caption += QString(caption.isEmpty() || f2.isEmpty() ? "" : " <-> ") + ( f2.isEmpty()? "" : ".../"+f2 );
-         caption += QString(caption.isEmpty() || f3.isEmpty() ? "" : " <-> ") + ( f3.isEmpty()? "" : ".../"+f3 ) ;
+         caption = ( f1.isEmpty()? QString("") : ".../"+f1 );
+         caption += QString(caption.isEmpty() || f2.isEmpty() ? "" : " <-> ") + ( f2.isEmpty()? QString("") : ".../"+f2 );
+         caption += QString(caption.isEmpty() || f3.isEmpty() ? "" : " <-> ") + ( f3.isEmpty()? QString("") : ".../"+f3 ) ;
       }      
       
-      m_pKDiff3Shell->setCaption( caption.isEmpty() ? "KDiff3" : caption+" - KDiff3");
+      m_pKDiff3Shell->setCaption( caption.isEmpty() ? QString("KDiff3") : caption+" - KDiff3");
    }
    
    
