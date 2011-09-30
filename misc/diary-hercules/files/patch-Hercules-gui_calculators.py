--- Hercules/gui/calculators.py.orig	2006-08-12 17:04:23.000000000 +0400
+++ Hercules/gui/calculators.py	2011-09-29 12:56:43.000000000 +0400
@@ -4,12 +4,12 @@
 
 import wx
 import wx.xrc as xrc
-
+from Hercules.globals import sharedir
 
 class IdealBody:
     """Ideal Body Measurements Calculator"""
     def __init__(self, parent):
-        self.resource = xrc.XmlResource('xrc/calculators.xrc')
+        self.resource = xrc.XmlResource(sharedir + 'xrc/calculators.xrc')
         self.dlg = self.resource.LoadDialog(parent, 'Calc01Dialog')
 
         self.wristBox = xrc.XRCCTRL(self.dlg, 'wristBox')
@@ -96,7 +96,7 @@
 class BMICalc:
     """Body Mass Index calculator for average people only"""
     def __init__(self, parent):
-        self.resource = xrc.XmlResource('xrc/calculators.xrc')
+        self.resource = xrc.XmlResource(sharedir + 'xrc/calculators.xrc')
         self.dlg = self.resource.LoadDialog(parent, 'CalcBMIDialog')
 
         self.maleRadio = xrc.XRCCTRL(self.dlg, 'maleRadio')
@@ -236,7 +236,7 @@
 class Cal2KJ:
     """Calorie KiloJoule Conversion"""
     def __init__(self, parent):
-        self.resource = xrc.XmlResource('xrc/calculators.xrc')
+        self.resource = xrc.XmlResource(sharedir + 'xrc/calculators.xrc')
         self.dlg = self.resource.LoadDialog(parent, 'CalcCal2KJDialog')
 
         self.caloriesBox = xrc.XRCCTRL(self.dlg, 'caloriesBox')
