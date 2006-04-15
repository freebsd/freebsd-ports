--- common.c.orig	Sun Aug 29 20:11:00 2004
+++ common.c	Sat Apr 15 00:11:40 2006
@@ -85,7 +85,7 @@
 
 	if (datasrc->bytes_in_buffer == 0) {
 		if (! (*datasrc->fill_input_buffer) (cinfo))
-			err(1, "%s: fill_input", __FUNCTION__);
+			err(1, "jpeg_getc: fill_input");
 	}
 	datasrc->bytes_in_buffer--;
 	return GETJOCTET(*datasrc->next_input_byte++);
@@ -308,7 +308,7 @@
 
 	dcts = malloc(bits * sizeof (short));
 	if (dcts == NULL) {
-		warn("%s: malloc", __FUNCTION__);
+		warn("prepare_all: malloc");
 		return (-1);
 	}
 
@@ -374,7 +374,7 @@
 	if (pdcts != NULL) {
 		dcts = malloc(bits * sizeof (short));
 		if (dcts == NULL) {
-			warn("%s: malloc", __FUNCTION__);
+			warn("prepare_normal: malloc");
 			return (-1);
 		}
 	}
@@ -422,7 +422,7 @@
 		/* XXX - wasteful */
 		back[comp] = calloc(off, sizeof (char));
 		if (back[comp] == NULL) {
-			warn("%s: calloc", __FUNCTION__);
+			warn("prepare_jphide: calloc");
 			goto err;
 		}
 	}
@@ -430,7 +430,7 @@
 	if (pdcts != NULL) {
 		dcts = malloc(mbits * sizeof (short));
 		if (dcts == NULL) {
-			warn("%s: malloc", __FUNCTION__);
+			warn("prepare_jphide: malloc");
 			goto err;
 		}
 	}
