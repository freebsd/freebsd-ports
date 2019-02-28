--- syncplay/ui/GuiConfiguration.py.orig	2019-01-15 11:08:33 UTC
+++ syncplay/ui/GuiConfiguration.py
@@ -1109,8 +1109,8 @@ class ConfigDialog(QtWidgets.QDialog):
             if lang == self.config['language']:
                 self.languageCombobox.setCurrentIndex(self.languageCombobox.count()-1)
         self.languageCombobox.currentIndexChanged.connect(self.languageChanged)
-        self.languageLayout.addWidget(self.languageLabel, 1, 0)
-        self.languageLayout.addWidget(self.languageCombobox, 1, 1)
+        self.languageLayout.addWidget(self.languageLabel, 1, Qt.AlignLeft)
+        self.languageLayout.addWidget(self.languageCombobox, 1, Qt.AlignLeft)
         self.displaySettingsLayout.addWidget(self.languageFrame)
 
         self.languageLabel.setObjectName("language")
