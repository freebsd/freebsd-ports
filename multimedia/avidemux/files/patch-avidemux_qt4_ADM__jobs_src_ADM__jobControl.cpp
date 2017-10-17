--- avidemux/qt4/ADM_jobs/src/ADM_jobControl.cpp.orig	2016-01-29 08:47:25 UTC
+++ avidemux/qt4/ADM_jobs/src/ADM_jobControl.cpp
@@ -112,7 +112,7 @@ void jobWindow::refreshList(void)
         QTableWidgetItem *endItem=fromText (end,i);
         QTableWidgetItem *durItem=fromText (dur,i);
 
-#define MX(x,y) case ADM_JOB_##x:  status->setIcon(QIcon(":/jobs/"y));break;
+#define MX(x,y) case ADM_JOB_##x:  status->setIcon(QIcon(":/jobs/" y));break;
         switch(listOfJob[i].status)
         {
             MX(KO,"gtk-no.png");
