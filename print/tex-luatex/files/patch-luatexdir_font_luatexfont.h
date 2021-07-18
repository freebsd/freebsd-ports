--- luatexdir/font/luatexfont.h.orig	2015-03-20 07:59:58 UTC
+++ luatexdir/font/luatexfont.h
@@ -149,8 +149,6 @@ void replace_packet_fonts(internal_font_number f, int 
                           int *new_fontid, int count);
 int *packet_local_fonts(internal_font_number f, int *num);
 
-int packet_cur_s;               /* current |do_vf_packet()| recursion level */
-int packet_stack_ptr;           /* pointer into |packet_stack| */
 vf_struct *new_vfstruct(void);
 
 /* writecff.c */
