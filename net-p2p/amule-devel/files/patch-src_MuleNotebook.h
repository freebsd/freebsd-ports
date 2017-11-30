--- src/MuleNotebook.h.orig	2017-06-03 23:55:41.000000000 +0200
+++ src/MuleNotebook.h	2017-11-20 14:52:35.287092000 +0100
@@ -130,9 +130,9 @@
 
 protected:
 	/**
-	 * Event handler for left or middle mouse button release (for closing pages)
+	 * Event handler for left or middle mouse button to press or release (for closing pages)
 	 */
-	void OnMouseButtonRelease(wxMouseEvent &event);
+	void OnMouseButton(wxMouseEvent &event);
 
 	/**
 	 * Event handler for mouse motion (for highlighting the 'x')
