--- ./yaraeditor/ui/yaraeditor.py.orig	2012-12-02 11:09:53.000000000 +0000
+++ ./yaraeditor/ui/yaraeditor.py	2013-07-30 23:07:31.000000000 +0000
@@ -2,7 +2,7 @@
 
 # Form implementation generated from reading ui file 'yaraeditor.ui'
 #
-# Created: Sun Dec  2 12:09:53 2012
+# Created: Tue Feb 26 07:52:45 2013
 #      by: PyQt4 UI code generator 4.9.1
 #
 # WARNING! All changes made in this file will be lost!
@@ -17,10 +17,11 @@
 class Ui_YaraEditor(object):
     def setupUi(self, YaraEditor):
         YaraEditor.setObjectName(_fromUtf8("YaraEditor"))
-        YaraEditor.resize(1117, 600)
+        YaraEditor.resize(1117, 609)
         icon = QtGui.QIcon()
         icon.addPixmap(QtGui.QPixmap(_fromUtf8(":/logo/images/logo.jpg")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
         YaraEditor.setWindowIcon(icon)
+        YaraEditor.setUnifiedTitleAndToolBarOnMac(True)
         self.centralwidget = QtGui.QWidget(YaraEditor)
         self.centralwidget.setObjectName(_fromUtf8("centralwidget"))
         self.verticalLayout = QtGui.QVBoxLayout(self.centralwidget)
@@ -34,18 +35,6 @@
         self.widgetEditor.setObjectName(_fromUtf8("widgetEditor"))
         self.horizontalLayout.addWidget(self.widgetEditor)
         self.verticalLayout.addWidget(self.MainWidget)
-        self.widgetOutput = QtGui.QWidget(self.centralwidget)
-        self.widgetOutput.setMaximumSize(QtCore.QSize(16777215, 110))
-        self.widgetOutput.setObjectName(_fromUtf8("widgetOutput"))
-        self.horizontalLayout_2 = QtGui.QHBoxLayout(self.widgetOutput)
-        self.horizontalLayout_2.setMargin(0)
-        self.horizontalLayout_2.setObjectName(_fromUtf8("horizontalLayout_2"))
-        self.outputEdit = QtGui.QTextEdit(self.widgetOutput)
-        self.outputEdit.setMaximumSize(QtCore.QSize(16777215, 100))
-        self.outputEdit.setReadOnly(True)
-        self.outputEdit.setObjectName(_fromUtf8("outputEdit"))
-        self.horizontalLayout_2.addWidget(self.outputEdit)
-        self.verticalLayout.addWidget(self.widgetOutput)
         YaraEditor.setCentralWidget(self.centralwidget)
         self.menubar = QtGui.QMenuBar(YaraEditor)
         self.menubar.setGeometry(QtCore.QRect(0, 0, 1117, 25))
@@ -95,9 +84,6 @@
         self.verticalLayout_3 = QtGui.QVBoxLayout(self.widgetMalware)
         self.verticalLayout_3.setMargin(0)
         self.verticalLayout_3.setObjectName(_fromUtf8("verticalLayout_3"))
-        self.label_2 = QtGui.QLabel(self.widgetMalware)
-        self.label_2.setObjectName(_fromUtf8("label_2"))
-        self.verticalLayout_3.addWidget(self.label_2)
         self.pathMalware = QtGui.QLineEdit(self.widgetMalware)
         self.pathMalware.setMaximumSize(QtCore.QSize(16777215, 16777215))
         self.pathMalware.setReadOnly(False)
@@ -134,6 +120,20 @@
         self.verticalLayout_6.addWidget(self.tabWidget)
         self.dockWidgetInspector.setWidget(self.dockWidgetContents_4)
         YaraEditor.addDockWidget(QtCore.Qt.DockWidgetArea(2), self.dockWidgetInspector)
+        self.dockWidget = QtGui.QDockWidget(YaraEditor)
+        self.dockWidget.setObjectName(_fromUtf8("dockWidget"))
+        self.dockWidgetContents_3 = QtGui.QWidget()
+        self.dockWidgetContents_3.setObjectName(_fromUtf8("dockWidgetContents_3"))
+        self.verticalLayout_9 = QtGui.QVBoxLayout(self.dockWidgetContents_3)
+        self.verticalLayout_9.setObjectName(_fromUtf8("verticalLayout_9"))
+        self.outputEdit = QtGui.QTextEdit(self.dockWidgetContents_3)
+        self.outputEdit.setMinimumSize(QtCore.QSize(0, 100))
+        self.outputEdit.setMaximumSize(QtCore.QSize(16777215, 16777215))
+        self.outputEdit.setReadOnly(True)
+        self.outputEdit.setObjectName(_fromUtf8("outputEdit"))
+        self.verticalLayout_9.addWidget(self.outputEdit)
+        self.dockWidget.setWidget(self.dockWidgetContents_3)
+        YaraEditor.addDockWidget(QtCore.Qt.DockWidgetArea(8), self.dockWidget)
         self.actionNouveau = QtGui.QAction(YaraEditor)
         icon1 = QtGui.QIcon()
         icon1.addPixmap(QtGui.QPixmap(_fromUtf8(":/icon/images/win/filenew.png")), QtGui.QIcon.Normal, QtGui.QIcon.On)
@@ -145,13 +145,14 @@
         self.actionEnregistrer.setObjectName(_fromUtf8("actionEnregistrer"))
 
         self.retranslateUi(YaraEditor)
-        self.tabWidget.setCurrentIndex(1)
+        self.tabWidget.setCurrentIndex(0)
         QtCore.QMetaObject.connectSlotsByName(YaraEditor)
 
     def retranslateUi(self, YaraEditor):
         YaraEditor.setWindowTitle(QtGui.QApplication.translate("YaraEditor", "Yara-Editor", None, QtGui.QApplication.UnicodeUTF8))
         self.label_3.setText(QtGui.QApplication.translate("YaraEditor", "Yara Browser", None, QtGui.QApplication.UnicodeUTF8))
-        self.label_2.setText(QtGui.QApplication.translate("YaraEditor", "Malware Browser", None, QtGui.QApplication.UnicodeUTF8))
+        self.dockWidgetMalware.setWindowTitle(QtGui.QApplication.translate("YaraEditor", "Malware Browser", None, QtGui.QApplication.UnicodeUTF8))
+        self.dockWidgetInspector.setWindowTitle(QtGui.QApplication.translate("YaraEditor", "Inspector", None, QtGui.QApplication.UnicodeUTF8))
         self.treeMalwareProperties.headerItem().setText(0, QtGui.QApplication.translate("YaraEditor", "Name", None, QtGui.QApplication.UnicodeUTF8))
         self.treeMalwareProperties.headerItem().setText(1, QtGui.QApplication.translate("YaraEditor", "Value", None, QtGui.QApplication.UnicodeUTF8))
         self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab_properties), QtGui.QApplication.translate("YaraEditor", "Tab Properties", None, QtGui.QApplication.UnicodeUTF8))
