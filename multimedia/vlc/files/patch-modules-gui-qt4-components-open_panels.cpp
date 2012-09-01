--- modules/gui/qt4/components/open_panels.cpp.orig
+++ modules/gui/qt4/components/open_panels.cpp
@@ -925,7 +925,7 @@ void CaptureOpenPanel::initialize()
 
     dvbCard = new QSpinBox;
     dvbCard->setAlignment( Qt::AlignRight );
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     dvbCard->setPrefix( "/dev/dvb/adapter" );
 #endif
     dvbDevLayout->addWidget( dvbDeviceLabel, 0, 0 );
