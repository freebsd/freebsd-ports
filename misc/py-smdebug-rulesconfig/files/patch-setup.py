--- setup.py.orig	2020-12-08 17:43:31 UTC
+++ setup.py
@@ -22,7 +22,7 @@ def build_rule_config_package(version):
         description="SMDebug RulesConfig",
         long_description=long_description,
         url="https://github.com/awslabs/sagemaker-debugger-rulesconfig",
-        packages=setuptools.find_packages(),
+        packages=setuptools.find_packages(exclude = ["tests", "tests.*"]),
         package_data={"smdebug_rulesconfig": ["debugger_rules/rule_config_jsons/*.json"]},
         classifiers=[
             "Programming Language :: Python :: 3",
