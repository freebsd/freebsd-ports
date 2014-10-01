--- makeMakefile.py.orig	2012-07-18 09:17:42.000000000 +0200
+++ makeMakefile.py	2014-02-07 17:28:44.000000000 +0100
@@ -82,7 +82,7 @@
 libs = ''
 
 if sharedLib:
-	compiler = ' '.join( [compiler, '-DOGDF_DLL -DOGDF_INSTALL' ] )
+	compiler = ' '.join( [compiler, '-DOGDF_INSTALL' ] )
 	if sys.platform == 'win32' or sys.platform == 'cygwin':
 		libs = ' '.join( [libs, '-lpsapi'] )
 	else:
@@ -97,17 +97,20 @@
 	# coinLib = loadConfig('COIN', 'coinLib')
 	solver_name = loadConfig('COIN', 'solver_name')
 	solver_incl = loadConfig('COIN', 'solver_incl')
-	# solver_lib = loadConfig('COIN', 'solver_lib')
+	solver_lib = loadConfig('COIN', 'solver_lib')
 	si2 = ' '
 	if solver_incl.strip() != '':
 	  si2 = '-I'+solver_incl
+	if solver_lib.strip() != '':
+	  libs = ' '.join( [libs, solver_lib] )
 	compiler = ' '.join( [ compiler, '-I'+coinIncl, si2, '-D'+solver_name, '-DUSE_COIN', ' ' ] )
 	
 useAbacus = loadConfig('ABACUS', 'useAbacus').startswith('t')
 if useAbacus:
 	abacusDef = loadConfig('ABACUS', 'abacusDef')
 	abacusIncl = loadConfig('ABACUS', 'abacusIncl')
-	# abacusLib = loadConfig('ABACUS', 'abacusLib')
+	abacusLib = loadConfig('ABACUS', 'abacusLib')
+	libs = ' '.join( [libs, abacusLib] )
 	compiler = ' '.join( [ compiler, abacusDef, '-I'+abacusIncl, '-DUSE_ABACUS', ' ' ] )
 	
 versions = []
