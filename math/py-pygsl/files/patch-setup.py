--- setup.py.orig	2021-12-07 16:05:38 UTC
+++ setup.py
@@ -89,8 +89,6 @@ del versiontext
 gsldist_path = os.path.join(pygsldir, "gsl_dist")
 sys.path.insert(0, gsldist_path)
 
-from wheel.bdist_wheel import bdist_wheel as _bdist_wheel
-
 import setuptools
 import setuptools.command
 import setuptools.command.install
@@ -173,26 +171,6 @@ else:
     del t_file
 
 
-class CustomInstallCommand(setuptools.command.install.install):
-    def run(self):
-        # first re-generate GSL wrappers using SWIG
-        self.run_command('gsl_wrappers')
-        # then configure
-        self.run_command('config')
-        # then install
-        setuptools.command.install.install.run(self)
-        #super().run()
-
-class CustomBdistWheelCommand(_bdist_wheel):
-    def run(self):
-        # first re-generate GSL wrappers using SWIG
-        self.run_command('gsl_wrappers')
-        # then configure
-        self.run_command('config')
-        # then install
-        _bdist_wheel.run(self)
-        #super().run()
-
 py_module_names = ['errors',
                    'statistics.__init__',
 		   '_numobj',
@@ -270,10 +248,9 @@ setup (name = proj_name,
        ext_package = 'pygsl',
        ext_modules = exts,
        headers = headers,
-       cmdclass = {'bdist_wheel': CustomBdistWheelCommand,
+       cmdclass = {
                    'config' : gsl_Config_Path,
                    'gsl_wrappers': gsl_CodeGenerator.gsl_CodeGenerator,
-                   'install': CustomInstallCommand,
                    #'build_sphinx': BuildDoc
                    },
        install_requires = ['numpy'],
