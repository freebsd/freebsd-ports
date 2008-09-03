--- fastest_sites-20080320.py.orig	2008-09-01 20:34:56.000000000 -0400
+++ fastest_sites-20080320.py	2008-09-02 22:20:46.000000000 -0400
@@ -129,15 +129,29 @@
 var_re = re.compile(r"^(MASTER_SITE_[A-Z_]+)\+?=")
 sites_mk = "%s/Mk/bsd.sites.mk" % (GetVariable("PORTSDIR"))
 sites = {}
+bad_sites = {}
 site_latency = {}
 
+# This catches http://.foo (as is the case with MASTER_SITE_GOOGLE_CODE)
+# and foo.com// (as is the case with MASTER_SITE_DEBIAN_POOL)
+# It also catches http://www..com just in case that pops up in the future
+bad_site_regex = re.compile(r"(\/\/\.|\.\.|[a-zA-Z]\/\/)")
+
 fd = open(sites_mk, "r")
 for line in fd:
   match = var_re.search(line)
   if match:
     varname = match.group(1)
     output = Run("make -V %s -f %s" % (varname, sites_mk))
-    sites[varname] = output.split()
+    # Some sites uses variables in them:
+    # MASTER_SITE_GOOGLE_CODE:  http://${PORTNAME}.googlecode.com/files/
+    # and MASTER_SITE_DEBIAN_POOL
+    # We don't have access to those variables so we skip them.
+    site_is_bad = bad_site_regex.search(output)
+    if site_is_bad:
+      bad_sites[varname] = output.split()
+    else:
+      sites[varname] = output.split()
 
 for (varname, sitelist) in sites.iteritems():
   if len(sys.argv) > 1 and varname not in sys.argv[1:]:
@@ -146,12 +160,22 @@
       " => Checking servers for %s (%d servers)" % (varname, len(sitelist))
   latency_list = FindFastest(varname, sitelist)
 
+  # Don't print the trailing slash on the last line.
   print "%s=\\" % varname
-  for (url, duration) in latency_list:
+  for (url, duration) in latency_list[:-1]:
     print "\t%s \\" % (url)
+  (url, duration) = latency_list[-1]
+  print "\t%s" % url
 
   print
   sys.stdout.flush()
 
   # Let the network quiesce
   #time.sleep(3)
+
+# Walk the dict of sites that we know cause problems.
+# If explicitly asked to sort one of them be verbose about skipping it
+# otherwise be silent.
+for (varname, sitelist) in bad_sites.iteritems():
+  if len(sys.argv) > 1 and varname in sys.argv[1:]:
+    print >>sys.stderr, "Unable to sort %s - skipping." % varname
