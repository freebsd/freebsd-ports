--- src/dvbcut.cpp~	Fri Dec 16 20:14:04 2005
+++ src/dvbcut.cpp	Mon Apr  9 16:55:43 2007
@@ -43,6 +43,7 @@
 #include <qmenubar.h>
 #include <qsettings.h>
 
+#include "port.h"
 #include "dvbcut.h"
 #include "mpgfile.h"
 #include "avframe.h"
@@ -56,6 +57,7 @@
 #include "busyindicator.h"
 #include "progressstatusbar.h"
 #include "exportdialog.h"
+#include "settings.h"
 
 // **************************************************************************
 // ***  busy cursor helpers
@@ -92,12 +94,12 @@
   {
   if (b) {
     if (busy==0)
-      setCursor(QCursor(Qt::WaitCursor));
+     QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
     ++busy;
     } else if (busy>0) {
     --busy;
     if (busy==0)
-      unsetCursor();
+      QApplication::restoreOverrideCursor();
     }
   }
 
@@ -118,8 +120,8 @@
   playAudio2Action->setEnabled(false);
   playAudio1Action->removeFrom(playToolbar);
   playAudio2Action->removeFrom(playToolbar);
-  playAudio1Action->removeFrom(Play);
-  playAudio2Action->removeFrom(Play);
+  playAudio1Action->removeFrom(playMenu);
+  playAudio2Action->removeFrom(playMenu);
 #endif // ! HAVE_LIB_AO
 
   audiotrackpopup=new QPopupMenu(this);
@@ -132,11 +134,10 @@
   connect( recentfilespopup, SIGNAL( activated(int) ), this, SLOT( loadrecentfile(int) ) );
   connect( recentfilespopup, SIGNAL( aboutToShow() ), this, SLOT( abouttoshowrecentfiles() ) );
 
-    {
-    QSettings settings;
-    settings.setPath(DVBCUT_QSETTINGS_DOMAIN,DVBCUT_QSETTINGS_PRODUCT);
-    setviewscalefactor(settings.readNumEntry(DVBCUT_QSETTINGS_PATH "viewscalefactor",1));
-    }
+  setviewscalefactor(settings.viewscalefactor);
+
+  // install event handler
+  linslider->installEventFilter(this);
 
   show();
   }
@@ -177,13 +178,9 @@
 
 void dvbcut::fileSaveAs()
   {
-  QSettings settings;
-  settings.setPath(DVBCUT_QSETTINGS_DOMAIN,DVBCUT_QSETTINGS_PRODUCT);
-  settings.beginGroup(DVBCUT_QSETTINGS_PATH);
-
   QString s=QFileDialog::getSaveFileName(
               prjfilen,
-              settings.readEntry("prjfilter",DVBCUT_DEFAULT_PRJFILTER),
+              settings.prjfilter,
               this,
               "Save project as...",
               "Choose the name of the project file" );
@@ -410,26 +407,56 @@
 
   mux.reset();
 
-  prgwin.printheading("Saved %d pictures (%02d:%02d:%02d.%03d)\n",savedpic,
+  prgwin.printheading("Saved %d pictures (%02d:%02d:%02d.%03d)",savedpic,
                       int(savedtime/(3600*90000)),
                       int(savedtime/(60*90000))%60,
                       int(savedtime/90000)%60,
                       int(savedtime/90)%1000	);
 
+  std::string chapterstring;
   if (!chapterlist.empty()) {
-    prgwin.printheading("Chapterlist:");
+    int nchar=0;
+    char chapter[16];
+    prgwin.printheading("\nChapterlist:");
     pts_t lastch=-1;
     for(std::list<pts_t>::const_iterator it=chapterlist.begin();
         it!=chapterlist.end();++it)
       if (*it != lastch) {
         lastch=*it;
-        prgwin.print("%02d:%02d:%02d.%03d",
+        // formatting the chapter string
+        if(nchar>0) {
+          nchar++; 
+	  chapterstring+=",";
+	}  
+        nchar+=sprintf(chapter,"%02d:%02d:%02d.%03d",
                      int(lastch/(3600*90000)),
                      int(lastch/(60*90000))%60,
                      int(lastch/90000)%60,
                      int(lastch/90)%1000	);
+        // normal output as before
+        prgwin.print(chapter);
+        // append chapter marks to a comma separated list for dvdauthor xml-file         
+        chapterstring+=chapter;
         }
     }
+  // simple dvdauthor xml file with chapter marks
+  std::string filename,destname;
+  if(expfilen.rfind("/")<expfilen.length()) 
+    filename=expfilen.substr(expfilen.rfind("/")+1);
+  else 
+    filename=expfilen;
+  destname=filename.substr(0,filename.rfind("."));
+  prgwin.printheading("\nSimple XML-file for dvdauthor with chapter marks:");
+  prgwin.print("<dvdauthor dest=\"%s\">",destname.c_str());
+  prgwin.print("  <vmgm />");
+  prgwin.print("  <titleset>");
+  prgwin.print("    <titles>");
+  prgwin.print("      <pgc>");
+  prgwin.print("        <vob file=\"%s\" chapters=\"%s\" />",filename.c_str(),chapterstring.c_str());
+  prgwin.print("      </pgc>");
+  prgwin.print("    </titles>");
+  prgwin.print("  </titleset>");
+  prgwin.print("</dvdauthor>");
 
   prgwin.finish();
   }
@@ -589,17 +616,21 @@
 
   fine=true;
   linslider->setValue(mpg->lastiframe(curpic));
-  off_t offset=(*mpg)[curpic].getpos().packetposition();
+  dvbcut_off_t offset=(*mpg)[curpic].getpos().packetposition();
   mplayer_curpts=(*mpg)[curpic].getpts();
 
   mplayer_process=new QProcess(QString("mplayer"));
   mplayer_process->addArgument("-noconsolecontrols");
+#ifdef __WIN32__
+  mplayer_process->addArgument("-vo");
+  mplayer_process->addArgument("directx:noaccel");
+#endif
   mplayer_process->addArgument("-wid");
   mplayer_process->addArgument(QString().sprintf("0x%x",int(imagedisplay->winId())));
-  mplayer_process->addArgument("-geometry");
-  mplayer_process->addArgument(QString().sprintf("%dx%d",int(imagedisplay->width()),int(imagedisplay->height())));
   mplayer_process->addArgument("-sb");
   mplayer_process->addArgument(QString::number(offset));
+  mplayer_process->addArgument("-geometry");
+  mplayer_process->addArgument(QString().sprintf("%dx%d+0+0",int(imagedisplay->width()),int(imagedisplay->height())));
 
   if (currentaudiotrack>=0 && currentaudiotrack<mpg->getaudiostreams()) {
     mplayer_process->addArgument("-aid");
@@ -695,10 +726,26 @@
 
   int relpic=0;
 
-  if (v>=4000)
-    relpic=int(exp(alpha*(v-4000))+.5);
-  else if (v<=-4000)
-    relpic=-int(exp(alpha*(-v-4000))+.5);
+  /*
+  if (v>jog_offset)
+    relpic=int(exp(alpha*(v-jog_offset))+.5);
+  else if (v<-jog_offset)
+    relpic=-int(exp(alpha*(-v-jog_offset))+.5);
+  */
+  /*
+  alternative function 
+  (fits better to external tick interval setting, because jog_offset 
+   only affects scale at small numbers AND range of 1 frame is NOT smaller 
+   than range of 0 and 2 frames as in old function!)
+  */ 
+  if (v>0) {
+    relpic=int(exp(alpha*v)-settings.jog_offset);
+    if(relpic<0) relpic=0;
+  }  
+  else if (v<0) {
+    relpic=-int(exp(-alpha*v)-settings.jog_offset);
+    if(relpic>0) relpic=0;
+  }  
 
   int newpic=jogmiddlepic+relpic;
   if (newpic<0)
@@ -706,10 +753,10 @@
   else if (newpic>=pictures)
     newpic=pictures-1;
 
-  if (relpic>50) {
+  if (relpic>=settings.jog_threshold) {
     newpic=mpg->nextiframe(newpic);
     fine=false;
-    } else if (relpic<-50) {
+    } else if (relpic<=-settings.jog_threshold) {
     fine=false;
     } else
     fine=true;
@@ -906,19 +953,18 @@
 
 void dvbcut::abouttoshowrecentfiles()
   {
-  loadrecentfilesfromsettings();
   recentfilespopup->clear();
   int id=0;
-  for(std::vector<std::pair<std::string,std::string> >::iterator it=recentfiles.begin();
-      it!=recentfiles.end();++it)
+  for(std::vector<std::pair<std::string,std::string> >::iterator it=settings.recentfiles.begin();
+      it!=settings.recentfiles.end();++it)
     recentfilespopup->insertItem(it->first,id++);
   }
 
 void dvbcut::loadrecentfile(int id)
   {
-  if (id<0 || id>=(signed)recentfiles.size())
+  if (id<0 || id>=(signed)settings.recentfiles.size())
     return;
-  open(recentfiles[id].first, recentfiles[id].second);
+  open(settings.recentfiles[id].first, settings.recentfiles[id].second);
   }
 
 // **************************************************************************
@@ -926,14 +972,10 @@
 
 void dvbcut::open(std::string filename, std::string idxfilename)
   {
-  QSettings settings;
-  settings.setPath(DVBCUT_QSETTINGS_DOMAIN,DVBCUT_QSETTINGS_PRODUCT);
-  settings.beginGroup(DVBCUT_QSETTINGS_PATH);
-
   if (filename.empty()) {
     QString fn=QFileDialog::getOpenFileName(
                  QString::null,
-                 settings.readEntry("loadfilter",DVBCUT_DEFAULT_LOADFILTER),
+                 settings.loadfilter,
                  this,
                  "Open file...",
                  "Choose an MPEG file to open" );
@@ -981,7 +1023,8 @@
   fileOpenAction->setEnabled(false);
   fileSaveAction->setEnabled(false);
   fileSaveAsAction->setEnabled(false);
-  fileCloseAction->setEnabled(false);
+  // enable closing even if no file was loaded (mr)
+  //fileCloseAction->setEnabled(false);
   fileExportAction->setEnabled(false);
   playPlayAction->setEnabled(false);
   playStopAction->setEnabled(false);
@@ -1081,7 +1124,7 @@
   if (idxfilename.empty()) {
     QString s=QFileDialog::getSaveFileName(
                 filename+".idx",
-                settings.readEntry("idxfilter",DVBCUT_DEFAULT_IDXFILTER),
+                settings.idxfilter,
                 this,
                 "Choose index file...",
                 "Choose the name of the index file" );
@@ -1193,9 +1236,14 @@
   linslider->setMaxValue(pictures-1);
   linslider->setLineStep(int(300*fps));
   linslider->setPageStep(int(900*fps));
-  linslider->setTickInterval(int(3600*fps));
+  if (settings.lin_interval > 0)
+    linslider->setTickInterval(int(settings.lin_interval*fps));
 
-  alpha=log(180000)/96000.;
+  //alpha=log(jog_maximum)/double(100000-jog_offset);
+  // with alternative function
+  alpha=log(settings.jog_maximum)/100000.;
+  if (settings.jog_interval > 0 && settings.jog_interval <= 100000) 
+    jogslider->setTickInterval(int(100000/settings.jog_interval));
 
   imagedisplay->setBackgroundMode(Qt::NoBackground);
   curpic=~0;
@@ -1287,54 +1335,20 @@
 // **************************************************************************
 // ***  protected functions
 
-void dvbcut::loadrecentfilesfromsettings()
-  {
-  QSettings settings;
-  settings.setPath(DVBCUT_QSETTINGS_DOMAIN,DVBCUT_QSETTINGS_PRODUCT);
-  settings.beginGroup(DVBCUT_QSETTINGS_PATH "recentfiles");
-
-  recentfiles.clear();
-
-  for(int i=0;i<5;++i) {
-    QString filename(settings.readEntry(QString::number(i)));
-    if (filename.isEmpty())
-      continue;
-    QString idxfilename(settings.readEntry(QString::number(i)+"-idx"));
-    recentfiles.push_back(std::pair<std::string,std::string>(filename,
-                          idxfilename.isEmpty()?std::string():std::string((const char *)idxfilename)));
-
-    }
-
-  }
-
 void dvbcut::addtorecentfiles(const std::string &filename, const std::string &idxfilename)
   {
-  loadrecentfilesfromsettings();
 
-  for(std::vector<std::pair<std::string,std::string> >::iterator it=recentfiles.begin();
-      it!=recentfiles.end();)
+  for(std::vector<std::pair<std::string,std::string> >::iterator it=settings.recentfiles.begin();
+      it!=settings.recentfiles.end();)
     if (it->first==filename)
-      it=recentfiles.erase(it);
+      it=settings.recentfiles.erase(it);
     else
       ++it;
 
-  recentfiles.insert(recentfiles.begin(),std::pair<std::string,std::string>(filename,idxfilename));
-
-  while (recentfiles.size()>5)
-    recentfiles.pop_back();
+  settings.recentfiles.insert(settings.recentfiles.begin(),std::pair<std::string,std::string>(filename,idxfilename));
 
-  QSettings settings;
-  settings.setPath(DVBCUT_QSETTINGS_DOMAIN,DVBCUT_QSETTINGS_PRODUCT);
-  settings.beginGroup(DVBCUT_QSETTINGS_PATH "recentfiles");
-
-  for(unsigned int i=0;i<recentfiles.size();++i) {
-    settings.writeEntry(QString::number(i),recentfiles[i].first);
-    settings.writeEntry(QString::number(i)+"-idx",recentfiles[i].second);
-    }
-  for(unsigned int i=recentfiles.size();i<5;++i) {
-    settings.removeEntry(QString::number(i));
-    settings.removeEntry(QString::number(i)+"-idx");
-    }
+  while (settings.recentfiles.size()>settings.recentfiles_max)
+    settings.recentfiles.pop_back();
   }
 
 void dvbcut::setviewscalefactor(int factor)
@@ -1345,11 +1359,7 @@
   viewHalfSizeAction->setOn(factor==2);
   viewQuarterSizeAction->setOn(factor==4);
 
-    {
-    QSettings settings;
-    settings.setPath(DVBCUT_QSETTINGS_DOMAIN,DVBCUT_QSETTINGS_PRODUCT);
-    settings.writeEntry(DVBCUT_QSETTINGS_PATH "viewscalefactor",factor);
-    }
+  settings.viewscalefactor = factor;
 
   if (factor!=viewscalefactor) {
     viewscalefactor=factor;
@@ -1360,3 +1370,32 @@
     }
   }
 
+bool dvbcut::eventFilter(QObject *watched, QEvent *e) {
+  if (e->type() == QEvent::Wheel) {
+    QWheelEvent *we = (QWheelEvent*)e;
+    if (watched == linslider) {
+      // process event myself
+      int delta = we->delta();
+      int incr = 0;
+      if (we->state() & AltButton)
+	incr = settings.wheel_increments[WHEEL_INCR_ALT];
+      else if (we->state() & ControlButton)
+	incr = settings.wheel_increments[WHEEL_INCR_CTRL];
+      else if (we->state() & ShiftButton)
+	incr = settings.wheel_increments[WHEEL_INCR_SHIFT];
+      else
+	incr = settings.wheel_increments[WHEEL_INCR_NORMAL];
+      if (incr != 0) {
+	bool save = fine;
+	// use fine positioning if incr is small
+	fine = (incr < 0 ? -incr : incr) < settings.wheel_threshold;
+	// Note: delta is a multiple of 120 (see Qt documentation)
+	linslider->setValue(curpic - (delta * incr) / settings.wheel_delta);
+	fine = save;
+	}
+      return true;
+      }
+    }
+  // propagate to base class
+  return dvbcutbase::eventFilter(watched, e);
+  }
