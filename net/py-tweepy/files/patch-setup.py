--- setup.py.orig	2015-02-21 19:28:08 UTC
+++ setup.py
@@ -15,7 +15,10 @@ else:
     raise RuntimeError("Unable to find version string in %s." % (VERSIONFILE,))
 
 install_reqs = parse_requirements('requirements.txt', session=uuid.uuid1())
+test_reqs = parse_requirements('test_requirements.txt', session=uuid.uuid1())
+
 reqs = [str(req.req) for req in install_reqs]
+treqs = [str(req.req) for req in test_reqs]
 
 setup(name="tweepy",
       version=version,
@@ -26,6 +29,8 @@ setup(name="tweepy",
       url="http://github.com/tweepy/tweepy",
       packages=find_packages(exclude=['tests']),
       install_requires=reqs,
+      tests_require=treqs,
+      test_suite='nose.collector',
       keywords="twitter library",
       classifiers=[
           'Development Status :: 4 - Beta',
