A small bug that surfaced during the creation of this port.  As it happens,
this does not actually affect the port in its final submitted form, but...
a fix is a fix, and it may impact the port later.

-- Johann Visagie <johann@egenetics.com>


--- admin/DistExt.py.orig	Mon Feb 19 21:40:30 2001
+++ admin/DistExt.py	Fri Mar 16 18:29:11 2001
@@ -145,6 +145,7 @@
             package_dir = [self.build_lib] + list(package)
             package_dir = apply(os.path.join, package_dir)
             for po_file in po_list:
+                self.mkpath(package_dir)
                 (out, _) = self.copy_file(po_file, package_dir)
                 self.outfiles.append(out)
                 locale = os.path.split(po_file)[1][:-3]
