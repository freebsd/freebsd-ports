--- common.c	Tue Jan 22 19:25:38 2002
+++ common.c.diff	Wed Dec 29 03:35:11 2004
@@ -85,7 +85,7 @@
 
 	if (datasrc->bytes_in_buffer == 0) {
 		if (! (*datasrc->fill_input_buffer) (cinfo))
-			err(1, __FUNCTION__": fill_input");
+			err(1, "jpeg_getc: fill_input");
 	}
 	datasrc->bytes_in_buffer--;
 	return GETJOCTET(*datasrc->next_input_byte++);
@@ -297,7 +297,7 @@
 
 	dcts = malloc(bits * sizeof (short));
 	if (dcts == NULL) {
-		warn(__FUNCTION__": malloc");
+		warn("prepare_all: malloc");
 		return (-1);
 	}
 
@@ -362,7 +362,7 @@
 	if (pdcts != NULL) {
 		dcts = malloc(bits * sizeof (short));
 		if (dcts == NULL) {
-			warn(__FUNCTION__": malloc");
+			warn("prepare_normal: malloc");
 			return (-1);
 		}
 	}
@@ -410,7 +410,7 @@
 		/* XXX - wasteful */
 		back[comp] = calloc(off, sizeof (char));
 		if (back[comp] == NULL) {
-			warn(__FUNCTION__": calloc");
+			warn("prepare_jphide: calloc");
 			goto err;
 		}
 	}
@@ -418,7 +418,7 @@
 	if (pdcts != NULL) {
 		dcts = malloc(mbits * sizeof (short));
 		if (dcts == NULL) {
-			warn(__FUNCTION__": malloc");
+			warn("prepare_jphide: malloc");
 			goto err;
 		}
 	}
