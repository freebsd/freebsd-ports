--- pwc-dec23.c.orig	2006-06-04 01:39:14 UTC
+++ pwc-dec23.c
@@ -261,7 +261,7 @@ void pwc_dec23_init(int type, int release, unsigned ch
 {
 	int flags;
 	struct pwc_dec23_private *pdev = data;
-	release = release;
+	/* release = release; */
 
 	switch (type) {
 	case 720:
@@ -277,7 +277,7 @@ void pwc_dec23_init(int type, int release, unsigned ch
 			pdev->zz = 6;
 		flags = mode[2] >> 5;	/* our: 7 */
 
-		fill_table_color(flags, (unsigned int *)KiaraRomTable,
+		fill_table_color(flags, (const unsigned int *)KiaraRomTable,
 				 pdev->table_0004, pdev->table_8004);
 		break;
 
@@ -293,7 +293,7 @@ void pwc_dec23_init(int type, int release, unsigned ch
 			pdev->zz = 6;
 		flags = mode[2] >> 3;
 
-		fill_table_color(flags, (unsigned int *)TimonRomTable,
+		fill_table_color(flags, (const unsigned int *)TimonRomTable,
 				 pdev->table_0004, pdev->table_8004);
 		break;
 
@@ -347,7 +347,6 @@ static void DecompressBand23(const struct pwc_dec23_pr
 	unsigned int reservoir, nbits_in_reservoir;
 	int first_4_bits;
 	unsigned int bytes_per_channel;
-	int line_size;		/* size of the line (4Y+U+V) */
 	int passes;
 	const unsigned char *ptable0004, *ptable8004;
 
@@ -368,8 +367,6 @@ static void DecompressBand23(const struct pwc_dec23_pr
 
 	get_nbits(reservoir, nbits_in_reservoir, stream, 4, first_4_bits);
 
-	line_size = pixels_per_line * 3;
-
 	for (passes = 0; passes < 2; passes++) {
 		if (passes == 0) {
 			bytes_per_channel = pixels_per_line;
@@ -605,12 +602,13 @@ void pwc_dec23_decompress(const struct pwc_coord *imag
 			  int flags, const void *data, int bandlength)
 {
 	const struct pwc_dec23_private *pdev = data;
-	unsigned char *pout, *pout_planar_y = NULL, *pout_planar_u =
+	//unsigned char *pout;
+	unsigned char *pout_planar_y = NULL, *pout_planar_u =
 	    NULL, *pout_planar_v = NULL;
 	int i, n, stride, pixel_size;
 
 	if (flags & PWCX_FLAG_BAYER) {
-		pout = dst + (view->x * offset->y) + offset->x;
+		//pout = dst + (view->x * offset->y) + offset->x;
 		pixel_size = view->x * 4;
 	} else {
 		n = view->x * view->y;
@@ -632,7 +630,7 @@ void pwc_dec23_decompress(const struct pwc_coord *imag
 			//TODO:
 			//DecompressBandBayer(pdev,src,pout,image.x,view->x,flags);
 			src += bandlength;
-			pout += pixel_size;
+			//pout += pixel_size;
 		} else {
 			DecompressBand23(pdev, src, pout_planar_y,
 					 pout_planar_u, pout_planar_v, image->x,
