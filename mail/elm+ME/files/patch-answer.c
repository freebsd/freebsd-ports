int and void* are not always of the same size. This patch eliminates
a compiler warning...

--- utils/answer.c	Wed Jul 21 12:36:33 2004
+++ utils/answer.c	Wed Jul  6 23:48:29 2005
@@ -380,5 +380,5 @@
 	read(user_data, buffer, entry.length > VERY_LONG_STRING ? VERY_LONG_STRING : entry.length);
 	if ((entry.type & GROUP) != 0 && mailing) {
-	    if (expand_group(sprbuffer, buffer + (int) entry.address,
+	    if (expand_group(sprbuffer, buffer + (intptr_t) entry.address,
 			     depth, sizeof sprbuffer) < 0)
 		return NULL;
@@ -386,6 +386,6 @@
 	    elm_sfprintf(sprbuffer, sizeof sprbuffer,
 			 FRM("%s (%s)"), 
-			 buffer + (int) entry.address,
-			 buffer + (int) entry.name);
+			 buffer + (intptr_t) entry.address,
+			 buffer + (intptr_t) entry.name);
 	}
 	return sprbuffer;
