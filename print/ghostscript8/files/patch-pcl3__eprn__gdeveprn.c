--- pcl3/eprn/gdeveprn.c.orig	Mon Apr 30 14:15:51 2001
+++ pcl3/eprn/gdeveprn.c	Sun Mar 25 22:22:54 2007
@@ -142,11 +142,13 @@
     if_debug0(EPRN_TRACE_CHAR,
       "! eprn_get_initial_matrix(): code is still ms_none.\n");
 #endif
+#if 0
     if (eprn_set_page_layout(dev) != 0)
       fputs("  Processing can't be stopped at this point although this error "
 	"occurred.\n", stderr);
       /* The current function has a signature without the ability to signal
 	 an error condition. */
+#endif
   }
 
   quarters = dev->eprn.default_orientation +
@@ -607,6 +609,7 @@
     }
   }
 
+#if 0
   /*  Now the 'best_*match' variables indicate for each of the categories of
       page descriptions to which extent the size is supported at all (non-NULL
       value) and what the best flag match in the category is. Here we now check
@@ -647,6 +650,7 @@
       return -1;
     }
   }
+#endif
   /* Now we have: best_dmatch != NULL || best_cmatch != NULL &&
      (eprn->media_overrides == NULL || best_cdmatch != NULL). */
 
@@ -692,7 +696,9 @@
   }
   /* If we've found a match, 'code' is no longer 'ms_none'. */
   if (eprn->code == ms_none) {
+#if 0
     eprn_flag_mismatch(stderr, eprn, no_match);
+#endif
     return -1;
   }
 
@@ -762,9 +768,11 @@
 
       rc = gdev_prn_open((gx_device *)dev);
       if (rc < 0) {
+#if 0
 	fprintf(stderr, "%s" ERRPREF
 	  "Failure of gdev_prn_open(), code is %d.\n",
 	  epref, rc);
+#endif
 	return rc;
       }
     }
@@ -875,7 +883,7 @@
       &hres, &vres, &eprn->black_levels, &eprn->non_black_levels);
 
   if (eprn->pagecount_file != NULL) {
-    gs_free(eprn->pagecount_file, strlen(eprn->pagecount_file) + 1,
+    gs_free(dev->memory, eprn->pagecount_file, strlen(eprn->pagecount_file) + 1,
       sizeof(char), "eprn_init_device");
     eprn->pagecount_file = NULL;
   }
@@ -944,17 +952,21 @@
       &eprn->black_levels, &eprn->non_black_levels) != 0) {
     gs_param_string str;
 
+#if 0
     fprintf(stderr, "%s" ERRPREF "The requested combination of colour model (",
       epref);
+#endif
     str.size = 0;
     if (eprn_get_string(eprn->colour_model, eprn_colour_model_list, &str) != 0)
       assert(0); /* Bug. No harm on NDEBUG because I've just set the size. */
+#if 0
     fwrite(str.data, str.size, sizeof(str.data[0]), stderr);
     fprintf(stderr, "),\n"
       "%s  resolution (%gx%g ppi) and intensity levels (%d, %d) is\n"
       "%s  not supported by the %s.\n",
       epref, device->HWResolution[0], device->HWResolution[1],
       eprn->black_levels, eprn->non_black_levels, epref, eprn->cap->name);
+#endif
     return_error(gs_error_rangecheck);
   }
 
@@ -1017,11 +1029,13 @@
 	  inappropriate :-). Note that eprn does not use 'PageCount' for
 	  updating the file. */
     else {
+#if 0
       /* pcf_getcount() has issued an error message. */
       fputs(
         "  No further attempts will be made to access the page count file.\n",
 	stderr);
-      gs_free(eprn->pagecount_file, strlen(eprn->pagecount_file) + 1,
+#endif
+      gs_free(device->memory, eprn->pagecount_file, strlen(eprn->pagecount_file) + 1,
 	sizeof(char), "eprn_open_device");
       eprn->pagecount_file = NULL;
     }
@@ -1034,31 +1048,33 @@
   /* Just in case a previous open call failed in a derived device (note that
      'octets_per_line' is still the same as then): */
   if (eprn->scan_line.str != NULL)
-    gs_free(eprn->scan_line.str, eprn->octets_per_line, sizeof(eprn_Octet),
+    gs_free(device->memory, eprn->scan_line.str, eprn->octets_per_line, sizeof(eprn_Octet),
       "eprn_open_device");
   if (eprn->next_scan_line.str != NULL) {
-    gs_free(eprn->next_scan_line.str, eprn->octets_per_line, sizeof(eprn_Octet),
+    gs_free(device->memory, eprn->next_scan_line.str, eprn->octets_per_line, sizeof(eprn_Octet),
       "eprn_open_device");
     eprn->next_scan_line.str = NULL;
   }
 
   /* Calls which might depend on prn having been initialized */
   eprn->octets_per_line = gdev_prn_raster((gx_device_printer *)device);
-  eprn->scan_line.str = (eprn_Octet *) gs_malloc(eprn->octets_per_line,
+  eprn->scan_line.str = (eprn_Octet *) gs_malloc(device->memory, eprn->octets_per_line,
     sizeof(eprn_Octet), "eprn_open_device");
   if (eprn->intensity_rendering == eprn_IR_FloydSteinberg) {
-    eprn->next_scan_line.str = (eprn_Octet *) gs_malloc(eprn->octets_per_line,
+    eprn->next_scan_line.str = (eprn_Octet *) gs_malloc(device->memory, eprn->octets_per_line,
       sizeof(eprn_Octet), "eprn_open_device");
     if (eprn->next_scan_line.str == NULL && eprn->scan_line.str != NULL) {
-      gs_free(eprn->scan_line.str, eprn->octets_per_line, sizeof(eprn_Octet),
+      gs_free(device->memory, eprn->scan_line.str, eprn->octets_per_line, sizeof(eprn_Octet),
 	"eprn_open_device");
       eprn->scan_line.str = NULL;
     }
   }
   if (eprn->scan_line.str == NULL) {
+#if 0
     fprintf(stderr, "%s" ERRPREF
       "Memory allocation failure from gs_malloc() in eprn_open_device().\n",
       epref);
+#endif
     return_error(gs_error_VMerror);
   }
 
@@ -1080,12 +1096,12 @@
 #endif
 
   if (eprn->scan_line.str != NULL) {
-    gs_free(eprn->scan_line.str, eprn->octets_per_line, sizeof(eprn_Octet),
+    gs_free(device->memory, eprn->scan_line.str, eprn->octets_per_line, sizeof(eprn_Octet),
       "eprn_close_device");
     eprn->scan_line.str = NULL;
   }
   if (eprn->next_scan_line.str != NULL) {
-    gs_free(eprn->next_scan_line.str, eprn->octets_per_line, sizeof(eprn_Octet),
+    gs_free(device->memory, eprn->next_scan_line.str, eprn->octets_per_line, sizeof(eprn_Octet),
       "eprn_close_device");
     eprn->next_scan_line.str = NULL;
   }
@@ -1152,20 +1168,24 @@
       accounting, this seems unfair.
   */
   if (rc == 0 && eprn->CUPS_accounting)
+#if 0
     fprintf(stderr, "PAGE: %ld %d\n", dev->ShowpageCount, num_copies);
     /* The arguments are the number of the page, starting at 1, and the number
        of copies of that page. */
+#endif
 
 #ifndef EPRN_NO_PAGECOUNTFILE
   /* On success, record the number of pages printed */
   if (rc == 0 && eprn->pagecount_file != NULL) {
     assert(num_copies > 0);	/* because of signed/unsigned */
     if (pcf_inccount(eprn->pagecount_file, num_copies) != 0) {
+#if 0
       /* pcf_inccount() has issued an error message. */
       fputs(
 	"  No further attempts will be made to access the page count file.\n",
 	stderr);
-      gs_free(eprn->pagecount_file, strlen(eprn->pagecount_file) + 1,
+#endif
+      gs_free(dev->memory, eprn->pagecount_file, strlen(eprn->pagecount_file) + 1,
 	sizeof(char), "eprn_output_page");
       eprn->pagecount_file = NULL;
     }
