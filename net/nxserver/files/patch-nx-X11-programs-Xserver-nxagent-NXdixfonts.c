--- nx-X11/programs/Xserver/hw/nxagent/NXdixfonts.c.orig	2006-11-09 12:22:35.000000000 -0455
+++ nx-X11/programs/Xserver/hw/nxagent/NXdixfonts.c	
@@ -2521,7 +2521,7 @@
 		err = (*fpe_functions[fpe->type].start_list_fonts_and_aliases)
 		    ((pointer) c->client, fpe, c->current.pattern,
 		     c->current.patlen, c->current.max_names - c->names->nnames,
-		     &c->current.private);
+		     &c->current.private); /* FIXME: returned mem c->current.private (needed by list_next_font_or_alias) may never be freed */
 		if (err == Suspended) {
 		    if (!c->slept) {
 			ClientSleep(client,
