--- stats.sh.orig	2008-08-06 17:43:32.000000000 -0400
+++ stats.sh	2008-08-06 17:47:16.000000000 -0400
@@ -1,15 +1,23 @@
 #!/bin/sh
 
+# This version of the script is heavily modified from the now
+# unsupported original.
+#
+# This version by:
+#	J.R. Oldroyd <fbsd@opal.com>
+#	FreeBSD port maintained for ASSP
+#
+
 # As a shell script (running on Unix...) it expects to find the local
 # copy of your standard Unix shell, the 'tail' utility and a working 'awk'
 # interpreter.
 
-# I use the default location for ASSP's maillog file, and the 'maillog.log'
+# I use the default location for ASSP's maillog file, and the 'maillog.txt'
 # name (in assp.cfg) to keep ASSP from changing it on me.
 
-# This script attempts to go back at least 300 lines in your maillog.log
+# This script attempts to go back at least 300 lines in your maillog.txt
 # file to give you a nice screenful of goodies to review when it
-# first starts.  If your maillog.log is nearly empty, then just
+# first starts.  If your maillog.txt is nearly empty, then just
 # be patient. As things happen - the logger will reveal it in COLOR!
 # ------------------------------------ KRL -------------------------
 
@@ -27,14 +35,7 @@
 #  order to give you a full screen on startup. Also, it assumes
 #  ANSI Color mode for your screen to display the lines in color.
 #
-# BS (in Red) lines are those caught by the Bayesian filter !!
-# LW (in White .. mostly) are those Local or Whitelisted eMails
-# Ok (in Green) are eMail that fully pass alltests without exceptions.
-# RB (in Cyan) .. Blocked Relay attempt
-# WL+  Whitelist ADDITION by an authorized local user
-# BA (in Cyan) .. Bad ATTACHEMENT rejected
-# SR (in Cyan) .. spam@ report submission
-# NS (in Cyan) .. notspam@ report submission
+# See "man assplog" for a description of the fields and coloring.
 #
 # I got the idea for this script from Mark Constable. He submitted
 #  a similar script to follow the Courier-MTA /var/log/maillog
@@ -46,91 +47,308 @@
 # Some fields are truncated (with a hard-coded length value, usually 40)
 #   to keep each line more or less intact on your screen as things scroll by
 # Colors are coded with ANSI Color coding, your mileage may vary ...
-# I assume the naming convention of 'maillog.log' so ASSP won't munge
+# I assume the naming convention of 'maillog.txt' so ASSP won't munge
 #  each current log into some difficult-to-grok name.  You should try
 #  to use this feature - and perhaps roll the log periodically with
 #  your system's 'newsyslog' functionality. You can send a SIGHUP to
 #  ASSP when you roll the log so it starts afresh..KRL
 
-tail -300 -f /usr/local/assp/maillog.log | \
- awk  ' \
-  /whitelisted/ { \
-  printf("%s %s \033[1;32m%-15s L\033[0mW  %s \033[1;32m->\033[0m %s\n", \
-        substr($1,1,length($1)), \
-        substr($2,1,length($2)), \
-        substr($3,1,length($3)), \
-        substr($4,1,40), \
-        substr($6,1,length($6)) )\
-        } \
-  /email/ && /whitelist addition/ { \
-  printf("%s %s \033[1;32m%-15s W\033[0mA+ %s \033[1;32m->\033[0m %s\n", \
-        substr($1,1,length($1)), \
-        substr($2,1,length($2)), \
-        "+email address+", \
-        substr($4,1,40), \
-        substr($6,1,length($6)) )\
-        } \
-  /whitelist addition/ && !/email/ { \
-  printf("%s %s \033[1;32m%-15s W\033[0mL+ %s \033[1;32m %s %s\033[0m\n", \
-        substr($1,1,length($1)), \
-        substr($2,1,length($2)), \
-        substr($3,1,length($3)), \
-        substr($4,1,40), \
-        "-adds-", \
-        substr($9,1,length($9)) )\
-        } \
-  /Bayesian spam/ { \
-  printf("%s %s \033[1;31m%-15s BS  %s -> %s\033[0m\n", \
-          substr($1,1,length($1)), \
-          substr($2,1,length($2)), \
-          substr($3,1,length($3)), \
-          substr($4,1,40), \
-        substr($6,1,length($6)) )\
-        } \
-  /message ok/ { \
-  printf("%s %s \033[1;32m%-15s Ok  %s -> %s\033[0m\n", \
-        substr($1,1,length($1)), \
-        substr($2,1,length($2)), \
-        substr($3,1,length($3)), \
-        substr($4,1,40), \
-        substr($6,1,length($6)) )\
-        } \
-  /bad attachment/ { \
-        printf("%s %s \033[1;35m%-15s BA  %s -> %s\033[0m\n", \
-        substr($1,1,length($1)), \
-        substr($2,1,length($2)), \
-        substr($3,1,length($3)), \
-        substr($4,1,40), \
-        substr($6,1,length($6)) )\
-        } \
-  /relay attempt blocked/ { \
-        printf("%s %s \033[1;35m%-15s RB  %s -> %s %s %s %s %s\033[0m\n", \
-        substr($1,1,length($1)), \
-        substr($2,1,length($2)), \
-        substr($3,1,length($3)), \
-        substr($4,1,length($4)), \
-        substr($5,1,length($5)), \
-        substr($6,1,length($6)), \
-        substr($7,1,length($7)), \
-        substr($8,1,length($8)), \
-        substr($9,1,length($9)) )\
-        } \
-  /Admin update:/ { \
-  printf("\033[1;33m%s %s %s %s %s %s \033[0m\n", $1, $2, $3, $4, $5, $6) \
-        } \
-  /Email spamreport/ { \
-  printf("%s %s\033[0;36m %-15s SR  %s Email SPAM Submission\033[0m\n", \
-        substr($1,1,length($1)), \
-        substr($2,1,length($2)), \
-        substr($3,1,length($3)), \
-        substr($4,1,length($4)) ) \
-        } \
-  /Email hamreport/ { \
-  printf("%s %s\033[0;36m %-15s NS  %s Email NOTSPAM Submission\033[0m\n", \
-        substr($1,1,length($1)), \
-        substr($2,1,length($2)), \
-        substr($3,1,length($3)), \
-        substr($4,1,length($4)) ) \
- }'
+tail -300 -f /var/db/assp/maillog.txt | awk  '
+  {
+    # look for $3 ~ [reason]
+    p=0
+    if ($3 ~ /\[.*\]/) p=1
+  }
+  /local or whitelisted/ {
+    printf("%s %s \033[1;32m%-15s\033[0m \033[1;37mLW  %s\033[0m \033[1;32m->\033[0m \033[1;37m%s\033[0m\n",
+        $1,
+        $2,
+        $(p+4),
+        substr($(p+5),1,40),
+        $(p+7) )
+    next
+  }
+  /[Em]ail whitelist (addition|deletion):/ {
+    printf("%s %s \033[1;36m%-15s\033[0m \033[1;36mW%s %s\033[0m \033[1;37m%s\033[0m \033[1;36m%s\033[0m\n",
+	$1,
+	$2,
+	$(p+4),
+	(/addition:/) ? "+" : "-",
+	substr($(p+5),1,40),
+        (/addition:/) ? "-adds-" : "-deletes-",
+	$(p+9) )
+    next
+  }
+  /whitelist addition:/ && !/[Ee]mail/ {
+    printf("%s %s \033[1;36m%-15s\033[0m \033[1;36mWC %s\033[0m \033[1;37m%s\033[0m \033[1;36m%s\033[0m\n",
+	$1,
+	$2,
+	$(p+4),
+	substr($(p+5),1,40),
+        "-adds-",
+	$(p+10) )
+    next
+    next
+  }
+  /[Ee]mail (hamreport|help|spamreport|redlist)/ {
+    printf("%s %s\033[1;36m %-15s EM  %s %s%s\033[0m\n",
+        $1,
+        $2,
+        $(p+4),
+        $(p+5),
+	$(p+7),
+	($(p+8)) ? " " $(p+8) : "" )
+    next
+  }
+  /Bayesian Check ( - )?Prob/ {
+    # suppress
+    next
+  }
+  /Bayesian [Ss]pam/ {
+    printf("%s %s \033[1;31m%-15s BS  %s -> %s\033[0m\n",
+        $1,
+        $2,
+        $(p+4),
+        substr($(p+5),1,40),
+        $(p+7) )
+    next
+  }
+  /recipient accepted/ {
+    # suppress
+    next
+  }
+  /message ok/ {
+    printf("%s %s \033[1;32m%-15s OK  %s -> %s\033[0m\n",
+        $1,
+        $2,
+        $(p+4),
+        substr($(p+5),1,40),
+        $(p+7) )
+    next
+  }
+  /bad attachment/ && !/no bad/ {
+        printf("%s %s \033[1;35m%-15s BA  %s -> %s\033[0m\n",
+        $1,
+        $2,
+        $(p+4),
+        substr($(p+5),1,40),
+        $(p+7) )
+    next
+  }
+  /relay attempt blocked/ {
+        printf("%s %s \033[1;35m%-15s RB  %s -> %s\033[0m\n",
+        $1,
+        $2,
+        $(p+4),
+        substr($(p+5),1,40),
+        ($(p+10) ~ /^(.*):$/) ? $(p+11) : $(p+10) )
+    next
+  }
+  /no recipients left -- dropping connection/ {
+    # suppress
+    next
+  }
+  /[Ii]nvalid address rejected/ {
+    printf("%s %s \033[1;34m%-15s IR  %s -> %s\033[0m\n",
+        $1,
+        $2,
+        $(p+4),
+        substr($(p+5),1,40),
+        $NF )
+    next
+  }
+  /malformed address/ {
+    printf("%s %s \033[1;35m%-15s MA  %s -> %s\033[0m\n",
+        $1,
+        $2,
+        $(p+4),
+        substr($(p+5),1,40),
+        $(p+8) )
+    next
+  }
+  /Unknown Sender (with|from) Local Domain/ {
+    printf("%s %s \033[1;34m%-15s IS  %s\033[0m\n",
+        $1,
+        $2,
+        $(p+4),
+        substr($(p+5),1,40) )
+    next
+  }
+  /(Commencing|Completed) (R|DNS|URI)BL checks/ {
+    # suppress
+    next
+  }
+  /((DNS|URI)BL )?Received-(R|DNS|URI)BL: (pass|neutral|fail)|URIBL fail|Bayesian Check URIBL/ {
+    # suppress
+    next
+  }
+  /failed (DNS|URI)BL|failed (R|URI)BL checks|Received-RBL: fail/ {
+    printf("%s %s \033[1;35m%-15s BL  %s -> %s\033[0m\n",
+        $1,
+        $2,
+        $(p+4),
+        substr($(p+5),1,40),
+        $(p+7) )
+    next
+  }
+  /(\[DNSBL]|\[DNSBLcache]).* rejected by / {
+    printf("%s %s \033[1;35m%-15s BL  %s (%s blacklisted by %s)\033[0m\n",
+        $1,
+        $2,
+        $(p+4),
+        substr($(p+5),1,40),
+        $(p+7),
+	$(p+10) )
+    next
+  }
+  /Received-SPF(\(cache\))?: (pass|neutral)| SPF: (soft)?fail|SPFstrict/ {
+    # suppress
+    next
+  }
+  /failed SPF checks|Received-SPF(\(cache\))?: ((soft)?fail|error)| SPF: neutral/ {
+    printf("%s %s \033[1;35m%-15s SP  %s -> %s\033[0m\n",
+        $1,
+        $2,
+        $(p+4),
+        substr($(p+5),1,40),
+        $(p+7) )
+    next
+  }
+  /has spam helo|HELO-Blacklist:/ {
+    printf("%s %s \033[1;35m%-15s HL  %s -> %s %s\033[0m\n",
+        $1,
+        $2,
+        $(p+4),
+        substr($(p+5),1,40),
+        $(p+7),
+        $(p+11) )
+    next
+  }
+  /Forged HELO:/ {
+    printf("%s %s \033[1;35m%-15s HL  %s -> %s\033[0m\n",
+        $1,
+        $2,
+        $(p+4),
+        substr($(p+5),1,40),
+        $(p+8) )
+    next
+  }
+  /Sender Validation:blocked:/ {
+    printf("%s %s \033[1;35m%-15s HL  %s %s\033[0m\n",
+        $1,
+        $2,
+        $(p+4),
+        substr($(p+5),1,40),
+        $(p+10) )
+    next
+  }
+  /(adding new|embargoing|accepting|whitelisting) triplet|(renewing|renewing whitelisted|deleting spamming whitelisted) tuplet/ {
+    # suppress
+    next
+  }
+  /(recipient|bounce) delayed/ {
+    printf("%s %s \033[1;35m%-15s DL  %s -> %s\033[0m\n",
+        $1,
+        $2,
+        $(p+4),
+        substr($(p+5),1,40),
+        $(p+8) )
+    next
+  }
+  /DATA phase delayed/ {
+    # suppress
+    next
+  }
+  /(Admin (update:|connection from ))|AdminUpdate:/ {
+    printf("\033[1;33m%s\033[0m\n", $0)
+    next
+  }
+  /ClamAV: scanning/ {
+    # suppress
+    next
+  }
+  /virus detected/ {
+    printf("%s %s\033[1;35m %-15s VI  %s -> %s (%s)\033[0m\n",
+	$1,
+	$2,
+	$(p+4),
+	$(p+5), $(p+7), $(p+10) )
+    next
+  }
+  /Message-Score:/ {
+    # suppress
+    next
+  }
+  /\[VIRUS].*PB:.*score:.*reason:/ {
+    # suppress
+    next
+    printf("%s %s\033[1;35m %-15s PB  %s %s %s %s (%s)\033[0m\n",
+	$1,
+	$2,
+	$(p+4),
+	$(p+10), $(p+11), $(p+12), $(p+13),
+	substr($(p+14),8,40) )
+    next
+  }
+  /PB:( deleting\(black\)|.*score:.*reason:)/ {
+    # suppress
+    next
+    printf("%s %s\033[1;34m %-15s PB  %s %s %s %s (%s)\033[0m\n",
+	$1,
+	$2,
+	$(p+4),
+	$(p+8), $(p+9), $(p+10), $(p+11),
+	substr($(p+12),8,40) )
+    next
+  }
+  /PBextreme:monitoring/ {
+    # suppress
+    next
+  }
+  /(\[ValidHelo]|\[InvalidHelo]|\[PTRinvalid]|\[PTRmissing])\[scoring]/ {
+    # suppress
+    next
+  }
+  /Message Limit/ {
+    printf("%s %s\033[1;35m %-15s PB  %s -> %s\033[0m\n",
+	$1,
+	$2,
+	$(p+4),
+	substr($(p+5),1,40),
+	substr($(p+7),1,40) )
+    next
+  }
+  /max errors \([0-9]+\) exceeded/ {
+    printf("%s %s\033[1;35m %-15s ME  %s\033[0m\n",
+	$1,
+	$2,
+	$(p+4),
+	substr($(p+5),1,40) )
+    next
+  }
+  /Message proxied without processing/ {
+    # suppress
+    next
+  }
+  /message proxied without processing/ {
+    printf("%s %s \033[1;32m%-15s NP  %s -> %s\033[0m\n",
+        $1,
+        $2,
+        $(p+4),
+        substr($(p+5),1,40),
+        $(p+7) )
+    next
+  }
+  /Regex:(Black|NoProcessingDomain)/ {
+    # suppress
+    next
+  }
+  {
+    printf("%s %s ", $1, $2)
+    for (i=3; i<=NF; i++)
+	printf("\033[1;30m%s\033[0m ", $i)
+    printf("\n")
+  }
+ '
 # end of script
 
