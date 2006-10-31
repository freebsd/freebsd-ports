--- lib/matplotlib/toolkits/basemap/basemap.py.orig     Wed Oct 11 12:46:53 2006
+++ lib/matplotlib/toolkits/basemap/basemap.py  Wed Oct 11 12:47:16 2006
@@ -22,7 +22,7 @@
 # BASEMAP_DATA_PATH env var not set.
 _datadir = os.environ.get('BASEMAP_DATA_PATH')
 if not _datadir:
-   _datadir = os.path.join(sys.prefix,'share','basemap')
+   _datadir = os.path.join(sys.prefix,'share','py-basemap-data')

 __version__ = '0.9.2'
 __revision__ = '20060831'
