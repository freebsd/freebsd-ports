--- tp/Texinfo/MiscXS/misc.c.orig	2017-05-02 17:05:43 UTC
+++ tp/Texinfo/MiscXS/misc.c
@@ -67,7 +67,7 @@ xs_abort_empty_line (HV *self, HV *curre
       additional_text = SvPV (additional_text_in, len);
       if (!SvUTF8 (additional_text_in))
         {
-          free (new_string);
+          Safefree (new_string);
           new_string = bytes_to_utf8 (additional_text, &len);
           additional_text = new_string;
         }
@@ -279,7 +279,7 @@ xs_merge_text (HV *self, HV *current, SV
     text = SvPV (text_in, len);
     if (!SvUTF8 (text_in))
       {
-        free (new_string);
+        Safefree (new_string);
         new_string = bytes_to_utf8 (text, &len);
         text = new_string;
       }
