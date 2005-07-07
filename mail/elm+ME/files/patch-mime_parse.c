Do not pause to inform the user, metamail is not needed.
Maybe, there is no need to even say anything at all...

--- melib/mime_parse.c	Sun Jun 27 15:39:33 2004
+++ melib/mime_parse.c	Thu Jul  7 16:46:46 2005
@@ -749,5 +749,5 @@
 		
 		if (! (tmp & NOTPLAIN_need_metamail)) {
-		    lib_error(CATGETS(elm_msg_cat, MeSet, MeParsingMimeNoMetamail,
+		    lib_transient(CATGETS(elm_msg_cat, MeSet, MeParsingMimeNoMetamail,
 				      "Parsing MIME structure... metamail not needed"));	    
 		}
