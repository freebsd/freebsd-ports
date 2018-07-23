lib/AutoTypeGlobalX11.cpp:65:17: error: assigning to 'Window' (aka 'unsigned long') from incompatible type 'nullptr_t'
                focusWindow = NULL;
                              ^~~~
--- src/lib/AutoTypeGlobalX11.cpp.orig	2018-07-23 15:16:19 UTC
+++ src/lib/AutoTypeGlobalX11.cpp
@@ -62,7 +62,7 @@ void AutoTypeGlobalX11::perform(IEntryHandle* entry, b
 		focusedWindow = 0;
 	}
 	else {
-		focusWindow = NULL;
+		focusWindow = 0;
 	}
 	
 	AutoTypeX11::perform(entry, hideWindow, nr, wasLocked);
