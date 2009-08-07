--- ./devede.py.orig	2009-04-30 08:17:34.000000000 -0300
+++ ./devede.py	2009-04-30 08:18:03.000000000 -0300
@@ -19,6 +19,13 @@
 # You should have received a copy of the GNU General Public License
 # along with this program.  If not, see <http://www.gnu.org/licenses/>.
 
+try:
+  import psyco
+  import re
+  psyco.cannotcompile(re.compile)
+  psyco.profile()
+except ImportError:
+  pass
 
 import sys
 import os
