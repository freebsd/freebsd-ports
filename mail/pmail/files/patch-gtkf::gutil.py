
$FreeBSD$

--- gtkf/gutil.py	2001/08/03 07:14:48	1.1
+++ gtkf/gutil.py	2001/08/03 07:14:57
@@ -19,7 +19,7 @@
 #  Boston, MA 02111-1307, USA.  
 
 from gtk import *
-import gtk
+import gtk, sys
 import GtkExtra
 try:
   import gnome
