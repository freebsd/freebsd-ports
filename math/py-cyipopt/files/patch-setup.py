-- Remove setup_requires so the port builds in Poudriere jails that do not have
-- pip available; all build dependencies are already declared in BUILD_DEPENDS.
--- setup.py.orig	2026-08-04 00:27:26 UTC
+++ setup.py
@@ -202,7 +202,6 @@ if __name__ == "__main__":
               'cyipopt.tests.integration',
               'cyipopt.tests.unit',
           ],
-          setup_requires=SETUP_REQUIRES,
           install_requires=INSTALL_REQUIRES,
           extras_require=EXTRAS_REQUIRES,
           include_package_data=include_package_data,
