--- ./webapp/graphite/dashboard/urls.py.orig	2013-08-21 17:11:04.000000000 +0000
+++ ./webapp/graphite/dashboard/urls.py	2014-02-13 02:01:59.482110196 +0000
@@ -1,4 +1,4 @@
-from django.conf.urls.defaults import *
+from django.conf.urls import *
 
 urlpatterns = patterns('graphite.dashboard.views',
   ('^save/(?P<name>[^/]+)', 'save'),
