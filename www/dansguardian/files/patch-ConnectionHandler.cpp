--- ConnectionHandler.cpp.orig	Tue Mar 26 08:22:34 2002
+++ ConnectionHandler.cpp	Tue Mar 26 08:25:12 2002
@@ -293,7 +293,9 @@
 
                         checkme.checkphrase(docbodyblock, dblen, options);
 
+#ifndef WITHOUT_PICS_FILTER
                         checkme.checkPICS(docbodyblock, dblen, options);
+#endif
                     } catch (exception& e) {}
                     delete[] docbodyblock;
                 }
