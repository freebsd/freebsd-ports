https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=734327

--- rss2email.py.orig	2018-01-14 00:42:27 UTC
+++ rss2email.py
@@ -694,7 +694,7 @@ def run(num=None):
 							for tag in tags:
 								taglist.append(tag['term'])
 						if taglist:
-							tagline = ",".join(taglist)
+							tagline = ",".join(filter(None, taglist))
 					
 					extraheaders = {'Date': datehdr, 'User-Agent': useragenthdr, 'X-RSS-Feed': f.url, 'X-RSS-ID': id, 'X-RSS-URL': link, 'X-RSS-TAGS' : tagline}
 					if BONUS_HEADER != '':
