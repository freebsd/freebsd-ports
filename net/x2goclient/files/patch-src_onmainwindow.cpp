--- src/onmainwindow.cpp.orig	2021-08-11 18:57:54 UTC
+++ src/onmainwindow.cpp
@@ -1372,7 +1372,7 @@ void ONMainWindow::closeClient()
 
         st.setting()->setValue ( "mainwindow/size",
                                  QVariant ( size() ) );
-        st.setting()->setValue ( "mainwindow/pos",QVariant ( pos() ) );
+        st.setting()->setValue ( "mainwindow/pos",QVariant ( mapToGlobal(QPoint(0,0) ) ));
         st.setting()->setValue ( "mainwindow/maximized",
                                  QVariant ( isMaximized() ) );
         st.setting()->sync();
