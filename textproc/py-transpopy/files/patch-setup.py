--- setup.py.orig	2022-09-17 02:34:34 UTC
+++ setup.py
@@ -7,7 +7,6 @@ setup(name='transpopy',
       install_requires=['google-cloud-translate'],
       packages=['transpopy'],
       package_data={'transpopy': ['transpopy/*']},
-      data_files=[('LICENSE')],
       entry_points={'console_scripts': ['transpopy=transpopy.__main__:main']},
       description='A simple script to translate po files.',
       long_description=("Read a po file and translate the msgids with the "
