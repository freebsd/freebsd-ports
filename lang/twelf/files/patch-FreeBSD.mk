--- FreeBSD.mk.orig	2009-02-12 21:33:04.000000000 -0500
+++ FreeBSD.mk	2009-02-12 21:48:54.000000000 -0500
@@ -0,0 +1,82 @@
+# ---------------------------------------------------------------
+# Executables
+# ---------------------------------------------------------------
+
+arch != uname -p
+
+.if ${arch} == "i386"
+smlarch = x86
+.else
+smlarch = ${arch}
+.endif
+
+prefix        = ${PREFIX}
+bindir        = ${prefix}/bin
+infodir       = ${prefix}/info
+twelfexecdir  = ${prefix}/libexec/twelf
+twelfsharedir = ${prefix}/share/twelf
+
+runfile  = bin/twelf-server
+heapfile = bin/.heap/twelf-server.${smlarch}-bsd
+
+# ---------------------------------------------------------------
+# Documentation
+# ---------------------------------------------------------------
+
+htmlnodes = toc abt 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
+
+dvifile = doc/dvi/twelf.dvi
+htmlfiles := doc/html/index.html ${htmlnodes:%=doc/html/twelf_%.html}
+infofile = doc/info/twelf.info
+pdffile = doc/pdf/twelf.pdf
+psfile = doc/ps/twelf.ps
+
+docfiles = ${dvifile} ${htmlfiles} ${infofile} ${pdffile} ${psfile}
+
+.for file in ${docfiles}
+${file}:
+	(cd doc/guide; make; make install)
+.endfor
+
+all: ${runfile} ${heapfile} ${docfiles}
+
+# ---------------------------------------------------------------
+# Installation
+# ---------------------------------------------------------------
+
+sharefiles != (echo README HISTORY;                            \
+               echo ${docfiles};                               \
+               find emacs        -type f -not -path '*/CVS/*'; \
+               find examples     -type f -not -path '*/CVS/*'; \
+               find examples-clp -type f -not -path '*/CVS/*'; \
+               find exercises    -type f -not -path '*/CVS/*'; \
+               find tex          -type f -not -path '*/CVS/*'; \
+               find vim          -type f -not -path '*/CVS/*' )
+
+installfiles := ${bindir}/twelf-server             \
+                ${twelfsharedir}/${runfile}        \
+                ${twelfexecdir}/${heapfile}        \
+                ${infodir}/twelf.info              \
+                ${sharefiles:%=$(twelfsharedir)/%}
+
+${bindir}/twelf-server: ${twelfsharedir}/${runfile}
+	ln -s $? $@
+
+${twelfsharedir}/${runfile}: ${runfile}
+	@install -d -o root -g wheel -m 0755 ${@D}
+	install -o root -g wheel -m 0555 $? $@
+
+${twelfexecdir}/${heapfile}: ${heapfile}
+	@install -d -o root -g wheel -m 0755 ${@D}
+	install -o root -g wheel -m 0444 $? $@
+
+${infodir}/twelf.info: doc/info/twelf.info
+	install -o root -g wheel -m 0444 $? $@
+
+.for file in ${sharefiles}
+${twelfsharedir}/${file}: ${file}
+	@install -d -o root -g wheel -m 0755 ${@D}
+	install -o root -g wheel -m 0644 $? $@
+.endfor
+
+install: ${installfiles}
--- FreeBSD.mk.orig	2009-02-12 21:33:04.000000000 -0500
+++ FreeBSD.mk	2009-02-12 21:48:54.000000000 -0500
@@ -0,0 +1,82 @@
+# ---------------------------------------------------------------
+# Executables
+# ---------------------------------------------------------------
+
+arch != uname -p
+
+.if ${arch} == "i386"
+smlarch = x86
+.else
+smlarch = ${arch}
+.endif
+
+prefix        = ${PREFIX}
+bindir        = ${prefix}/bin
+infodir       = ${prefix}/info
+twelfexecdir  = ${prefix}/libexec/twelf
+twelfsharedir = ${prefix}/share/twelf
+
+runfile  = bin/twelf-server
+heapfile = bin/.heap/twelf-server.${smlarch}-bsd
+
+# ---------------------------------------------------------------
+# Documentation
+# ---------------------------------------------------------------
+
+htmlnodes = toc abt 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
+
+dvifile = doc/dvi/twelf.dvi
+htmlfiles := doc/html/index.html ${htmlnodes:%=doc/html/twelf_%.html}
+infofile = doc/info/twelf.info
+pdffile = doc/pdf/twelf.pdf
+psfile = doc/ps/twelf.ps
+
+docfiles = ${dvifile} ${htmlfiles} ${infofile} ${pdffile} ${psfile}
+
+.for file in ${docfiles}
+${file}:
+	(cd doc/guide; make; make install)
+.endfor
+
+all: ${runfile} ${heapfile} ${docfiles}
+
+# ---------------------------------------------------------------
+# Installation
+# ---------------------------------------------------------------
+
+sharefiles != (echo README HISTORY;                            \
+               echo ${docfiles};                               \
+               find emacs        -type f -not -path '*/CVS/*'; \
+               find examples     -type f -not -path '*/CVS/*'; \
+               find examples-clp -type f -not -path '*/CVS/*'; \
+               find exercises    -type f -not -path '*/CVS/*'; \
+               find tex          -type f -not -path '*/CVS/*'; \
+               find vim          -type f -not -path '*/CVS/*' )
+
+installfiles := ${bindir}/twelf-server             \
+                ${twelfsharedir}/${runfile}        \
+                ${twelfexecdir}/${heapfile}        \
+                ${infodir}/twelf.info              \
+                ${sharefiles:%=$(twelfsharedir)/%}
+
+${bindir}/twelf-server: ${twelfsharedir}/${runfile}
+	ln -s $? $@
+
+${twelfsharedir}/${runfile}: ${runfile}
+	@install -d -o root -g wheel -m 0755 ${@D}
+	install -o root -g wheel -m 0555 $? $@
+
+${twelfexecdir}/${heapfile}: ${heapfile}
+	@install -d -o root -g wheel -m 0755 ${@D}
+	install -o root -g wheel -m 0444 $? $@
+
+${infodir}/twelf.info: doc/info/twelf.info
+	install -o root -g wheel -m 0444 $? $@
+
+.for file in ${sharefiles}
+${twelfsharedir}/${file}: ${file}
+	@install -d -o root -g wheel -m 0755 ${@D}
+	install -o root -g wheel -m 0644 $? $@
+.endfor
+
+install: ${installfiles}
