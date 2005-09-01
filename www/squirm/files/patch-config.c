--- config.c.org	Tue Aug 30 21:19:29 2005
+++ config.c	Tue Aug 30 21:21:10 2005
@@ -273,7 +273,7 @@
 	    return 0;
 	  }
 
-	  fq_pattern_filename = gen_fq_name(pattern_filename, "etc/");
+	  fq_pattern_filename = gen_fq_name(pattern_filename, "etc/squirm/");
 	  if (fq_pattern_filename == NULL) {
 	    logprint(LOG_ERROR, "couldn't allocate memory in parse_squirm_conf()\n");
 	    dodo_mode = 1;
