diff -ruN bibletime/printing/cprintdialogpages.cpp bibletime/printing/cprintdialogpages.cpp
--- bibletime/printing/cprintdialogpages.cpp	Fri Apr 12 13:41:32 2002
+++ bibletime/printing/cprintdialogpages.cpp	Thu Jun 20 00:24:38 2002
@@ -54,14 +54,14 @@
   QGridLayout *gbox = new QGridLayout( group, 4, 2, 5, 5 );
   gbox->addRowSpacing( 0, group->fontMetrics().height()-5 );
 
-  const QString name[4] = {i18n("&Top"),i18n("&Bottom"),i18n("&Left"), i18n("&Right") };
+  const QString nname[4] = {i18n("&Top"),i18n("&Bottom"),i18n("&Left"), i18n("&Right") };
   for( int i=0; i<4; i++ ) {
     m_marginSpin[i] = new QSpinBox( group );
     m_marginSpin[i]->setFixedHeight( m_marginSpin[i]->sizeHint().height() );
     m_marginSpin[i]->setMinimumWidth( m_marginSpin[i]->fontMetrics().width("M")*10 );
     m_marginSpin[i]->setSuffix(" mm");
 
-    QLabel *label = new QLabel( m_marginSpin[i], name[i], group );
+    QLabel *label = new QLabel( m_marginSpin[i], nname[i], group );
     label->setFixedHeight( m_marginSpin[i]->sizeHint().height() );
     label->setFixedWidth( label->sizeHint().width() );
 
