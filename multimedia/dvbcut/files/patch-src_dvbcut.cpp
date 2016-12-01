--- src/dvbcut.cpp.orig	2016-11-18 13:31:01 UTC
+++ src/dvbcut.cpp
@@ -580,7 +580,7 @@ void dvbcut::fileExport()
     }
   }
 
-  std::unique_ptr<exportdialog> expd(new exportdialog(QString::fromStdString(expfilen),this));
+  std::auto_ptr<exportdialog> expd(new exportdialog(QString::fromStdString(expfilen),this));
   expd->ui->muxercombo->addItem(tr("MPEG program stream/DVD (DVBCUT multiplexer)"));
   expd->ui->muxercombo->addItem(tr("MPEG program stream (DVBCUT multiplexer)"));
   expd->ui->muxercombo->addItem(tr("MPEG program stream/DVD (libavformat)"));
@@ -725,7 +725,7 @@ void dvbcut::fileExport()
 
   //   lavfmuxer mux(fmt,*mpg,outfilename);
 
-  std::unique_ptr<muxer> mux;
+  std::auto_ptr<muxer> mux;
   uint32_t audiostreammask(0);
 
   for(int a=0;a<mpg->getaudiostreams();++a)
@@ -737,17 +737,17 @@ void dvbcut::fileExport()
 
   switch(expfmt) {
     case 1:
-      mux = std::unique_ptr<muxer>(new mpegmuxer(audiostreammask,*mpg,out_file.c_str(),false,0));
+      mux = std::auto_ptr<muxer>(new mpegmuxer(audiostreammask,*mpg,out_file.c_str(),false,0));
       break;
     case 2:
-      mux = std::unique_ptr<muxer>(new lavfmuxer("dvd",audiostreammask,*mpg,out_file.c_str()));
+      mux = std::auto_ptr<muxer>(new lavfmuxer("dvd",audiostreammask,*mpg,out_file.c_str()));
       break;
     case 3:
-      mux = std::unique_ptr<muxer>(new lavfmuxer("mpegts",audiostreammask,*mpg,out_file.c_str()));
+      mux = std::auto_ptr<muxer>(new lavfmuxer("mpegts",audiostreammask,*mpg,out_file.c_str()));
       break;
     case 0:
     default:
-      mux = std::unique_ptr<muxer>(new mpegmuxer(audiostreammask,*mpg,out_file.c_str()));
+      mux = std::auto_ptr<muxer>(new mpegmuxer(audiostreammask,*mpg,out_file.c_str()));
       break;
   }
 
