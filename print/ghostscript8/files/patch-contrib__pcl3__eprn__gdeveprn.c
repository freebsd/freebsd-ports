--- contrib/pcl3/eprn/gdeveprn.c.orig	Thu Apr 26 01:27:24 2007
+++ contrib/pcl3/eprn/gdeveprn.c	Tue May 15 01:34:15 2007
@@ -95,6 +95,7 @@
 #ifdef EPRN_TRACE
 #include "gdebug.h"
 #endif	/* EPRN_TRACE */
+#include "gxstdio.h"
 
 /* Special headers for this device */
 #ifndef EPRN_NO_PAGECOUNTFILE
@@ -143,8 +144,8 @@
       "! eprn_get_initial_matrix(): code is still ms_none.\n");
 #endif
     if (eprn_set_page_layout(dev) != 0)
-      fputs("  Processing can't be stopped at this point although this error "
-	"occurred.\n", stderr);
+      eprintf("  Processing can't be stopped at this point although this error "
+	"occurred.\n");
       /* The current function has a signature without the ability to signal
 	 an error condition. */
   }
@@ -303,17 +304,17 @@
 
   Function: print_flags
 
-  Print a textual description of 'flags' on 'f'.
+  Print a textual description of 'flags' to the error stream.
 
 ******************************************************************************/
 
-static void print_flags(FILE *f, ms_MediaCode flags, const ms_Flag *user_flags)
+static void print_flags(ms_MediaCode flags, const ms_Flag *user_flags)
 {
   /* Non-standard flags first */
   if (user_flags != NULL) {
     while (user_flags->code != ms_none) {
       if (user_flags->code & flags) {
-	fputs(user_flags->name, f);
+	errprintf(user_flags->name);
 	flags &= ~user_flags->code;
       }
       user_flags++;
@@ -321,17 +322,17 @@
   }
 
   /* Standard substrings */
-  if (flags & MS_SMALL_FLAG) fputs(MS_SMALL_STRING, f);
-  if (flags & MS_BIG_FLAG  ) fputs(MS_BIG_STRING,   f);
-  if (flags & MS_EXTRA_FLAG) fputs(MS_EXTRA_STRING, f);
+  if (flags & MS_SMALL_FLAG) eprintf(MS_SMALL_STRING);
+  if (flags & MS_BIG_FLAG  ) eprintf(MS_BIG_STRING);
+  if (flags & MS_EXTRA_FLAG) eprintf(MS_EXTRA_STRING);
   flags &= ~(MS_SMALL_FLAG | MS_BIG_FLAG | MS_EXTRA_FLAG);
 
   /* Completeness check */
   if (flags & ~MS_TRANSVERSE_FLAG)
-    fprintf(f, "0x%04X", (unsigned int)(flags & ~MS_TRANSVERSE_FLAG));
+    eprintf1("0x%04X", (unsigned int)(flags & ~MS_TRANSVERSE_FLAG));
 
   /* Standard qualifier */
-  if (flags & MS_TRANSVERSE_FLAG) fputs("." MS_TRANSVERSE_STRING, f);
+  if (flags & MS_TRANSVERSE_FLAG) eprintf("." MS_TRANSVERSE_STRING);
 
   return;
 }
@@ -347,37 +348,37 @@
 
   If the derived device has set a flag mismatch error reporting function, the
   call will be passed to that function. Otherwise a general error message is
-  written on 'err'.
+  written through the graphics library's eprintf().
 
 ******************************************************************************/
 
-static void eprn_flag_mismatch(FILE *err, const struct s_eprn_Device *eprn,
+static void eprn_flag_mismatch(const struct s_eprn_Device *eprn,
   bool no_match)
 {
-  if (eprn->fmr != NULL) (*eprn->fmr)(err, eprn, no_match);
+  if (eprn->fmr != NULL) (*eprn->fmr)(eprn, no_match);
   else {
     const char *epref = eprn->CUPS_messages? CUPS_ERRPREF: "";
 
-    fprintf(err, "%s" ERRPREF "The %s does not support ",
+    eprintf2("%s" ERRPREF "The %s does not support ",
       epref, eprn->cap->name);
-    if (eprn->desired_flags == 0) fprintf(err, "an empty set of media flags");
+    if (eprn->desired_flags == 0) eprintf("an empty set of media flags");
     else {
-      fputs("the \"", err);
-      print_flags(err, eprn->desired_flags, eprn->flag_desc);
-      fputs("\" flag(s)", err);
+      eprintf("the \"");
+      print_flags(eprn->desired_flags, eprn->flag_desc);
+      eprintf("\" flag(s)");
     }
-    fprintf(err, "\n%s  (ignoring presence or absence of \"", epref);
+    eprintf1("\n%s  (ignoring presence or absence of \"", epref);
     {
       ms_MediaCode optional = MS_TRANSVERSE_FLAG;
       if (eprn->optional_flags != NULL) {
 	const ms_MediaCode *of = eprn->optional_flags;
 	while (*of != ms_none) optional |= *of++;
       }
-      print_flags(err, optional, eprn->flag_desc);
+      print_flags(optional, eprn->flag_desc);
     }
-    fputs("\") for ", err);
-    if (no_match) fputs("any", err); else fputs("this", err);
-    fputs(" page size.\n", err);
+    eprintf("\") for ");
+    if (no_match) eprintf("any"); else eprintf("this");
+    eprintf(" page size.\n");
   }
 
   return;
@@ -483,7 +484,7 @@
   the media flags, or the page descriptions have been changed.
 
   The function returns zero on success and a non-zero value otherwise.
-  In the latter case, an error message has been issued on stderr. This can only
+  In the latter case, an error message has been issued. This can only
   occur if the media size is not supported with the flags requested.
 
   On success, the following variables in the device structure are consistent:
@@ -615,21 +616,21 @@
     /* No discrete match */
     if (best_cmatch == NULL) {
       /* No match at all. */
-      fprintf(stderr, "%s" ERRPREF
+      eprintf3("%s" ERRPREF
 	"This document requests a page size of %.0f x %.0f bp.\n",
 	   epref, dev->MediaSize[0], dev->MediaSize[1]);
       if (eprn->cap->custom == NULL) {
 	/* The printer does not support custom page sizes */
 	if (eprn->media_overrides != NULL)
-	  fprintf(stderr,
+	  eprintf1(
 	    "%s  The media configuration file does not contain an entry for "
 	      " this size.\n", epref);
 	else
-	  fprintf(stderr, "%s  This size is not supported by the %s.\n",
+	  eprintf2("%s  This size is not supported by the %s.\n",
 	    epref, eprn->cap->name);
       }
       else
-	fprintf(stderr,
+	eprintf3(
 	  "%s  This size is not supported as a discrete size and it exceeds "
 	    "the\n"
 	  "%s  custom page size limits for the %s.\n",
@@ -637,7 +638,7 @@
       return -1;
     }
     if (eprn->media_overrides != NULL && best_cdmatch == NULL) {
-      fprintf(stderr, "%s" ERRPREF
+      eprintf6("%s" ERRPREF
 	"This document requests a page size of %.0f x %.0f bp\n"
 	"%s  but there is no entry for this size in the "
 	  "media configuration file\n"
@@ -692,7 +693,7 @@
   }
   /* If we've found a match, 'code' is no longer 'ms_none'. */
   if (eprn->code == ms_none) {
-    eprn_flag_mismatch(stderr, eprn, no_match);
+    eprn_flag_mismatch(eprn, no_match);
     return -1;
   }
 
@@ -762,7 +763,7 @@
 
       rc = gdev_prn_open((gx_device *)dev);
       if (rc < 0) {
-	fprintf(stderr, "%s" ERRPREF
+	eprintf2("%s" ERRPREF
 	  "Failure of gdev_prn_open(), code is %d.\n",
 	  epref, rc);
 	return rc;
@@ -944,13 +945,13 @@
       &eprn->black_levels, &eprn->non_black_levels) != 0) {
     gs_param_string str;
 
-    fprintf(stderr, "%s" ERRPREF "The requested combination of colour model (",
+    eprintf1("%s" ERRPREF "The requested combination of colour model (",
       epref);
     str.size = 0;
     if (eprn_get_string(eprn->colour_model, eprn_colour_model_list, &str) != 0)
       assert(0); /* Bug. No harm on NDEBUG because I've just set the size. */
-    fwrite(str.data, str.size, sizeof(str.data[0]), stderr);
-    fprintf(stderr, "),\n"
+    errwrite(str.data, str.size * sizeof(str.data[0]));
+    eprintf7("),\n"
       "%s  resolution (%gx%g ppi) and intensity levels (%d, %d) is\n"
       "%s  not supported by the %s.\n",
       epref, device->HWResolution[0], device->HWResolution[1],
@@ -1022,9 +1023,8 @@
 	  updating the file. */
     else {
       /* pcf_getcount() has issued an error message. */
-      fputs(
-        "  No further attempts will be made to access the page count file.\n",
-	stderr);
+      eprintf(
+        "  No further attempts will be made to access the page count file.\n");
       gs_free(gs_lib_ctx_get_non_gc_memory_t(), eprn->pagecount_file, strlen(eprn->pagecount_file) + 1,
 	sizeof(char), "eprn_open_device");
       eprn->pagecount_file = NULL;
@@ -1060,7 +1060,7 @@
     }
   }
   if (eprn->scan_line.str == NULL) {
-    fprintf(stderr, "%s" ERRPREF
+    eprintf1("%s" ERRPREF
       "Memory allocation failure from gs_malloc() in eprn_open_device().\n",
       epref);
     return_error(gs_error_VMerror);
@@ -1156,7 +1156,7 @@
       accounting, this seems unfair.
   */
   if (rc == 0 && eprn->CUPS_accounting)
-    fprintf(stderr, "PAGE: %ld %d\n", dev->ShowpageCount, num_copies);
+    eprintf2("PAGE: %ld %d\n", dev->ShowpageCount, num_copies);
     /* The arguments are the number of the page, starting at 1, and the number
        of copies of that page. */
 
@@ -1166,9 +1166,8 @@
     assert(num_copies > 0);	/* because of signed/unsigned */
     if (pcf_inccount(eprn->pagecount_file, num_copies) != 0) {
       /* pcf_inccount() has issued an error message. */
-      fputs(
-	"  No further attempts will be made to access the page count file.\n",
-	stderr);
+      eprintf(
+	"  No further attempts will be made to access the page count file.\n");
       gs_free(gs_lib_ctx_get_non_gc_memory_t(), eprn->pagecount_file, strlen(eprn->pagecount_file) + 1,
 	sizeof(char), "eprn_output_page");
       eprn->pagecount_file = NULL;
