--- slrnface.sl.orig	Wed Apr 10 18:34:08 2002
+++ slrnface.sl	Wed Apr 10 18:34:22 2002
@@ -16,7 +16,7 @@
 %  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 
-variable xfacefp;
+variable xfacefp = NULL;
 
 define startup_hook()
 {
