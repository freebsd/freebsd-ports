--- cmds_visual.c.orig	2019-02-22 18:41:46 UTC
+++ cmds_visual.c
@@ -440,7 +440,7 @@ void do_visualmode(struct block * buf) {
             sc_error("Locked cells encountered. Nothing changed");
             return;
         }
-        wchar_t interp_line[BUFFERSIZE];
+        extern wchar_t interp_line[BUFFERSIZE];
         if (buf->value == L'{')      swprintf(interp_line, BUFFERSIZE, L"leftjustify %s", v_name(r->tlrow, r->tlcol));
         else if (buf->value == L'}') swprintf(interp_line, BUFFERSIZE, L"rightjustify %s", v_name(r->tlrow, r->tlcol));
         else if (buf->value == L'|') swprintf(interp_line, BUFFERSIZE, L"center %s", v_name(r->tlrow, r->tlcol));
