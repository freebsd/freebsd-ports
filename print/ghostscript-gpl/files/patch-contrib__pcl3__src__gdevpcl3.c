--- contrib/pcl3/src/gdevpcl3.c.orig	Thu Apr 26 01:27:24 2007
+++ contrib/pcl3/src/gdevpcl3.c	Tue May 15 01:48:00 2007
@@ -338,7 +338,7 @@
   /* First we construct a properly NUL-terminated string */
   s = (char *) malloc(in_value->size + 1);
   if (s == NULL) {
-    fprintf(stderr, ERRPREF
+    eprintf1(ERRPREF
       "Memory allocation failure in get_int_for_string(): %s.\n",
       strerror(errno));
     return_error(gs_error_VMerror);
@@ -434,25 +434,25 @@
   const char *epref = eprn->CUPS_messages? CUPS_ERRPREF: "";
 
   if (eprn->desired_flags == 0) {
-    fprintf(stderr,
+    eprintf2(
       "%s" ERRPREF "The %s does not support the requested media properties.\n",
       epref, eprn->cap->name);
   }
   else if (eprn->desired_flags == MS_BIG_FLAG) {
-    fprintf(stderr, "%s" ERRPREF "The %s does not support banner printing",
+    eprintf2("%s" ERRPREF "The %s does not support banner printing",
       epref, eprn->cap->name);
-    if (!no_match) fputs(" for this size", stderr);
-    fputs(".\n", stderr);
+    if (!no_match) eprintf(" for this size");
+    eprintf(".\n");
   }
   else if (eprn->desired_flags == PCL_CARD_FLAG) {
-    fprintf(stderr, "%s" ERRPREF
+    eprintf2("%s" ERRPREF
       "The %s does not support a `Card' variant for ",
       epref, eprn->cap->name);
-    if (no_match) fputs("any", stderr); else fputs("this", stderr);
-    fputs(" size.\n", stderr);
+    if (no_match) eprintf("any"); else eprintf("this");
+    eprintf(" size.\n");
   }
   else {
-    fprintf(stderr,
+    eprintf1(
       "%s" ERRPREF "Banner printing on postcards?? You must be joking!\n",
       epref);
   }
@@ -699,8 +699,8 @@
   be copied to '*s'.
 
   The function returns a negative ghostscript error code on error and zero
-  otherwise. In the former case an error message will have been issued on
-  stderr, using 'epref' as a prefix for the message.
+  otherwise. In the former case an error message will have been issued, 
+  using 'epref' as a prefix for the message.
 
 ******************************************************************************/
 
@@ -728,7 +728,7 @@
 
     if (s->str == NULL) {
       s->length = 0;
-      fprintf(stderr, "%s" ERRPREF
+      eprintf1("%s" ERRPREF
 	"Memory allocation failure from gs_malloc().\n", epref);
       rc = gs_error_VMerror;
       param_signal_error(plist, pname, rc);
@@ -760,8 +760,7 @@
   copied.
 
   The function returns a negative ghostscript error code on error and zero
-  otherwise. In the former case an error message will have been issued on
-  stderr.
+  otherwise. In the former case an error message will have been issued.
 
 ******************************************************************************/
 
@@ -785,7 +784,7 @@
       "fetch_cstring");
 
     if (*s == NULL) {
-      fprintf(stderr, "%s" ERRPREF
+      eprintf1("%s" ERRPREF
 	"Memory allocation failure from gs_malloc().\n", epref);
       rc = gs_error_VMerror;
       param_signal_error(plist, pname, rc);
@@ -907,9 +906,9 @@
 	eprn_init_device((eprn_Device *)dev, &pcl3_printers[dev->printer].desc);
       }
       else {
-	fprintf(stderr, "%s" ERRPREF "Unknown subdevice name: `", epref);
-	fwrite(string_value.data, sizeof(char), string_value.size, stderr);
-	fputs("'.\n", stderr);
+	eprintf1("%s" ERRPREF "Unknown subdevice name: `", epref);
+	errwrite(string_value.data, sizeof(char)*string_value.size);
+	eprintf("'.\n");
 	last_error = gs_error_rangecheck;
 	param_signal_error(plist, pname, last_error);
       }
@@ -925,8 +924,8 @@
       == 0) {
     if (temp != pcl_cm_none && temp != pcl_cm_rl && temp != pcl_cm_tiff &&
 	temp != pcl_cm_delta && temp != pcl_cm_crdr) {
-      fprintf(stderr,
-	"%s" ERRPREF "Unsupported compression method: %d.\n", epref, temp);
+      eprintf2("%s" ERRPREF "Unsupported compression method: %d.\n",
+	epref, temp);
       last_error = gs_error_rangecheck;
       param_signal_error(plist, pname, last_error);
     }
@@ -934,7 +933,7 @@
       if (temp == pcl_cm_crdr && (dev->printer == HPDeskJet ||
 	  dev->printer == HPDeskJetPlus || dev->printer == HPDJ500)) {
 	/* This I know to be the case for the DJ 500. The others are guessed. */
-	fprintf(stderr,
+	eprintf2(
 	  "%s" ERRPREF "The %s does not support compression method 9.\n",
 	  epref, dev->eprn.cap->name);
 	last_error = gs_error_rangecheck;
@@ -956,7 +955,7 @@
     if (1 <= temp && temp <= 5 && (dev->printer != HPDJ500C || temp <= 3))
       requested.depletion = temp;
     else {
-      fprintf(stderr, "%s" ERRPREF "Invalid value for depletion: %d.\n",
+      eprintf2("%s" ERRPREF "Invalid value for depletion: %d.\n",
 	epref, temp);
       last_error = gs_error_rangecheck;
       param_signal_error(plist, pname, last_error);
@@ -978,7 +977,7 @@
 	    Hence I'm giving an error message only in those cases where HP
 	    explicitly states that the printer does not support the command.
 	  */
-	fprintf(stderr,
+	eprintf2(
 	  "%s" ERRPREF "The %s does not support setting a dry time.\n",
 	  epref, dev->eprn.cap->name);
 	last_error = gs_error_rangecheck;
@@ -987,8 +986,8 @@
       else data->dry_time = temp;
     }
     else {
-      fprintf(stderr,
-	"%s" ERRPREF "Invalid value for the dry time: %d.\n", epref, temp);
+      eprintf2("%s" ERRPREF "Invalid value for the dry time: %d.\n",
+	epref, temp);
       last_error = gs_error_rangecheck;
       param_signal_error(plist, pname, last_error);
     }
@@ -1008,7 +1007,7 @@
 	    dev->Duplex_set = 0;	/* force to "null" */
 	}
 	else {
-	  fprintf(stderr, "%s" ERRPREF
+	  eprintf2("%s" ERRPREF
 	    "You can use a non-trivial value for DuplexCapability\n"
 	    "%s  only for unspec and unspecold.\n", epref, epref);
 	  last_error = gs_error_rangecheck;
@@ -1016,9 +1015,9 @@
 	}
       }
       else {
-	fprintf(stderr, "%s" ERRPREF "Invalid duplex capability: `", epref);
-	fwrite(string_value.data, sizeof(char), string_value.size, stderr);
-	fputs("'.\n", stderr);
+	eprintf1("%s" ERRPREF "Invalid duplex capability: `", epref);
+	errwrite(string_value.data, sizeof(char)*string_value.size);
+	eprintf("'.\n");
 	last_error = gs_error_rangecheck;
 	param_signal_error(plist, pname, last_error);
       }
@@ -1037,12 +1036,12 @@
     if ((rc = param_read_bool(plist, (pname = "Duplex"), &temp)) == 0 &&
 	temp && dev->duplex_capability == Duplex_none) {
       if (dev->printer == pcl3_generic_new || dev->printer == pcl3_generic_old)
-	fprintf(stderr, "%s" ERRPREF
+	eprintf3("%s" ERRPREF
           "The '%s' device does not support duplex printing unless\n"
 	  "%s  'DuplexCapability' is not 'none'.\n",
 	  epref, find_subdevice_name(dev->printer), epref);
       else
-	fprintf(stderr, "%s" ERRPREF
+	eprintf2("%s" ERRPREF
 	  "The %s does not support duplex printing.\n",
 	  epref, dev->eprn.cap->name);
       last_error = gs_error_rangecheck;
@@ -1071,9 +1070,9 @@
     rc = get_int_for_string(&string_value, media_type_list, &temp);
     if (rc != 0) {
       if (rc != gs_error_VMerror) {
-	fprintf(stderr, "%s" ERRPREF "Unknown medium: `", epref);
-	fwrite(string_value.data, sizeof(char), string_value.size, stderr);
-	fputs("'.\n", stderr);
+	eprintf1("%s" ERRPREF "Unknown medium: `", epref);
+	errwrite(string_value.data, sizeof(char)*string_value.size);
+	eprintf("'.\n");
       }
       last_error = rc;
       param_signal_error(plist, pname, last_error);
@@ -1081,7 +1080,7 @@
     else {
       new_quality = true;
       if (temp < 0 || 6 < temp)
-	fprintf(stderr, "%s" WARNPREF "Unknown media type code: %d.\n",
+	eprintf2("%s" WARNPREF "Unknown media type code: %d.\n",
 	  wpref, temp);
       pcl3_set_mediatype(data, temp);
     }
@@ -1107,7 +1106,7 @@
       if (pcl_has_CRD(data->level))
 	data->level = (temp? pcl_level_3plus_CRD_only: pcl_level_3plus_S68);
       else if (temp == true) {
-	fprintf(stderr, "%s" ERRPREF
+	eprintf1("%s" ERRPREF
 	  "OnlyCRD may be set only for group-3 devices.\n", epref);
 	last_error = gs_error_rangecheck;
 	param_signal_error(plist, pname, last_error);
@@ -1140,9 +1139,9 @@
     rc = get_int_for_string(&string_value, print_quality_list, &temp);
     if (rc != 0) {
       if (rc != gs_error_VMerror) {
-	fprintf(stderr, "%s" ERRPREF "Unknown print quality: `", epref);
-	fwrite(string_value.data, sizeof(char), string_value.size, stderr);
-	fputs("'.\n", stderr);
+	eprintf1("%s" ERRPREF "Unknown print quality: `", epref);
+	errwrite(string_value.data, sizeof(char)*string_value.size);
+	eprintf("'.\n");
       }
       last_error = rc;
       param_signal_error(plist, pname, last_error);
@@ -1150,7 +1149,7 @@
     else {
       new_quality = true;
       if (temp < -1 || 1 < temp)
-	fprintf(stderr, "%s" WARNPREF "Unknown print quality: %d.\n",
+	eprintf2("%s" WARNPREF "Unknown print quality: %d.\n",
 	  wpref, temp);
       pcl3_set_printquality(data, temp);
     }
@@ -1165,7 +1164,7 @@
 	== 0) {
     if (0 <= temp && temp <= 2) requested.quality = temp;
     else {
-      fprintf(stderr,
+      eprintf2(
 	"%s" ERRPREF "Invalid value for raster graphics quality: %d.\n",
 	epref, temp);
       last_error = gs_error_rangecheck;
@@ -1186,7 +1185,7 @@
   if ((rc = param_read_int(plist, (pname = "SendNULs"), &temp)) == 0) {
     if (data->NULs_to_send >= 0) data->NULs_to_send = temp;
     else {
-      fprintf(stderr,
+      eprintf2(
 	"%s" ERRPREF "Invalid value for SendNULs parameter: %d.\n",
 	epref, temp);
       last_error = gs_error_rangecheck;
@@ -1202,7 +1201,7 @@
       (rc = param_read_int(plist, pname, &temp)) == 0) {
     if (0 <= temp && temp <= 2) requested.shingling = temp;
     else {
-      fprintf(stderr, "%s" ERRPREF "Invalid value for shingling: %d.\n",
+      eprintf2("%s" ERRPREF "Invalid value for shingling: %d.\n",
 	epref, temp);
       last_error = gs_error_rangecheck;
       param_signal_error(plist, pname, last_error);
@@ -1280,7 +1279,7 @@
   /* Check on rendering parameters */
   if ((dev->eprn.black_levels > 2 || dev->eprn.non_black_levels > 2) &&
       dev->file_data.print_quality == -1)
-    fprintf(stderr,
+    eprintf2(
       "%s" WARNPREF "More than 2 intensity levels and draft quality\n"
       "%s    are unlikely to work in combination.\n", wpref, wpref);
 
@@ -1311,18 +1310,18 @@
       */
       char buffer[50];
 
-      fprintf(stderr, "%s" ERRPREF
+      eprintf2("%s" ERRPREF
 	"The current configuration for this driver has identified the\n"
 	"%s  page setup requested by the document as being for `",
 	epref, epref);
       if (ms_find_name_from_code(buffer, sizeof(buffer),
-	  dev->eprn.code, flag_description) == 0) fputs(buffer, stderr);
-      else fputs("UNKNOWN", stderr);	/* should never happen */
-      fprintf(stderr, "' (%.0f x %.0f bp).\n"
+	  dev->eprn.code, flag_description) == 0) eprintf(buffer);
+      else eprintf("UNKNOWN");	/* should never happen */
+      eprintf3("' (%.0f x %.0f bp).\n"
 	"%s  The driver does not know how to do this in PCL.\n",
 	dev->MediaSize[0], dev->MediaSize[1], epref);
       if (dev->eprn.media_file != NULL)
-	fprintf(stderr,
+	eprintf2(
 	  "%s  You should therefore not include such an entry in the\n"
 	  "%s  media configuration file.\n", epref, epref);
       return_error(gs_error_rangecheck);
@@ -1473,7 +1472,7 @@
       pcl_cm_is_differential(dev->file_data.compression) &&
 	rd.previous == NULL) {
     free(lengths); free(rd.next); free(rd.previous);
-    fprintf(stderr, "%s" ERRPREF "Memory allocation failure from malloc().\n",
+    eprintf1("%s" ERRPREF "Memory allocation failure from malloc().\n",
       epref);
     return_error(gs_error_VMerror);
   }
@@ -1514,7 +1513,7 @@
     free(lengths); free(rd.next); free(rd.previous);
     for (j = 0; j < 2; j++) free(rd.workspace[j]);
 
-    fprintf(stderr, "%s" ERRPREF "Memory allocation failure from malloc().\n",
+    eprintf1("%s" ERRPREF "Memory allocation failure from malloc().\n",
       epref);
     return_error(gs_error_VMerror);
   }
