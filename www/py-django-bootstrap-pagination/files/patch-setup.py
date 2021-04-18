Avoid the installation of the test suite in the top-level directory
of ${PYTHON_SITELIBDIR}.

--- setup.py.orig	2019-06-13 21:18:37 UTC
+++ setup.py
@@ -17,7 +17,7 @@ setup(
     keywords="django bootstrap pagination templatetag",
     author=u'Jason McClellan<jason@jasonmcclellan.io>, Koert van der Veer<koert@ondergetekende.nl>',
     author_email='jason@jasonmccllelan.io',
-    packages=find_packages(),
+    packages=find_packages(exclude=['tests']),
     url='https://github.com/jmcclell/django-bootstrap-pagination',
     license='MIT licence, see LICENCE',
     description='Render Django Page objects as Bootstrap 3.x/4.x Pagination compatible HTML',
