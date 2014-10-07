--- twms/filter.py.orig	2014-10-07 11:57:53 UTC
+++ twms/filter.py
@@ -15,8 +15,8 @@
 #   along with tWMS.  If not, see <http://www.gnu.org/licenses/>.
 
 
-import ImageFilter
-import ImageEnhance
+from PIL import ImageFilter
+from PIL import ImageEnhance
 
 def raster(result_img, filt):
     """
