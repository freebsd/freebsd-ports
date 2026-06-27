-- Remove pytest-runner from setup_requires as it's not needed for build
-- and the port doesn't exist in FreeBSD ports tree.

--- setup.py.orig	2026-06-27 10:37:52 UTC
+++ setup.py
@@ -77,7 +77,6 @@ setup(
     python_requires=">=3.6",
     tests_require=['pytest', 'scipy', 'pillow', 'matplotlib'],
     test_suite='pytest',
-    setup_requires=['pytest-runner'],
     install_requires=['numpy', 'h5py', 'six', 'enum34;python_version<"3.4"'],
     package_data={'nixio': [license_text, description_text]},
     include_package_data=True,
