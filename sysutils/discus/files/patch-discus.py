--- discus.py.orig	2023-01-21 12:38:18 UTC
+++ discus.py
@@ -350,16 +350,8 @@ def read_mounts(mtab, skip_list):
     """Read the mounts file."""
     mounts = []
 
-    # If the first letter of the mtab file begins with a !, it is a
-    # shell command to be executed, and not a file to be read.  Idea
-    # provided by John Soward.
-    if mtab[0] == "!":
-        mtab = subprocess.getoutput(mtab[1:])
-        mtab = str.split(mtab, "\n")
-    else:
-        fp = open(mtab)
-        mtab = fp.readlines()
-        fp.close()
+    mtab = subprocess.getoutput('/sbin/mount -p')
+    mtab = str.split(mtab, "\n")
 
     # Extract the mounted filesystems from the read file.
     for entry in mtab:
@@ -432,7 +424,7 @@ def main():
     """Define main program."""
     options = parse_options()
     interpret_options(options)
-    mounts = read_mounts(opts["mtab"], opts["skip_list"])
+    mounts = read_mounts(None, opts["skip_list"])
     headers = get_header(opts["graph"])
     stats_factory = StatsFactory(opts["reserved"])
     size_formatter = SizeFormatter(opts["smart"], opts["placing"],
