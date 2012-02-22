--- ./src/main/display.cc.orig	2012-02-20 17:02:30.000000000 -0500
+++ ./src/main/display.cc	2012-02-21 00:40:06.000000000 -0500
@@ -29,12 +29,6 @@
 #include <thmlhtmlhref.h>
 #include <gbfhtmlhref.h>
 #include <teihtmlhref.h>
-#ifndef NO_SWORD_SET_RENDER_NOTE_NUMBERS
-/* these files are erroneously uninstalled as of previous release */
-#include <osisxhtml.h>
-#include <thmlxhtml.h>
-#include <gbfxhtml.h>
-#endif
 
 #include <osisvariants.h>
 #include <thmlvariants.h>
@@ -650,7 +644,6 @@
 	if ((reported = backend->get_entry_attribute("Footnote", "1", "n", false))) {
 		g_free(reported);		// dispose of test junk.
 
-#ifdef NO_SWORD_SET_RENDER_NOTE_NUMBERS
 		//
 		// with recent engine change to auto-render
 		// note/xref markers, this is unneeded.
@@ -689,7 +682,6 @@
 		// naïveté: if any verse uses 'n=', all do: reset for next verse.
 		if (reset)
 			footnote = 0;
-#endif /* NO_SWORD_SET_RENDER_NOTE_NUMBERS */
 	}
 
 	// otherwise we simply count notes & xrefs through the verse.
@@ -762,41 +754,8 @@
 	}
 }
 
-#ifdef NO_SWORD_SET_RENDER_NOTE_NUMBERS
 // placeholder for older Sword.
 #define	set_render_numbers(x,y)	/* nothing */
-#else
-void
-set_render_numbers(SWModule& imodule, GLOBAL_OPS *ops)
-{
-	for (FilterList::const_iterator it =
-		 imodule.getRenderFilters().begin();
-	     it != imodule.getRenderFilters().end();
-	     it++) {
-		OSISHTMLHREF *f1 = dynamic_cast<OSISHTMLHREF *>(*it);
-		if (f1)
-			f1->setRenderNoteNumbers((ops->xrefnotenumbers != 0));
-		ThMLHTMLHREF *f2 = dynamic_cast<ThMLHTMLHREF *>(*it);
-		if (f2)
-			f2->setRenderNoteNumbers((ops->xrefnotenumbers != 0));
-		GBFHTMLHREF *f3 = dynamic_cast<GBFHTMLHREF *>(*it);
-		if (f3)
-			f3->setRenderNoteNumbers((ops->xrefnotenumbers != 0));
-		TEIHTMLHREF *f4 = dynamic_cast<TEIHTMLHREF *>(*it);
-		if (f4)
-			f4->setRenderNoteNumbers((ops->xrefnotenumbers != 0));
-		OSISXHTML *f5 = dynamic_cast<OSISXHTML *>(*it);
-		if (f5)
-			f5->setRenderNoteNumbers((ops->xrefnotenumbers != 0));
-		ThMLXHTML *f6 = dynamic_cast<ThMLXHTML *>(*it);
-		if (f6)
-			f6->setRenderNoteNumbers((ops->xrefnotenumbers != 0));
-		GBFXHTML *f7 = dynamic_cast<GBFXHTML *>(*it);
-		if (f7)
-			f7->setRenderNoteNumbers((ops->xrefnotenumbers != 0));
-	}
-}
-#endif /* !NO_SWORD_SET_RENDER_NOTE_NUMBERS */
 
 //
 // display of commentary by chapter.
