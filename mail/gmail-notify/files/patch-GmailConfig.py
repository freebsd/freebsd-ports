*** GmailConfig.py.orig	Tue May  3 10:02:32 2005
--- GmailConfig.py	Tue Jun  7 15:27:30 2005
***************
*** 18,24 ****
  	configElements = None 
  
  	# Declare global variables for configuration as dictionary
! 	options = { "gmailusername":None, "gmailpassword":None, "browserpath":"firefox", "lang":"English",   
  				"voffset":0, "hoffset":0, "checkinterval":20000, 
  				"animationdelay":15, "popuptimespan":5000}
  					
--- 18,24 ----
  	configElements = None 
  
  	# Declare global variables for configuration as dictionary
! 	options = { "gmailusername":None, "gmailpassword":None, "browserpath":"firefox", "lang":"English", "actionpath":"play",  
  				"voffset":0, "hoffset":0, "checkinterval":20000, 
  				"animationdelay":15, "popuptimespan":5000}
  					
***************
*** 36,43 ****
  		self.window.set_title( self.lang.get_string(1) )
  		self.window.set_border_width( 5 )
  		self.window.set_position( gtk.WIN_POS_CENTER )
! 		self.window.set_modal( gtk.TRUE )
! 		self.window.set_resizable(gtk.FALSE)
  		icon = gtk.gdk.pixbuf_new_from_file(ICON_PATH)
  		gtk.window_set_default_icon_list( (icon) )
  
--- 36,43 ----
  		self.window.set_title( self.lang.get_string(1) )
  		self.window.set_border_width( 5 )
  		self.window.set_position( gtk.WIN_POS_CENTER )
! 		self.window.set_modal( True )
! 		self.window.set_resizable(False)
  		icon = gtk.gdk.pixbuf_new_from_file(ICON_PATH)
  		gtk.window_set_default_icon_list( (icon) )
  
***************
*** 49,54 ****
--- 49,55 ----
  						["gmailusername",2,None,None],
  						["gmailpassword",22,None,None],
  						["browserpath",3,None,None],
+ 						["actionpath",99,None,None],
  						["voffset",28,None,None],
  						["hoffset",27,None,None],
  						["checkinterval",31,None,None],
***************
*** 57,63 ****
  					]
  
  		# Create table and attach to window
! 		table = gtk.Table( rows=11, columns=2, homogeneous=gtk.FALSE )
  
  		self.window.add(table)
  
--- 58,64 ----
  					]
  
  		# Create table and attach to window
! 		table = gtk.Table( rows=12, columns=2, homogeneous=False )
  
  		self.window.add(table)
  
***************
*** 74,80 ****
  				textbox.set_text( str( self.options[curVar] ) )
  
  			if ( curVar == "gmailpassword" ):
! 				textbox.set_visibility( gtk.FALSE )
  				textbox.set_invisible_char( '*' )
  
  			# Store widget in element array
--- 75,81 ----
  				textbox.set_text( str( self.options[curVar] ) )
  
  			if ( curVar == "gmailpassword" ):
! 				textbox.set_visibility( False )
  				textbox.set_invisible_char( '*' )
  
  			# Store widget in element array
***************
*** 109,120 ****
  		
  
  		if ( self.readLoginFromFile ):
! 			self.savePassword.set_active( gtk.TRUE )
  		else:
! 			self.savePassword.set_active( gtk.FALSE )
  			
  		self.savePassword.show()
! 		table.attach( alignment, 0, 2, 9, 10 )
  		alignment.show()
  
  		# Add combobox to select language 
--- 110,121 ----
  		
  
  		if ( self.readLoginFromFile ):
! 			self.savePassword.set_active( True )
  		else:
! 			self.savePassword.set_active( False )
  			
  		self.savePassword.show()
! 		table.attach( alignment, 0, 2, 10, 11 )
  		alignment.show()
  
  		# Add combobox to select language 
***************
*** 129,142 ****
                                  self.cbo_langs.append_text( one_lang.get_name())
  		self.cbo_langs.set_active(0)
  		# Attach combobox and label
! 		table.attach( self.lbl_langs, 0, 1, 8, 9 )
  		self.lbl_langs.show()
! 		table.attach( self.cbo_langs, 1, 2, 8, 9, ypadding=5 )
  		self.cbo_langs.show()
  		
  		# Add 'Close' button
  		button = gtk.Button( stock=gtk.STOCK_OK )
! 		table.attach( button, 0, 2, 10, 11, ypadding=2 )
  		button.connect( "clicked", self.onOkay )
  		button.show()
  
--- 130,143 ----
                                  self.cbo_langs.append_text( one_lang.get_name())
  		self.cbo_langs.set_active(0)
  		# Attach combobox and label
! 		table.attach( self.lbl_langs, 0, 1, 9, 10 )
  		self.lbl_langs.show()
! 		table.attach( self.cbo_langs, 1, 2, 9, 10, xpadding=0, ypadding=5 )
  		self.cbo_langs.show()
  		
  		# Add 'Close' button
  		button = gtk.Button( stock=gtk.STOCK_OK )
! 		table.attach( button, 0, 2, 11, 12, xpadding=0, ypadding=2 )
  		button.connect( "clicked", self.onOkay )
  		button.show()
  
***************
*** 206,212 ****
  	def onDelete( self, widget, data=None ):
  		gtk.main_quit()
  		self.hide()
! 		return gtk.TRUE
  	
  	def onOkay( self, widget, callback_data=None ):
  		errorString = ""
--- 207,213 ----
  	def onDelete( self, widget, data=None ):
  		gtk.main_quit()
  		self.hide()
! 		return True
  	
  	def onOkay( self, widget, callback_data=None ):
  		errorString = ""
