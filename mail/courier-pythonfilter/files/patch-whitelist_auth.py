--- filters/whitelist_auth.py.orig     Sun Dec 26 00:01:02 2004
+++ filters/whitelist_auth.py  Thu Jul 27 07:46:24 2006
@@ -1,5 +1,5 @@
 #!/usr/bin/python
-# whitelist-auth -- Courier filter which exempts authenticated users from filtering
+# whitelist_auth -- Courier filter which exempts authenticated users from filtering
 # Copyright (C) 2004  Gordon Messmer <gordon@dragonsdawn.net>
 #
 # This program is free software; you can redistribute it and/or modify
@@ -28,7 +28,7 @@
 _auth_regex = re.compile(r'\(AUTH: \w* \w*([^)]*)\)\s*by %s' % _hostname)

 # Record in the system log that this filter was initialized.
-sys.stderr.write('Initialized the "whitelist-auth" python filter\n')
+sys.stderr.write('Initialized the "whitelist_auth" python filter\n')


 def checkHeader(header):
@@ -105,6 +105,6 @@
     # is whitelisted, or nothing to indicate that the remaining
     # filters would be run.
     if not sys.argv[1:]:
-        print 'Use:  whitelist-auth.py <control file>'
+        print 'Use:  whitelist_auth.py <control file>'
         sys.exit(1)
     print doFilter(sys.argv[1], [])
