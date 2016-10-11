--- doc/docgen.sh.orig	2016-07-20 16:53:48 UTC
+++ doc/docgen.sh
@@ -1,8 +1,11 @@
 #!/bin/sh
 
-xsltproc http://docbook.sourceforge.net/release/xsl/current/html/docbook.xsl docs.xml > docs.html && \
+xsltproc LOCALBASE/share/xsl/docbook/manpages/docbook.xsl docs.xml > docs.html && \
+xsltproc LOCALBASE/share/xsl/docbook/manpages/docbook.xsl variables.xml > variables.html && \
+xsltproc LOCALBASE/share/xsl/docbook/manpages/docbook.xsl config_settings.xml > config_settings.html && \
+xsltproc LOCALBASE/share/xsl/docbook/manpages/docbook.xsl lua.xml > lua.html && \
 db2x_xsltproc -s man docs.xml -o docs.mxml && \
-db2x_manxml docs.mxml && \
+db2x_manxml docs.mxml
 { echo ".TH CONKY 1 \"August 2005\" \"conky compiled August 2005\" \"User Commands\""; sed 1d < conky.1; } > conky.2 && \
 mv conky.2 conky.1 && \
 man ./conky.1 | col -b > README && \
