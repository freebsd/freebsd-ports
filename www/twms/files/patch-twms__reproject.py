--- twms/reproject.py.orig	2014-10-07 11:58:11 UTC
+++ twms/reproject.py
@@ -14,7 +14,7 @@
 #   You should have received a copy of the GNU General Public License
 #   along with tWMS.  If not, see <http://www.gnu.org/licenses/>.
 
-import Image
+from PIL import Image
 import projections
 import sys
 
