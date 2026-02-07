--- luatexdir/font/luatexfont.h.orig	2020-10-04 19:39:39 UTC
+++ luatexdir/font/luatexfont.h
@@ -129,8 +129,6 @@ void glyph_unicode_free(void);
 void replace_packet_fonts(internal_font_number f, int *old_fontid, int *new_fontid, int count);
 int *packet_local_fonts(internal_font_number f, int *num);
 
-extern int packet_cur_s;               /* current |do_vf_packet()| recursion level */
-extern int packet_stack_ptr;           /* pointer into |packet_stack| */
 vf_struct *new_vfstruct(void);
 
 /* writecff.c */
