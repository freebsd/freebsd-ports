--- ./setup.py.orig	2011-02-04 12:07:09.000000000 -0800
+++ ./setup.py	2011-03-04 04:57:02.000000000 -0800
@@ -40,10 +40,10 @@
 	 # XDG desktop mime types cache
 	 ('share/mime/packages',['xdg/openshot.xml']),
 	 # launcher (mime.types)
-	 ('lib/mime/packages',['xdg/openshot']),
+	 #('lib/mime/packages',['xdg/openshot']),
 	 # man-page ("man 1 openshot")
-	 ('share/man/man1',['docs/openshot.1']),
-	 ('share/man/man1',['docs/openshot-render.1']),
+	 ('man/man1',['docs/openshot.1']),
+	 ('man/man1',['docs/openshot-render.1']),
 ]
 
 # Add all the translations
@@ -70,7 +70,7 @@
 
 FAILED = 'Failed to update.\n'
 
-if ROOT and dist != None:
+if ROOT and sys.argv[1] == "install" and dist != None:
 	#update the XDG Shared MIME-Info database cache
 	try: 
 		sys.stdout.write('Updating the Shared MIME-Info database cache.\n')
@@ -79,11 +79,11 @@
 		sys.stderr.write(FAILED)
 
 	#update the mime.types database
-	try: 
-		sys.stdout.write('Updating the mime.types database\n')
-		subprocess.call("update-mime")
-	except:
-		sys.stderr.write(FAILED)
+	#try: 
+	#	sys.stdout.write('Updating the mime.types database\n')
+	#	subprocess.call("update-mime")
+	#except:
+	#	sys.stderr.write(FAILED)
 
 	# update the XDG .desktop file database
 	try:
