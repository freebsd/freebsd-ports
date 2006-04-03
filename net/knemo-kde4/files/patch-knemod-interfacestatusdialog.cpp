--- src/knemod/interfacestatusdialog.cpp.orig	Sat Apr  1 21:44:22 2006
+++ src/knemod/interfacestatusdialog.cpp	Sun Apr  2 21:34:55 2006
@@ -24,6 +24,7 @@
 #include <qtabwidget.h>
 
 #include <kdebug.h>
+#include <kcombobox.h>
 #include <kconfig.h>
 #include <klocale.h>
 #include <kglobal.h>
@@ -92,6 +93,10 @@
     mTimer = new QTimer();
     connect( mTimer, SIGNAL( timeout() ), this, SLOT( updateDialog() ) );
     mTimer->start( 1000 );
+
+#ifdef Q_OS_FREEBSD    
+    connect( comboBoxIP, SIGNAL( activated(int) ), this, SLOT( updateDialog() ) );
+#endif
 }
 
 InterfaceStatusDialog::~InterfaceStatusDialog()
@@ -201,12 +206,28 @@
     if ( data.available )
     {
         // ip tab
+#ifdef Q_OS_FREEBSD
+        if ( data.addrData.count() != comboBoxIP->count() )
+            comboBoxIP->clear();
+          
+        QDictIterator<AddrData> it( data.addrData );
+        for( ; it.current(); ++it )
+            if (!comboBoxIP->contains(it.currentKey()))
+                comboBoxIP->insertItem( it.currentKey() );
+            
+        textLabelSubnet->setText(data.addrData[ comboBoxIP->currentText() ]->subnetMask);
+#else        
         textLabelIP->setText( data.ipAddress );
         textLabelSubnet->setText( data.subnetMask );
+#endif
         if ( mInterface->getType() == Interface::ETHERNET )
         {
             variableLabel1->setText( i18n( "Broadcast Address:" ) );
+#ifdef Q_OS_FREEBSD
+            variableText1->setText( data.addrData[ comboBoxIP->currentText() ]->broadcastAddress);
+#else
             variableText1->setText( data.broadcastAddress );
+#endif
             variableLabel2->setText( i18n( "Default Gateway:" ) );
             variableText2->setText( data.defaultGateway );
             variableLabel3->setText( i18n( "HW-Address:" ) );
