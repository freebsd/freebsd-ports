--- src/ssltools.h.orig	2019-01-05 13:22:11 UTC
+++ src/ssltools.h
@@ -1057,7 +1057,7 @@ char find_display[] = 
 "#\n"
 "if [ \"X$FD_XDM\" != \"X\" ]; then\n"
 "	list=\"\"\n"
-"	for pair in `echo \"$psout\" | grep '/X.* :[0-9][0-9]* .*-auth' | egrep -v 'startx|xinit' | sed -e 's,^.*/X.* \\(:[0-9][0-9]*\\) .* -auth \\([^ ][^ ]*\\).*$,\\1\\,\\2,' | sort -u`\n"
+"	for pair in `echo \"$psout\" | grep '/X.* :[0-9][0-9]* .*-auth' | egrep -v 'startx|xinit' | sed -e 's,^.*/X.* \\(:[0-9][0-9]*\\).*-auth \\([^ ][^ ]*\\).*$,\\1\\,\\2,' | sort -u`\n"
 "	do\n"
 "		da=`echo \"$pair\" | awk -F, '{print $1}'`\n"
 "		xa=`echo \"$pair\" | awk -F, '{print $2}'`\n"
