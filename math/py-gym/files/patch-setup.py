--- setup.py.orig	2020-12-19 00:04:11 UTC
+++ setup.py
@@ -29,7 +29,7 @@ setup(name='gym',
                 if package.startswith('gym')],
       zip_safe=False,
       install_requires=[
-          'scipy', 'numpy>=1.10.4', 'pyglet>=1.4.0,<=1.5.0', 'Pillow<=7.2.0', 'cloudpickle>=1.2.0,<1.7.0',
+          'scipy', 'numpy>=1.10.4', 'pyglet>=1.4.0,<=1.5.0', 'Pillow<=8.2.0', 'cloudpickle>=1.2.0,<1.7.0',
       ],
       extras_require=extras,
       package_data={'gym': [
