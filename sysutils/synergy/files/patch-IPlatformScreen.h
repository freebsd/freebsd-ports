--- lib/synergy/IPlatformScreen.h.orig	Wed Sep  1 13:56:16 2004
+++ lib/synergy/IPlatformScreen.h	Wed Sep  1 13:56:47 2004
@@ -171,7 +171,6 @@
 						getActiveModifiers() const = 0;
 	virtual const char*	getKeyName(KeyButton) const = 0;
 
-protected:
 	//! Handle system event
 	/*!
 	A platform screen is expected to install a handler for system
