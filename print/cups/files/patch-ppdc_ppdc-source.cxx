--- ppdc/ppdc-source.cxx.orig	2020-04-27 18:04:29 UTC
+++ ppdc/ppdc-source.cxx
@@ -1752,7 +1752,7 @@ ppdcSource::get_resolution(ppdcFile *fp)// I - File to
         _cupsLangPrintf(stderr,
                   _("ppdc: Bad resolution name \"%s\" on line %d of "
         "%s."), name, fp->line, fp->filename);
-        break;
+        return (NULL);
 }
 
   // Create the necessary PS commands...
