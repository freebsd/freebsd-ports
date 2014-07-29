$FreeBSD$

*** 2.4.5/room/south/sforst19.c	Sun Nov 11 21:45:36 1990
--- 2.4.5/room/south/sforst19.c	Mon Sep 12 21:57:54 1994
***************
*** 37,43 ****
  
  east()
  {
!     call_other(this_palyer(), "move_player", "east#room/south/sforst16");
      return 1;
  }
  
--- 37,43 ----
  
  east()
  {
!     call_other(this_player(), "move_player", "east#room/south/sforst16");
      return 1;
  }
  
