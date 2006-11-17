--- enchant/checker/wxSpellCheckerDialog.py	Thu Aug 10 09:33:29 2006
+++ enchant/checker/wxSpellCheckerDialog.py.port	Sun Nov 12 22:50:39 2006
@@ -49,6 +49,8 @@
 
 """
 
+import wxversion
+wxversion.select('2.6')
 import wx
 
 class wxSpellCheckerDialog(wx.Dialog):
