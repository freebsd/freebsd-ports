commit 101f170fe525d7f9f8d0c9b80a78af2ed1f6f069
Author: Mathieu Arnold <mat@mat.cc>
Date:   2018-06-13 13:02:37 +0200

    Fix patching sysctl.conf on FreeBSD.

    In b3c1be27fb the lines were stripped of their ending \n, but the \n was
    never added back to the lines, so calling writelines generates a broken
    one line file.

--- salt/modules/freebsd_sysctl.py.orig	2018-04-02 16:35:12 UTC
+++ salt/modules/freebsd_sysctl.py
@@ -165,7 +165,7 @@ def persist(name, value, config='/etc/sy
     if not edited:
         nlines.append("{0}\n".format(_formatfor(name, value, config)))
     with salt.utils.files.fopen(config, 'w+') as ofile:
-        nlines = [salt.utils.stringutils.to_str(_l) for _l in nlines]
+        nlines = [salt.utils.stringutils.to_str(_l) + '\n' for _l in nlines]
         ofile.writelines(nlines)
     if config != '/boot/loader.conf':
         assign(name, value)
