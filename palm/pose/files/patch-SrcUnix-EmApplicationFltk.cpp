--- ../SrcUnix/EmApplicationFltk.cpp.orig	Fri Mar 29 05:11:19 2002
+++ ../SrcUnix/EmApplicationFltk.cpp	Tue Apr 16 12:51:28 2002
@@ -115,6 +115,7 @@
 
 EmApplicationFltk::EmApplicationFltk (void) :
 	EmApplication (),
+	fClipboardWidget (NULL),
 	fAppWindow (NULL)
 {
 	EmAssert (gHostApplication == NULL);
@@ -138,6 +139,7 @@
 EmApplicationFltk::~EmApplicationFltk (void)
 {
 	delete fAppWindow;
+	delete fClipboardWidget;
 
 	EmAssert (gHostApplication == this);
 	gHostApplication = NULL;
