/*
 *      @(#)vnvars.h	2.1 TriChlor: 92/03/17 06:36:41
 */

#ifndef _VNVARS_H_
#define _VNVARS_H_

#include <sys/types.h>
#include <X11/Intrinsic.h>
#include <vnkeys.h>

extern Boolean	vn_filter_keyboard;
extern Boolean	vn_filter_screen;
extern Vk_Fsm	vn_keyboard_id;
extern Vk_Fsm	vn_screen_id;
extern u_char	vn_erase_char; /* see vnvars.c */
extern unsigned int vn_erase_character; /* see vnvars.c */

#endif /* _VNVARS_H_ */
