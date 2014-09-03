--- src/pcre/pcretest.c.orig	2012-02-14 12:36:59.560983755 +0100
+++ src/pcre/pcretest.c	2012-02-14 12:45:15.056415687 +0100
@@ -748,24 +748,6 @@
       new_info(re, NULL, PCRE_INFO_NAMECOUNT, &namecount);
       new_info(re, NULL, PCRE_INFO_NAMETABLE, (void *)&nametable);
 
-      old_count = pcre_info(re, &old_options, &old_first_char);
-      if (count < 0) fprintf(outfile,
-        "Error %d from pcre_info()\n", count);
-      else
-        {
-        if (old_count != count) fprintf(outfile,
-          "Count disagreement: pcre_fullinfo=%d pcre_info=%d\n", count,
-            old_count);
-
-        if (old_first_char != first_char) fprintf(outfile,
-          "First char disagreement: pcre_fullinfo=%d pcre_info=%d\n",
-            first_char, old_first_char);
-
-        if (old_options != (int)get_options) fprintf(outfile,
-          "Options disagreement: pcre_fullinfo=%ld pcre_info=%d\n",
-            get_options, old_options);
-        }
-
       if (size != gotten_store) fprintf(outfile,
         "Size disagreement: pcre_fullinfo=%d call to malloc for %d\n",
         size, gotten_store);
