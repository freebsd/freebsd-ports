*** examples/colors.c.orig	Mon Jul  5 22:42:37 2004
--- examples/colors.c	Mon Jul  5 22:37:05 2004
***************
*** 16,21 ****
--- 16,24 ----
   * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   * Boston, MA 02111-1307, USA.
   */
+ #ifdef    GTK_DISABLE_DEPRECATED
+ #undef    GTK_DISABLE_DEPRECATED
+ #endif /* GTK_DISABLE_DEPRECATED */
  #include <stdio.h>
  #include <gtk/gtk.h>
  #include <gtk/gtkcolorsel.h>
