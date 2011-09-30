--- Hercules/gui/exercisewizard.py.orig	2006-08-27 08:55:00.000000000 +0400
+++ Hercules/gui/exercisewizard.py	2011-09-29 13:00:00.000000000 +0400
@@ -6,7 +6,7 @@
 import wx.xrc as xrc
 import wx.wizard as wiz
 from Hercules.plugins.net_exrx import *
-
+from Hercules.globals import sharedir
 
 class WizardPageStart:
     def __init__(self, parent, page):
@@ -187,7 +187,7 @@
         self.exerciseInfo = []
         
         # Load resource file with wizard pages
-        self.resource = xrc.XmlResource('xrc/exercisewizard.xrc')
+        self.resource = xrc.XmlResource(sharedir + 'xrc/exercisewizard.xrc')
 
         # Create the wizard and the pages
         self.wizard = self.resource.LoadObject(self.parent,
