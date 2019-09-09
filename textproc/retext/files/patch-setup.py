--- setup.py.orig	2019-09-09 20:33:15.181197000 +0200
+++ setup.py	2019-09-09 20:37:49.730010000 +0200
@@ -57,7 +57,7 @@
 	def run(self):
 		for ts_file in glob(join('locale', '*.ts')):
 			try:
-				check_call(('lrelease', ts_file), env={'QT_SELECT': '5'})
+				check_call(('lrelease', ts_file), env={'QT_SELECT': 'qt5'})
 			except Exception as e:
 				log.warn('Failed to build translations: %s', e)
 				break
