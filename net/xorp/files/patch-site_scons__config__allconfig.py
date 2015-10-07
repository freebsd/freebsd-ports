--- site_scons/config/allconfig.py.orig	2012-01-11 17:56:10 UTC
+++ site_scons/config/allconfig.py
@@ -21,6 +21,7 @@ import sys
 import os
 import string
 from SCons.Script.SConscript import SConsEnvironment
+import fnmatch;
 
 # TODO SCons support for headerfilename needs to be fixed at source--
 # that would let us use confdefs.h for the include file header
@@ -226,10 +227,12 @@ def DoAllConfig(env, conf, host_os):
     if has_af_inet and has_sock_raw:
         conf.Define('HAVE_IP_RAW_SOCKETS')
         # TODO:  This needs to be properly detected.
-        # TODO:  This used to check for bsd and linux in an error prone
-        #        way.  Now, do negative checks, but this could break Solaris
+        # <http://www.xorp.org/bugzilla/show_bug.cgi?id=106#c1>:
+        # TODO:  This used to check for openbsd and linux in an error prone
+        #        way.  Now, do negative checks, but this could break Solaris and other OS
         #        (or not..no idea if it supports raw or not).
-	if not (env.has_key('mingw') and env['mingw']):
+        if not ((env.has_key('mingw') and env['mingw']) or
+                   fnmatch.fnmatch(host_os, 'freebsd*')):
             conf.Define('IPV4_RAW_OUTPUT_IS_RAW')
             conf.Define('IPV4_RAW_INPUT_IS_RAW')
     
