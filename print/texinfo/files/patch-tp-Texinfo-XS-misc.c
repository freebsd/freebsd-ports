% sed -e 's|free (.*)|Safe&|' -i .orig tp/Texinfo/XS/misc.c

--- tp/Texinfo/XS/misc.c.orig	2022-11-30 17:06:28 UTC
+++ tp/Texinfo/XS/misc.c
@@ -67,7 +67,7 @@ xs_abort_empty_line (HV *self, HV *current, SV *additi
       additional_spaces = SvPV (additional_spaces_in, len);
       if (!SvUTF8 (additional_spaces_in))
         {
-          free (new_string);
+          Safefree (new_string);
           new_string = bytes_to_utf8 (additional_spaces, &len);
           additional_spaces = new_string;
         }
@@ -248,7 +248,7 @@ xs_merge_text (HV *self, HV *current, SV *text_in)
     text = SvPV (text_in, len);
     if (!SvUTF8 (text_in))
       {
-        free (new_string);
+        Safefree (new_string);
         new_string = bytes_to_utf8 (text, &len);
         text = new_string;
       }
