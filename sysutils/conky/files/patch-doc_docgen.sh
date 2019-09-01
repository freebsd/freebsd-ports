--- doc/docgen.sh.orig	2019-08-12 21:53:54 UTC
+++ doc/docgen.sh
@@ -1,6 +1,9 @@
 #!/bin/sh
 
-xsltproc http://docbook.sourceforge.net/release/xsl/current/html/docbook.xsl docs.xml > docs.html && \
+xsltproc LOCALBASE/share/xsl/docbook/html/docbook.xsl docs.xml > docs.html && \
+xsltproc LOCALBASE/share/xsl/docbook/html/docbook.xsl variables.xml > variables.html && \
+xsltproc LOCALBASE/share/xsl/docbook/html/docbook.xsl config_settings.xml > config_settings.html && \
+xsltproc LOCALBASE/share/xsl/docbook/html/docbook.xsl lua.xml > lua.html && \
 db2x_xsltproc -s man docs.xml -o docs.mxml && \
 db2x_manxml docs.mxml && \
 { echo ".TH CONKY 1 \"August 2005\" \"conky compiled August 2005\" \"User Commands\""; sed 1d < conky.1; } > conky.2 && \
