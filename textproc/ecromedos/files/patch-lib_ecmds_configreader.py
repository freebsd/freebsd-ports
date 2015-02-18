--- lib/ecmds/configreader.py.orig	2012-01-12 21:43:00 UTC
+++ lib/ecmds/configreader.py
@@ -113,9 +113,7 @@ class ECMDSCfgFileReader:
 		try:
 			cfile = os.path.normpath(options['config_file'])
 		except KeyError:
-			syspath = os.path.normpath(sys.path[0])
-			cfile = os.sep.join(["..", "etc", "ecmds.conf"])
-			cfile = os.path.join(syspath, cfile)
+			cfile = "%%ETCDIR%%/ecmds.conf"
 			if not os.path.isfile(cfile):
 				msg = "Please specify the location of the config file."
 				raise ECMDSError(msg)
@@ -189,9 +187,7 @@ class ECMDSPluginsMapReader:
 		try:
 			pmap = os.path.normpath(config['plugins_map'])
 		except KeyError:
-			syspath = os.path.normpath(sys.path[0])
-			pmap = os.sep.join(["..", "etc", "plugins.conf"])
-			pmap = os.path.join(syspath, pmap)
+			pmap = "%%ETCDIR%%/plugins.conf"
 			if not os.path.isfile(pmap):
 				msg = "Warning: plugins map not found."
 				sys.stderr.write(msg + "\n")
