CVE-2014-0209

--- src/fontfile/fontdir.c.orig	2014-01-07 17:25:08.000000000 +0100
+++ src/fontfile/fontdir.c	2014-05-13 18:13:40.000000000 +0200
@@ -177,6 +177,11 @@ FontFileAddEntry(FontTablePtr table, Fon
     if (table->sorted)
 	return (FontEntryPtr) 0;    /* "cannot" happen */
     if (table->used == table->size) {
+	if (table->size >= ((INT32_MAX / sizeof(FontEntryRec)) - 100))
+	    /* If we've read so many entries we're going to ask for 2gb
+	       or more of memory, something is so wrong with this font
+	       directory that we should just give up before we overflow. */
+	    return NULL;
 	newsize = table->size + 100;
 	entry = realloc(table->entries, newsize * sizeof(FontEntryRec));
 	if (!entry)
