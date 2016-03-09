--- makeMakefile.py.orig	2015-05-29 15:36:39 UTC
+++ makeMakefile.py
@@ -154,7 +154,7 @@ if useCoin:
 	if sharedLib and (sys.platform == 'win32' or sys.platform == 'cygwin'):
 		libs += ' -l' + v.coinSharedName()
 
-ogdfFlags = '-I./include ' + addIncludes
+ogdfFlags = '-I./include %%STDCPP11%% ' + addIncludes
 coinFlags = '$(COIN_INSTALL_DEFINES) -I./include/coin ' + addIncludes
 
 if sharedLib:
@@ -458,8 +458,8 @@ if installPrefix:
 	if useCoin:
 		InstallHeaders('include/coin', makefile, installPrefix)
 	makefile.write('\ninstall-pkgconfig: ogdf.pc\n')
-	makefile.write('\tinstall -d $(DESTDIR)' + installPrefix + '/lib/pkgconfig\n')
-	makefile.write('\tinstall -m 0644 ogdf.pc $(DESTDIR)' + installPrefix + '/lib/pkgconfig\n')
+	makefile.write('\tinstall -d $(DESTDIR)' + installPrefix + '/libdata/pkgconfig\n')
+	makefile.write('\tinstall -m 0644 ogdf.pc $(DESTDIR)' + installPrefix + '/libdata/pkgconfig\n')
 
 makefile.write('\ndistclean: clean-doc')
 for v in versions:
