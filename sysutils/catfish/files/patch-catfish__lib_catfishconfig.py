--- catfish_lib/catfishconfig.py.orig	2023-08-06 08:56:49 UTC
+++ catfish_lib/catfishconfig.py
@@ -17,6 +17,7 @@ import os
 #   with this program.  If not, see <https://www.gnu.org/licenses/>.
 
 import os
+import sys
 
 __all__ = [
     'project_path_not_found',
@@ -29,7 +30,10 @@ __catfish_data_directory__ = '../data/'
 # files). By default, this is ../data, relative your trunk layout
 __catfish_data_directory__ = '../data/'
 # Location of locate.db file
-__locate_db_paths__ = ('/var/lib/plocate/plocate.db', '/var/lib/mlocate/mlocate.db')
+if sys.platform.startswith('linux'):
+    __locate_db_paths__ = ('/var/lib/plocate/plocate.db', '/var/lib/mlocate/mlocate.db')
+elif 'bsd' in sys.platform or sys.platform.startswith('dragonfly'):
+    __locate_db_paths__ = ('/var/db/locate.database')
 __license__ = 'GPL-2+'
 __version__ = '4.18.0'
 __url__ = 'https://docs.xfce.org/apps/catfish/start'
