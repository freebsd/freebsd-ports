$FreeBSD$
--- gui.cpp	Tue Jun 29 17:16:38 2004
+++ gui.cpp.port	Sat Jul  9 21:25:43 2005
@@ -121,7 +121,7 @@
 		{
 			// utiliser d_chryzode_proc pour tenir  jour la bitmap ??????
 			destroy_bitmap((BITMAP *)main_dialog[MAIN_D_CHRYZODE].dp);
-			(BITMAP *)main_dialog[MAIN_D_CHRYZODE].dp = create_bitmap(SCREEN_W, SCREEN_H);
+			main_dialog[MAIN_D_CHRYZODE].dp = (BITMAP *)create_bitmap(SCREEN_W, SCREEN_H);
 			((Cchryzode *)main_dialog[MAIN_D_CHRYZODE].dp2)->set_bmp((BITMAP *)main_dialog[MAIN_D_CHRYZODE].dp);
 			main_dialog[MAIN_D_CHRYZODE].w = SCREEN_W;
 			main_dialog[MAIN_D_CHRYZODE].h = SCREEN_H;
