--- DenyHosts/regex.py.orig	Sat Jun 23 14:32:34 2007
+++ DenyHosts/regex.py	Sat Jun 23 14:32:58 2007
@@ -17,7 +17,7 @@
 
 FAILED_ENTRY_REGEX4 = re.compile(r"""Authentication failure for (?P<user>.*) .*from (?P<host>.*)""")
 
-FAILED_ENTRY_REGEX5 = re.compile(r"""User (?P<user>.*) .*from (?P<host>.*) not allowed because none of user's groups are listed in AllowGroups""")
+FAILED_ENTRY_REGEX5 = re.compile(r"""User (?P<user>.*) .*from (?P<host>.*) not allowed because none of user's groups are listed in AllowGroups$""")
 
 FAILED_ENTRY_REGEX6 = re.compile(r"""Did not receive identification string .*from (::ffff:)?(?P<host>\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3})""")
 
