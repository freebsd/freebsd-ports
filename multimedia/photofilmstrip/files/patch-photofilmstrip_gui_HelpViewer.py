--- photofilmstrip/gui/HelpViewer.py.orig	2015-01-25 19:27:30.213707995 +0600
+++ photofilmstrip/gui/HelpViewer.py	2015-01-25 19:28:35.363702863 +0600
@@ -36,7 +36,7 @@
     def __init__(self):
         self.__htmlCtrl = wx.html.HtmlHelpController()
         docFile = os.path.join(os.path.dirname(os.path.abspath(sys.argv[0])), 
-                               "..", "share", "doc", "photofilmstrip", "photofilmstrip.hhp")
+                               "..", "photofilmstrip", "doc", "photofilmstrip.hhp")
         fn = os.path.abspath(docFile)
         self.__htmlCtrl.AddBook(fn)
         
