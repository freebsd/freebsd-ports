--- common.c.orig	2004-08-29 23:11:00 UTC
+++ common.c
@@ -85,7 +85,7 @@ jpeg_getc(j_decompress_ptr cinfo)
 
 	if (datasrc->bytes_in_buffer == 0) {
 		if (! (*datasrc->fill_input_buffer) (cinfo))
-			err(1, "%s: fill_input", __FUNCTION__);
+			err(1, "jpeg_getc: fill_input");
 	}
 	datasrc->bytes_in_buffer--;
 	return GETJOCTET(*datasrc->next_input_byte++);
@@ -308,7 +308,7 @@ prepare_all_gradx(short **pdcts, int *pb
 
 	dcts = malloc(bits * sizeof (short));
 	if (dcts == NULL) {
-		warn("%s: malloc", __FUNCTION__);
+		warn("prepare_all: malloc");
 		return (-1);
 	}
 
@@ -374,7 +374,7 @@ prepare_normal(short **pdcts, int *pbits
 	if (pdcts != NULL) {
 		dcts = malloc(bits * sizeof (short));
 		if (dcts == NULL) {
-			warn("%s: malloc", __FUNCTION__);
+			warn("prepare_normal: malloc");
 			return (-1);
 		}
 	}
@@ -422,7 +422,7 @@ prepare_jphide(short **pdcts, int *pbits
 		/* XXX - wasteful */
 		back[comp] = calloc(off, sizeof (char));
 		if (back[comp] == NULL) {
-			warn("%s: calloc", __FUNCTION__);
+			warn("prepare_jphide: calloc");
 			goto err;
 		}
 	}
@@ -430,7 +430,7 @@ prepare_jphide(short **pdcts, int *pbits
 	if (pdcts != NULL) {
 		dcts = malloc(mbits * sizeof (short));
 		if (dcts == NULL) {
-			warn("%s: malloc", __FUNCTION__);
+			warn("prepare_jphide: malloc");
 			goto err;
 		}
 	}
