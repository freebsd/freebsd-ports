--- src/sg_wr_mode.c.orig	2023-06-24 02:05:48 UTC
+++ src/sg_wr_mode.c
@@ -374,17 +374,23 @@ main(int argc, char * argv[])
         }
     }
     if (cfile_arg || contents_arg) {
+        const char * inp = (cfile_arg ? cfile_arg : contents_arg);
+
         if (cfile_arg && contents_arg) {
             pr2serr("Cannot have both --contents= and --cfile= options\n");
             return SG_LIB_SYNTAX_ERROR;
         }
         memset(read_in, 0, read_in_sz);
-        if ((ret = build_mode_page(optarg, !! cfile_arg, do_raw, read_in,
-                                   &read_in_len, read_in_sz))) {
+        if ((ret = build_mode_page(inp, !! cfile_arg, do_raw,
+                                   read_in, &read_in_len, read_in_sz))) {
             pr2serr("bad argument to '%s'\n", cfile_arg ? "--cfile=" :
                                                           "--contents=");
             return ret;
         }
+        if (verbose > 5) {
+	    pr2serr("Decoded contents:\n");
+            hex2stderr(read_in, read_in_len, 1);
+	}
         got_contents = true;
     }
 
