--- ./yaraeditor/ui/rules_generator.py.orig	2012-12-02 11:09:53.000000000 +0000
+++ ./yaraeditor/ui/rules_generator.py	2013-07-30 23:07:31.000000000 +0000
@@ -2,7 +2,7 @@
 
 # Form implementation generated from reading ui file 'rules_generator.ui'
 #
-# Created: Sun Dec  2 12:09:53 2012
+# Created: Tue Feb 26 07:52:45 2013
 #      by: PyQt4 UI code generator 4.9.1
 #
 # WARNING! All changes made in this file will be lost!
@@ -17,9 +17,18 @@
 class Ui_DialogGenerator(object):
     def setupUi(self, DialogGenerator):
         DialogGenerator.setObjectName(_fromUtf8("DialogGenerator"))
-        DialogGenerator.resize(728, 507)
+        DialogGenerator.resize(728, 610)
         self.verticalLayout = QtGui.QVBoxLayout(DialogGenerator)
         self.verticalLayout.setObjectName(_fromUtf8("verticalLayout"))
+        self.label = QtGui.QLabel(DialogGenerator)
+        self.label.setObjectName(_fromUtf8("label"))
+        self.verticalLayout.addWidget(self.label)
+        self.label_4 = QtGui.QLabel(DialogGenerator)
+        self.label_4.setObjectName(_fromUtf8("label_4"))
+        self.verticalLayout.addWidget(self.label_4)
+        self.label_5 = QtGui.QLabel(DialogGenerator)
+        self.label_5.setObjectName(_fromUtf8("label_5"))
+        self.verticalLayout.addWidget(self.label_5)
         self.widget = QtGui.QWidget(DialogGenerator)
         self.widget.setObjectName(_fromUtf8("widget"))
         self.horizontalLayout = QtGui.QHBoxLayout(self.widget)
@@ -86,6 +95,9 @@
 
     def retranslateUi(self, DialogGenerator):
         DialogGenerator.setWindowTitle(QtGui.QApplication.translate("DialogGenerator", "Dialog", None, QtGui.QApplication.UnicodeUTF8))
+        self.label.setText(QtGui.QApplication.translate("DialogGenerator", "1 - Adding elements in the \"Same Family\", the strings will be retained only those that are found in each element.", None, QtGui.QApplication.UnicodeUTF8))
+        self.label_4.setText(QtGui.QApplication.translate("DialogGenerator", "2 - Adding elements in the \"Other Malware\", the strings in these files will not be selected to build the rule.", None, QtGui.QApplication.UnicodeUTF8))
+        self.label_5.setText(QtGui.QApplication.translate("DialogGenerator", "3 - In the middle part, you can see only the strings used for the detection.", None, QtGui.QApplication.UnicodeUTF8))
         self.label_2.setText(QtGui.QApplication.translate("DialogGenerator", "Other Malware (False positive)", None, QtGui.QApplication.UnicodeUTF8))
         self.btnBrowseNewFile.setText(QtGui.QApplication.translate("DialogGenerator", "...", None, QtGui.QApplication.UnicodeUTF8))
         self.label_3.setText(QtGui.QApplication.translate("DialogGenerator", "Same Family", None, QtGui.QApplication.UnicodeUTF8))
