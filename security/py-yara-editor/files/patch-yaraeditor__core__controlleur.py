--- ./yaraeditor/core/controlleur.py.orig	2012-12-02 11:09:48.000000000 +0000
+++ ./yaraeditor/core/controlleur.py	2013-07-30 23:07:31.000000000 +0000
@@ -329,8 +329,11 @@
         #self.ui_yaraeditor.verticalLayout_7 = QtGui.QVBoxLayout(self.ui_yaraeditor.tab_strings)
         #self.ui_yaraeditor.verticalLayout_7.setObjectName(_fromUtf8("verticalLayout_7"))
         self.ui_yaraeditor.treeMalwareStrings = YTreeWidget(self.ui_yaraeditor.tab_strings)
-        self.ui_yaraeditor.treeMalwareStrings.setHeaderHidden(True)
+        self.ui_yaraeditor.treeMalwareStrings.setHeaderHidden(False)
         self.ui_yaraeditor.treeMalwareStrings.setObjectName(_fromUtf8("treeMalwareStrings"))
+        self.ui_yaraeditor.treeMalwareStrings.setColumnCount(2)
+        self.ui_yaraeditor.treeMalwareStrings.headerItem().setText(0, QtGui.QApplication.translate("YaraEditor", "Value", None, QtGui.QApplication.UnicodeUTF8))
+        self.ui_yaraeditor.treeMalwareStrings.headerItem().setText(1, QtGui.QApplication.translate("YaraEditor", "Type", None, QtGui.QApplication.UnicodeUTF8))
         self.ui_yaraeditor.verticalLayout_7.addWidget(self.ui_yaraeditor.treeMalwareStrings)
         
 
@@ -370,7 +373,7 @@
             self.add_element(self.treeMalwareProperties,"Name",fileInfo.fileName())
             self.add_element(self.treeMalwareProperties,"Path",fileInfo.filePath())
             self.add_element(self.treeMalwareProperties,"Size",str(fileInfo.size()))
-            fi = open(str(fileInfo.filePath()),'r')
+            fi = open(str(fileInfo.filePath()),'rb')
             data = fi.read()
             fi.close()
             sha1 = QtCore.QCryptographicHash.hash(data,QtCore.QCryptographicHash.Sha1).toHex()  
@@ -378,14 +381,16 @@
             self.add_element(self.treeMalwareProperties,"MD5",str(md5))
             self.add_element(self.treeMalwareProperties,"SHA1",str(sha1))
 
-            for s in self.get_strings(data):
-                self.add_element(self.treeMalwareStrings,str(s))
+            for s,t in self.get_strings(data):
+                self.add_element(self.treeMalwareStrings,str(s),t)
             
-    def add_element(self,tree,name,value=""):
+    def add_element(self,tree,name,value="",typeValue=""):
         item = QtGui.QTreeWidgetItem(tree)
         item.setText(0,name)
         if value!="":
             item.setText(1,value)
+        if typeValue!="":
+            item.setText(1,typeValue)            
 
     def remove_element(self,tree,name):
         findings = tree.findItems(name,Qt.MatchCaseSensitive)
@@ -393,12 +398,33 @@
             index = tree.indexOfTopLevelItem(f)
             tree.takeTopLevelItem(index)
 
+    def get_ascii(self,data,length_min=7):
+        strings = set()
+        for m in re.finditer("([\x21-\x7e]{4,})", data):
+            if len(m.group(1))> length_min:
+                strings.add(m.group(1))
+        return strings
+
+    def get_unicode(self,data,length_min=7):
+        strings = set()
+        for m in re.finditer("([\x20-\x7e]{4,})", data):
+            if len(m.group(1))> length_min:
+                strings.add(m.group(1))
+        return strings
 
     def get_strings(self,data,length_min=7):
-        strings = list()
-        for m in re.finditer("([\x20-\x7e]{3,})", data):
-            if len(m.group(1))> length_min:
-                strings.append(m.group(1))
+        strings_ascii = self.get_ascii(data,length_min)
+        strings_unicode = self.get_unicode(data,length_min)
+        
+        strings = set()
+        for sa in strings_ascii:
+            strings.add((sa,"ascii"))
+
+        for su in strings_unicode:
+            if su in strings:
+                continue
+            strings.add((su,"unicode"))
+
         return strings
 
     def maybeSave(self):
@@ -610,7 +636,7 @@
                 logging.debug(traceback.format_exc())
                 self.add_message_output(report)
 
-        self.add_message_output("Finish : %d match" % found)
+        self.add_message_output("Finish : %d matches" % found)
 
     def check_yara(self,rules,path):
         try:
@@ -664,13 +690,14 @@
 
         rules = TEMPLATE_YARA
         rules = rules.replace("###STRINGS###","\n".join(set_strings))
-        rules = rules.replace("###CONDITION###","\t(%s)" % " or ".join(set_condition))
+        #rules = rules.replace("###CONDITION###","\t(%s)" % " and ".join(set_condition))
+        rules = rules.replace("###CONDITION###","\tall of them")
         return rules
 
 
     def generator_add_file(self,path=""): 
         if path == "":
-            pathes = QtGui.QFileDialog.getOpenFileNames(self.mainwindow, "Open File","","All (*.*)")
+            pathes = QtGui.QFileDialog.getOpenFileNames(self.mainwindow, "Open File","","All (*)")
         if pathes == None:
             return 
 
@@ -688,7 +715,7 @@
 
     def generator_add_family(self,path=None): 
         if path == None:
-            pathes = QtGui.QFileDialog.getOpenFileNames(self.mainwindow, "Open File","","All (*.*)")
+            pathes = QtGui.QFileDialog.getOpenFileNames(self.mainwindow, "Open File","","All (*)")
         else:
             pathes = path
 
@@ -715,16 +742,25 @@
             self.generator_remove_string(item.text())
 
         self.ui_generator.treeWidget.clear()
-        for s,v in self.set_string.iteritems():
-            if v>=countFamily:
-                self.add_element(self.ui_generator.treeWidget,str(s))
+        good = False
+        while not good:
+            for s,v in self.set_string.iteritems():
+                print s,v
+                if v>=countFamily:
+                    self.add_element(self.ui_generator.treeWidget,str(s))
+                    good = True
+            countFamily -=1
 
 
     def generator_add_string(self,malware):
-        f = open(malware,'r')
+        f = open(malware,'rb')
         data = f.read()
         f.close()
-        for s in self.get_strings(data):
+        strings_in_file = set()
+        for s,t in self.get_strings(data):
+            strings_in_file.add(s)
+
+        for s in strings_in_file:
             if '"' not in s and '\\' not in s and not len(s)>40:
                 if self.set_string.has_key(str(s)):
                     self.set_string[str(s)] += 1
@@ -733,10 +769,10 @@
 
 
     def generator_remove_string(self,malware):
-        f = open(malware,'r')
+        f = open(malware,'rb')
         data = f.read()
         f.close()
-        for s in self.get_strings(data):
+        for s,t in self.get_strings(data):
             if self.set_string.has_key(str(s)):
                 self.set_string[str(s)] = 0
 
