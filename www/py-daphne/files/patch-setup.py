--- setup.py.orig	2022-10-07 10:10:21 UTC
+++ setup.py
@@ -24,7 +24,6 @@ setup(
     include_package_data=True,
     install_requires=["twisted[tls]>=22.4", "autobahn>=22.4.2", "asgiref>=3.5.2,<4"],
     python_requires=">=3.7",
-    setup_requires=["pytest-runner"],
     extras_require={"tests": ["hypothesis", "pytest", "pytest-asyncio", "django"]},
     entry_points={
         "console_scripts": ["daphne = daphne.cli:CommandLineInterface.entrypoint"]
