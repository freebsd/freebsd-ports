--- knemod/interfacestatusdialog.cpp.orig	Sat Jan 22 00:11:02 2005
+++ knemod/interfacestatusdialog.cpp	Sat Jan 22 00:15:24 2005
@@ -24,6 +24,7 @@
 #include <qtabwidget.h>
 
 #include <kdebug.h>
+#include <kcombobox.h>
 #include <kconfig.h>
 #include <klocale.h>
 #include <kglobal.h>
@@ -69,6 +70,10 @@
     mTimer = new QTimer();
     connect( mTimer, SIGNAL( timeout() ), this, SLOT( updateDialog() ) );
     mTimer->start( 1000 );
+
+#ifdef Q_OS_FREEBSD    
+    connect( comboBoxIP, SIGNAL( activated(int) ), this, SLOT( updateDialog() ) );
+#endif
 }
 
 InterfaceStatusDialog::~InterfaceStatusDialog()
@@ -152,12 +157,28 @@
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
