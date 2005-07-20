*** notifier.py.orig	Tue May  3 10:02:33 2005
--- notifier.py	Thu Jun 23 23:30:03 2005
***************
*** 7,13 ****
  import time
  import libgmail
  import os
! import pytrayicon
  import sys
  import warnings
  import ConfigParser
--- 7,13 ----
  import time
  import libgmail
  import os
! import trayicon
  import sys
  import warnings
  import ConfigParser
***************
*** 82,88 ****
  		self.popuptimer=0
  		self.waittimer=0
  		# Create the tray icon object
! 		self.tray = pytrayicon.TrayIcon(self.lang.get_string(21));
  		self.eventbox = gtk.EventBox()
  		self.tray.add(self.eventbox)
  		self.eventbox.connect("button_press_event", self.tray_icon_clicked)
--- 82,88 ----
  		self.popuptimer=0
  		self.waittimer=0
  		# Create the tray icon object
! 		self.tray = trayicon.TrayIcon(self.lang.get_string(21));
  		self.eventbox = gtk.EventBox()
  		self.tray.add(self.eventbox)
  		self.eventbox.connect("button_press_event", self.tray_icon_clicked)
***************
*** 205,210 ****
--- 205,211 ----
  		self.imageicon = gtk.Image()
  
  		if attrs[1]>0:
+ 		  	os.system(self.options['actionpath']+" &")	
  			print str(attrs[1])+" new messages"
  			sender = attrs[2]
  			subject= attrs[3]
