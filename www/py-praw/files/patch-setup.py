# pytest-runner is only needed when testing and should
# be scoped/added only if 'test' arg is passed to setup.py

--- setup.py.orig	2019-05-17 07:48:36 UTC
+++ setup.py
@@ -50,7 +50,6 @@ setup(
     long_description=README,
     package_data={"": ["LICENSE.txt"], PACKAGE_NAME: ["*.ini"]},
     packages=find_packages(exclude=["tests", "tests.*"]),
-    setup_requires=["pytest-runner >=2.1"],
     tests_require=[
         "betamax >=0.8, <0.9",
         "betamax-matchers >=0.3.0, <0.5",
