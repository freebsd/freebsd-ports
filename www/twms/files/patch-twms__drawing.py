--- twms/drawing.py.orig	2014-10-07 11:57:57 UTC
+++ twms/drawing.py
@@ -13,7 +13,7 @@
 
 #   You should have received a copy of the GNU General Public License
 #   along with tWMS.  If not, see <http://www.gnu.org/licenses/>.
-import Image, ImageDraw
+from PIL import Image, ImageDraw
 import urllib
 import os, sys
 
@@ -79,4 +79,4 @@
        draw.ellipse((coords[0][0]-3,coords[0][1]-3,coords[0][0]+3,coords[0][1]+3),fill=color,outline=color)
     elif geometry == "POLYGON":
        draw.polygon(coords, fill=color, outline=color)
-    return img
\ No newline at end of file
+    return img
