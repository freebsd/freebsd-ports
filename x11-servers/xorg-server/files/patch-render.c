--- programs/Xserver/render/render.c.orig	Mon May 29 09:43:15 2006
+++ programs/Xserver/render/render.c	Mon May 29 09:45:02 2006
@@ -1340,7 +1340,7 @@
 	{
 	    if (buffer + sizeof (GlyphSet) < end)
 	    {
-                memcpy(&gs, buffer, sizeof(GlyphSet));
+		gs = *(CARD32 *) buffer;
 		glyphSet = (GlyphSetPtr) SecurityLookupIDByType (client,
 								 gs,
 								 GlyphSetType,
