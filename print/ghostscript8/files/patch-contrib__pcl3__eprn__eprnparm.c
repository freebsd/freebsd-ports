--- contrib/pcl3/eprn/eprnparm.c.orig	Thu Apr 26 01:27:24 2007
+++ contrib/pcl3/eprn/eprnparm.c	Tue May 15 02:02:42 2007
@@ -146,7 +146,7 @@
   /* First we construct a properly NUL-terminated string */
   s = (char *) malloc(in_value->size + 1);
   if (s == NULL) {
-    fprintf(stderr, ERRPREF
+    eprintf1(ERRPREF
       "Memory allocation failure in eprn_get_int(): %s.\n",
       strerror(errno));
     return_error(gs_error_VMerror);
@@ -352,8 +352,7 @@
   'eprn->media_overrides' should be NULL.
 
   The function returns zero on success and a non-zero ghostscript error value
-  otherwise. In the latter case, an error message will have been issued on
-  stderr.
+  otherwise. In the latter case, an error message will have been issued.
 
 ******************************************************************************/
 
@@ -379,7 +378,7 @@
 
   /* Open the file */
   if ((f = fopen(eprn->media_file, "r")) == NULL) {
-    fprintf(stderr, "%s" ERRPREF "Error opening the media configuration file\n"
+    eprintf5("%s" ERRPREF "Error opening the media configuration file\n"
       "%s    `%s'\n%s  for reading: %s.\n",
       epref, epref, eprn->media_file, epref, strerror(errno));
     return_error(gs_error_invalidfileaccess);
@@ -395,7 +394,7 @@
 
     /* Check for buffer overflow */
     if ((s = strchr(buffer, '\n')) == NULL && fgetc(f) != EOF) {
-      fprintf(stderr, "%s" ERRPREF "Exceeding line length %d in "
+      eprintf5("%s" ERRPREF "Exceeding line length %d in "
 	  "media configuration file\n%s  %s, line %d.\n",
 	epref, BUFFER_SIZE - 2 /* '\n'+'\0' */, epref, eprn->media_file, line);
       cleanup();
@@ -453,7 +452,7 @@
       new_list = (eprn_PageDescription *)
 	realloc(list, (read+1)*sizeof(eprn_PageDescription));
       if (new_list == NULL) {
-	fprintf(stderr, "%s" ERRPREF
+	eprintf2("%s" ERRPREF
 	  "Memory allocation failure in eprn_read_media_data(): %s.\n",
 	  epref, strerror(errno));
 	cleanup();
@@ -477,14 +476,14 @@
     {
       ms_MediaCode code = ms_find_code_from_name(s, eprn->flag_desc);
       if (code == ms_none) {
-	fprintf(stderr, "%s" ERRPREF "Unknown media name (%s) in "
+	eprintf5("%s" ERRPREF "Unknown media name (%s) in "
 	    "media configuration file\n%s  %s, line %d.\n",
 	  epref, s, epref, eprn->media_file, line);
 	cleanup();
 	return_error(gs_error_rangecheck);
       }
       if (code & MS_ROTATED_FLAG) {
-	fprintf(stderr, "%s" ERRPREF "Invalid substring \"" MS_ROTATED_STRING
+	eprintf5("%s" ERRPREF "Invalid substring \"" MS_ROTATED_STRING
 	    "\" in media name (%s)\n"
 	  "%s  in media configuration file %s, line %d.\n",
 	  epref, s, epref, eprn->media_file, line);
@@ -499,7 +498,7 @@
 	  &current->bottom, &current->right, &current->top, &chars_read) != 4 ||
 	t[chars_read] != '\0') {
       if (*t != '\0') *(t-1) = ' ';	/* remove NUL after media name */
-      fprintf(stderr, "%s" ERRPREF
+      eprintf5("%s" ERRPREF
 	"Syntax error in media configuration file %s, line %d:\n%s    %s\n",
 	epref, eprn->media_file, line, epref, buffer);
       cleanup();
@@ -509,7 +508,7 @@
     /* Check for sign */
     if (current->left < 0 || current->bottom < 0 || current->right < 0 ||
 	current->top < 0) {
-      fprintf(stderr, "%s" ERRPREF
+      eprintf4("%s" ERRPREF
 	"Ghostscript does not support negative margins (line %d in the\n"
 	"%s  media configuration file %s).\n",
 	epref, line, epref, eprn->media_file);
@@ -530,14 +529,14 @@
        The user might not notice the reason without help, hence we check. */
     if (ms_without_flags(current->code) == ms_CustomPageSize &&
 	eprn->cap->custom == NULL)
-      fprintf(stderr, "%s" WARNPREF "The media configuration file %s\n"
+      eprintf6("%s" WARNPREF "The media configuration file %s\n"
 	"%s    contains a custom page size entry in line %d, "
 	  "but custom page sizes\n"
 	"%s    are not supported by the %s.\n",
 	wpref, eprn->media_file, wpref, line, wpref, eprn->cap->name);
   }
   if (ferror(f)) {
-    fprintf(stderr, "%s" ERRPREF
+    eprintf2("%s" ERRPREF
       "Unidentified system error while reading `%s'.\n",
       epref, eprn->media_file);
     cleanup();
@@ -547,7 +546,7 @@
 
   /* Was the file empty? */
   if (read == 0) {
-    fprintf(stderr, "%s" ERRPREF "The media configuration file %s\n"
+    eprintf3("%s" ERRPREF "The media configuration file %s\n"
       "%s  does not contain any media information.\n",
       epref, eprn->media_file, epref);
     return_error(gs_error_rangecheck);
@@ -557,7 +556,7 @@
   eprn->media_overrides = (eprn_PageDescription *) gs_malloc(gs_lib_ctx_get_non_gc_memory_t(), read + 1,
     sizeof(eprn_PageDescription), "eprn_read_media_data");
   if (eprn->media_overrides == NULL) {
-    fprintf(stderr, "%s" ERRPREF
+    eprintf1("%s" ERRPREF
       "Memory allocation failure from gs_malloc() in eprn_read_media_data().\n",
       epref);
     free(list);
@@ -585,8 +584,7 @@
   from the specified media configuration file.
 
   The return code will be zero an success and a ghostscript error code
-  otherwise. In the latter case, an error message will have been issued on
-  stderr.
+  otherwise. In the latter case, an error message will have been issued.
 
   The 'length' may be positive in which case it denotes the length of the
   string 'media_file' or zero in which case the string is assumed to be
@@ -629,7 +627,7 @@
     eprn->media_file = (char *)gs_malloc(gs_lib_ctx_get_non_gc_memory_t(), length + 1, sizeof(char),
       "eprn_set_media_data");
     if (eprn->media_file == NULL) {
-      fprintf(stderr, "%s" ERRPREF
+      eprintf1("%s" ERRPREF
 	"Memory allocation failure from gs_malloc() in "
 	"eprn_set_media_data().\n",
 	epref);
@@ -928,9 +926,9 @@
     rc = eprn_get_int(&string_value, eprn_colour_model_list, &temp);	\
     if (rc != 0) {							\
       if (rc != gs_error_VMerror) {					\
-	fprintf(stderr, "%s" ERRPREF "Unknown colour model: `", epref);	\
-	fwrite(string_value.data, sizeof(char), string_value.size, stderr); \
-	fputs("'.\n", stderr);						\
+	eprintf1("%s" ERRPREF "Unknown colour model: `", epref);	\
+	errwrite(string_value.data, sizeof(char)*string_value.size);	\
+	eprintf("'.\n");						\
       }									\
       last_error = rc;							\
       param_signal_error(plist, pname, last_error);			\
@@ -994,7 +992,7 @@
       eprn->black_levels = temp;
     }
     else {
-      fprintf(stderr, "%s" ERRPREF
+      eprintf2("%s" ERRPREF
 	"The value for BlackLevels is outside the range permitted: %d.\n",
 	epref, temp);
       last_error = gs_error_rangecheck;
@@ -1011,7 +1009,7 @@
       eprn->non_black_levels = temp;
     }
     else {
-      fprintf(stderr, "%s" ERRPREF
+      eprintf2("%s" ERRPREF
 	"The value for CMYLevels is outside the range permitted: %d.\n",
 	epref, temp);
       last_error = gs_error_rangecheck;
@@ -1025,8 +1023,8 @@
     bool temp;
     if ((rc = param_read_bool(plist, "CUPSAccounting", &temp)) == 0) {
       if (eprn->CUPS_accounting && !temp)
-	fputs(CUPS_WARNPREF WARNPREF
-	  "Attempt to set CUPSAccounting from true to false.\n", stderr);
+	eprintf(CUPS_WARNPREF WARNPREF
+	  "Attempt to set CUPSAccounting from true to false.\n");
       else eprn->CUPS_accounting = temp;
     }
     else if (rc < 0) last_error = rc;
@@ -1042,10 +1040,10 @@
       eprn->intensity_rendering = temp;
     }
     else {
-      fprintf(stderr, "%s" ERRPREF "Invalid method for IntensityRendering: `",
+      eprintf1("%s" ERRPREF "Invalid method for IntensityRendering: `",
         epref);
-      fwrite(string_value.data, sizeof(char), string_value.size, stderr);
-      fputs("'.\n", stderr);
+      errwrite(string_value.data, sizeof(char)*string_value.size);
+      eprintf("'.\n");
       last_error = gs_error_rangecheck;
       param_signal_error(plist, pname, last_error);
     }
@@ -1066,7 +1064,7 @@
       eprn->default_orientation = temp;
     }
     else {
-      fprintf(stderr,
+      eprintf2(
 	"%s" ERRPREF "LeadingEdge may only have values 0 to 3, not %d.\n",
 	epref, temp);
       last_error = gs_error_rangecheck;
@@ -1111,7 +1109,7 @@
     /* Current (up to at least gs 6.50) ghostscript versions do not accept
        negative MediaPosition values. */
     if (eprn->media_position < 0)
-      fprintf(stderr, "%s" WARNPREF
+      eprintf3("%s" WARNPREF
 	"Ghostscript does not accept negative values (%d) for the\n"
 	  "%s    `MediaPosition' parameter.\n",
 	wpref, eprn->media_position, wpref);
@@ -1145,7 +1143,7 @@
       eprn->pagecount_file = (char *)gs_malloc(gs_lib_ctx_get_non_gc_memory_t(), string_value.size + 1,
 	sizeof(char), "eprn_put_params");
       if (eprn->pagecount_file == NULL) {
-	fprintf(stderr, "%s" ERRPREF
+	eprintf1( "%s" ERRPREF
 	  "Memory allocation failure from gs_malloc() in eprn_put_params().\n",
 	  epref);
 	last_error = gs_error_VMerror;
@@ -1167,7 +1165,7 @@
       eprn->non_black_levels = temp;
     }
     else {
-      fprintf(stderr, "%s" ERRPREF
+      eprintf2("%s" ERRPREF
 	"The value for RGBLevels is outside the range permitted: %d.\n",
 	epref, temp);
       last_error = gs_error_rangecheck;
@@ -1187,7 +1185,7 @@
   */
   if ((rc = param_read_int(plist, (pname = "BitsPerPixel"), &temp)) == 0) {
     if (temp != dev->color_info.depth) {
-      fprintf(stderr, "%s" ERRPREF
+      eprintf3("%s" ERRPREF
 	"Attempt to set `BitsPerPixel' to a value (%d)\n"
 	"%s  other than the one selected by the driver.\n",
 	epref, temp, epref);
