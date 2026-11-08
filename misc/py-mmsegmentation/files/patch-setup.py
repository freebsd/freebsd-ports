--- setup.py.orig	2026-09-13 00:44:05 UTC
+++ setup.py
@@ -176,7 +176,7 @@ if __name__ == '__main__':
         author_email='openmmlab@gmail.com',
         keywords='computer vision, semantic segmentation',
         url='https://github.com/open-mmlab/mmsegmentation',
-        packages=find_packages(exclude=('configs', 'tools', 'demo')),
+        packages=find_packages(exclude=('configs', 'tools', 'demo', 'tests', 'tests.*')),
         include_package_data=True,
         classifiers=[
             'Development Status :: 4 - Beta',
