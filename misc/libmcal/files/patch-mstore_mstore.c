--- mstore/mstore.c.orig	Tue Jan 28 18:31:33 2003
+++ mstore/mstore.c	Tue Mar 20 21:46:20 2007
@@ -308,7 +308,7 @@
 	if (!reopen) {
 		if ((stream = calloc(1, sizeof(*stream))) == NULL)
 			goto fail;
-		if ((DATA = calloc(1, sizeof(*DATA))) == NULL)
+		if ((stream->data = calloc(1, sizeof(*DATA))) == NULL)
 			goto fail;
 	}
 
@@ -773,7 +773,7 @@
         while((event=read_event(calfile))) {
 	  if (event->id == modified_event->id)
 	    {
-	    (const CALEVENT*)event = modified_event;         
+	      event = modified_event;
 	  /*is more required here to assign objects, a loop through all the properties*/
 	    /*    We actually only want to modify any individual property, not the whole thing..
 		  TODO */
