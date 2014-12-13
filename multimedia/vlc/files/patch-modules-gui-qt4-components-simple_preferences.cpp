--- modules/gui/qt4/components/simple_preferences.cpp.orig	2014-12-09 10:47:08.000000000 +0100
+++ modules/gui/qt4/components/simple_preferences.cpp	2014-12-09 10:48:34.000000000 +0100
@@ -419,7 +419,8 @@
             QLineEdit * name ## Device = new QLineEdit; \
             name ## Label->setBuddy( name ## Device ); \
             QPushButton * name ## Browse = new QPushButton( qtr( "Browse..." ) ); \
-            outputAudioLayout->addWidget( name ## Device, outputAudioLayout->rowCount() - 1, 0, 1, -1, Qt::AlignLeft );
+            outputAudioLayout->addWidget( name ## Device, outputAudioLayout->rowCount() - 1, 0, 1, -1, Qt::AlignLeft ); \
+            outputAudioLayout->addWidget( name ## Browse, outputAudioLayout->rowCount() - 1, 1, 1, -1, Qt::AlignLeft );
 
             /* Build if necessary */
             QGridLayout * outputAudioLayout = qobject_cast<QGridLayout *>(ui.outputAudioBox->layout());
