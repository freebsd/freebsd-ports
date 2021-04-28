--- discus.py.orig	2020-04-13 07:05:40 UTC
+++ discus.py
@@ -437,16 +437,8 @@ def read_mounts(mtab, skip_list):
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
@@ -534,7 +526,7 @@ def get_layout(headers, reports):
 def main():
     """Define main program."""
     parse_options()
-    mounts = read_mounts(opts["mtab"], opts["skip_list"])
+    mounts = read_mounts(None, opts["skip_list"])
     headers = get_header(opts["graph"])
     stats_factory = StatsFactory(opts["reserved"])
     size_formatter = SizeFormatter(opts["smart"], opts["placing"],
@@ -559,13 +551,13 @@ def main():
 
 if __name__ == "__main__":
     # Before starting, we need to load the configuration files which
-    # contain global objects.  First the global /etc file, then the user's
+    # contain global objects.  First the global /usr/local/etc file, then the user's
     # file, if exists.
     try:
-        exec(compile(open("/etc/discusrc", "rb").read(), "/etc/discusrc",
+        exec(compile(open("/usr/local/etc/discus/discusrc", "rb").read(), "/usr/local/etc/discus/discusrc",
              'exec'))
     except IOError:
-        usage(EX_CONFIG, "/etc/discusrc must exist and be readable.")
+        usage(EX_CONFIG, "/usr/local/etc/discus/discusrc must exist and be readable.")
 
     try:
         exec(compile(open(os.environ['HOME'] + "/.discusrc", "rb").read(),
