/*
 *      @(#)vnvars.c	2.1 TriChlor: 92/03/17 06:36:00
 */


#include "vnvars.h"

Boolean		vn_filter_keyboard;
Boolean		vn_filter_screen;
Vk_Fsm		vn_keyboard_id;
Vk_Fsm		vn_screen_id;
u_char		vn_erase_char;	/* character copied from tty characteristics */
unsigned int	vn_erase_character; /* character given by .Xdefaults */
