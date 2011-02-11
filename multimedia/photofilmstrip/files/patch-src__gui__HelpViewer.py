--- ./src/gui/HelpViewer.py.orig	2010-12-20 01:52:21.000000000 -0800
+++ ./src/gui/HelpViewer.py	2011-02-05 12:17:23.000000000 -0800
@@ -36,7 +36,7 @@
     def __init__(self):
         self.__htmlCtrl = wx.html.HtmlHelpController()
         docFile = os.path.join(os.path.dirname(os.path.abspath(sys.argv[0])), 
-                               "..", "doc", "photofilmstrip", "photofilmstrip.hhp")
+                               "..", "photofilmstrip", "doc", "photofilmstrip.hhp")
         fn = os.path.abspath(docFile)
         self.__htmlCtrl.AddBook(fn)
         
