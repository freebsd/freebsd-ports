# Patch shaped from http://seclists.org/oss-sec/2013/q4/535
===================================================================
--- ./DenyHosts/regex.py.orig	2006-12-07 20:47:04.000000000 +0100
+++ ./DenyHosts/regex.py	2013-12-23 17:17:42.000000000 +0100
@@ -6,22 +6,22 @@
 
 #DATE_FORMAT_REGEX = re.compile(r"""(?P<month>[A-z]{3,3})\s*(?P<day>\d+)""")
 
-SSHD_FORMAT_REGEX = re.compile(r""".* (sshd.*:|\[sshd\]) (?P<message>.*)""")
+SSHD_FORMAT_REGEX = re.compile(r""".*? (sshd.*?:|\[sshd\]) (?P<message>.*)""")
 #SSHD_FORMAT_REGEX = re.compile(r""".* sshd.*: (?P<message>.*)""")
 
-FAILED_ENTRY_REGEX = re.compile(r"""Failed (?P<method>.*) for (?P<invalid>invalid user |illegal user )?(?P<user>.*?) .*from (::ffff:)?(?P<host>\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3})""")
+FAILED_ENTRY_REGEX = re.compile(r"""Failed (?P<method>\S*) for (?P<invalid>invalid user |illegal user )?(?P<user>.*) from (::ffff:)?(?P<host>\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3})$""")
 
-FAILED_ENTRY_REGEX2 = re.compile(r"""(?P<invalid>(Illegal|Invalid)) user (?P<user>.*?) .*from (::ffff:)?(?P<host>\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3})""")
+FAILED_ENTRY_REGEX2 = re.compile(r"""(?P<invalid>(Illegal|Invalid)) user (?P<user>.*) from (::ffff:)?(?P<host>\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3})$""")
 
-FAILED_ENTRY_REGEX3 = re.compile(r"""Authentication failure for (?P<user>.*) .*from (::ffff:)?(?P<host>\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3})""")
+FAILED_ENTRY_REGEX3 = None
 
-FAILED_ENTRY_REGEX4 = re.compile(r"""Authentication failure for (?P<user>.*) .*from (?P<host>.*)""")
+FAILED_ENTRY_REGEX4 = re.compile(r"""Authentication failure for (?P<user>.*) from (::ffff:)?(?P<host>\S+)$""")
 
-FAILED_ENTRY_REGEX5 = re.compile(r"""User (?P<user>.*) .*from (?P<host>.*) not allowed because none of user's groups are listed in AllowGroups""")
+FAILED_ENTRY_REGEX5 = re.compile(r"""User (?P<user>.*) from (::ffff:)?(?P<host>\S+) not allowed because none of user's groups are listed in AllowGroups$""")
 
-FAILED_ENTRY_REGEX6 = re.compile(r"""Did not receive identification string .*from (::ffff:)?(?P<host>\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3})""")
+FAILED_ENTRY_REGEX6 = re.compile(r"""Did not receive identification string .*from (::ffff:)?(?P<host>\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3})$""")
 
-FAILED_ENTRY_REGEX7 = re.compile(r"""User (?P<user>.*) not allowed because not listed in AllowUsers""")
+FAILED_ENTRY_REGEX7 = re.compile(r"""User (?P<user>.*) from (::ffff:)?(?P<host>\S+) not allowed because not listed in AllowUsers$""")
 
 
 # these are reserved for future versions
@@ -42,7 +42,7 @@
     FAILED_ENTRY_REGEX_MAP[i] = rx
 
 
-SUCCESSFUL_ENTRY_REGEX = re.compile(r"""Accepted (?P<method>.*) for (?P<user>.*?) from (::ffff:)?(?P<host>\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3})""")
+SUCCESSFUL_ENTRY_REGEX = re.compile(r"""Accepted (?P<method>\S+) for (?P<user>.*?) from (::ffff:)?(?P<host>\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3})$""")
 
 TIME_SPEC_REGEX = re.compile(r"""(?P<units>\d*)\s*(?P<period>[smhdwy])?""")
 
