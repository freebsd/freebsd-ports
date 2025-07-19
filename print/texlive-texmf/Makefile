PORTNAME=	texlive
DISTVERSION=	${TEXLIVE_VERSION}
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	LOCAL/tex
PKGNAMESUFFIX=	-texmf
DISTNAME=	${PORTNAME}-${DISTVERSION}${PKGNAMESUFFIX}-freebsd
DIST_SUBDIR=	TeX
EXTRACT_ONLY=

MAINTAINER=	tex@FreeBSD.org
COMMENT=	TeX Live Typesetting System, texmf Tree
WWW=		https://tug.org/texlive/

# Reduce DEPENDS temporarily
USES=		cpe tar:xz tex
CPE_VENDOR=	tug
USE_TEX=	texhash tlmgr:run

NO_ARCH=	yes
NO_BUILD=	yes

NO_WRKSUBDIR=	yes

PKG_CREATE_VERBOSE=	yes
TEXHASHDIRS=		${TEXMFDIR} ${TEXMFDISTDIR}

do-install:
	${TAR} -Jxf ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} \
		-C ${STAGEDIR}${PREFIX}/share \
		--strip-components 1 --no-same-permission --no-same-owner
	@${REINPLACE_CMD} -i '' -E -e '1s|/bin/python3|${python_CMD}|' \
		${STAGEDIR}${PREFIX}/share/texmf-dist/tex/latex/prettytok/prettytok-decode-8bit.py
	${REINPLACE_CMD} -i '' -e '1s|/usr/bin/perl|${perl_CMD}|' \
		${STAGEDIR}${PREFIX}/share/texmf-dist/scripts/eolang/eolang.pl
	# https://ctan.org/ctan-ann/id/mailman.9290.1717583628.3764.ctan-ann@ctan.org
	${REINPLACE_CMD} -e 's|IfInstanceExistTF|IfInstanceExistsTF|g' \
		${STAGEDIR}${PREFIX}/share/texmf-dist/tex/latex/xfrac/xfrac.sty
	${FIND} -s ${STAGEDIR}${PREFIX}/share/texmf-dist -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	${FIND} -s ${STAGEDIR}${PREFIX}/share/texmf-dist -type d -empty | ${SORT} -r | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/#@dir #' >> ${TMPPLIST}

.if defined(MAINTAINER_MODE)
MASTER_SITES=	https://ftp.tu-chemnitz.de/pub/tug/historic/systems/texlive/2025/
EXCLUDE_FILES=		\*/doc/man ls-R doc dvipdfm dvipdfmx dvips \
			fonts/cmap/dvipdfmx fonts/cmap/uptex fonts/enc/dvips \
			fonts/map/dvipdfm fonts/map/dvipdfmx fonts/map/dvips \
			fonts/map/luatex fonts/misc/xetex fonts/source/ptex \
			fonts/tfm/ptex fonts/ofm/public/japanese-otf tex/jadetex \
			tex/lambda fonts/ovp/public/japanese-otf-uptex source \
			fonts/tfm/public/japanese-otf fonts/vf/ptex xdvi \
			fonts/tfm/public/japanese-otf-uptex tex/generic/dvips \
			tex/latex-dev fonts/tfm/uptex fonts/type1/ptex \
			fonts/vf/public/japanese-otf tex/lualatex tex/luatex \
			fonts/vf/public/japanese-otf-uptex fonts/vf/uptex \
			tex/generic/config/luatex-unicode-letters.tex \
			tex/generic/config/luatexiniconfig.tex scripts/xetex \
			tex/generic/context/luatex tex/generic/xetexconfig \
			tex/generic/hyph-utf8/patterns/ptex tex/platex tex/ptex \
			tex/latex/latexconfig/dvilualatex.ini tex/uplatex \
			tex/uptex tex/latex/latexconfig/lualatex-patch-kernel.tex \
			tex/latex/latexconfig/lualatex-reset-codes.tex tex/xelatex \
			tex/xetex tex/latex/latexconfig/lualatex.ini \
			tex/latex/latexconfig/lualatexiniconfig.tex \
			tex/latex/latexconfig/lualatexquotejobname.tex \
			tex/latex/latexconfig/xelatex.ini scripts/context/lua \
			tex/plain/config/aleph.ini web2c/updmap-hdr.cfg \
			tex/plain/config/dviluatex.ini web2c/updmap.cfg \
			tex/plain/config/luatex.ini tex/plain/config/xetex.ini \
			tex/xmltex web2c/fmtutil-hdr.cnf tex/cslatex \
			web2c/texmf.cnf scripts/context/stubs/unix/context \
			scripts/context/stubs/unix/contextjit \
			scripts/context/stubs/unix/luatools \
			scripts/context/stubs/unix/mtxrun \
			scripts/context/stubs/unix/mtxrunjit \
			scripts/context/stubs/unix/texexec \
			scripts/context/stubs/unix/texmfstart \
			scripts/jfontmaps/kanji-config-updmap-sys.sh \
			scripts/jfontmaps/kanji-config-updmap.pl \
			scripts/jfontmaps/kanji-fontmap-creator.pl \
			scripts/lua2dox/lua2dox_filter scripts/pdfjam/pdfflip \
			scripts/pdfjam/pdf180 scripts/pdfjam/pdf270 \
			scripts/pdfjam/pdf90 scripts/pdfjam/pdfbook \
			scripts/pdfjam/pdfjam-pocketmod scripts/pdfjam/pdfjoin \
			scripts/pdfjam/pdfjam-slides3up scripts/pdfjam/pdfnup \
			scripts/pdfjam/pdfjam-slides6up scripts/pdfjam/pdfpun \
			scripts/pmx/pmx2pdf.lua scripts/texlive/allcm.sh \
			scripts/texlive/allneeded.sh scripts/texlive/dvi2fax.sh \
			scripts/texlive/dvired.sh scripts/texlive/e2pall.pl \
			scripts/texlive/fontinst.sh scripts/texlive/kpsetool.sh \
			scripts/texlive/kpsewhere.sh scripts/texlive/ps2frag.sh \
			scripts/texlive/pslatex.sh scripts/texlive/rubibtex.sh \
			scripts/texlive/rumakeindex.sh scripts/texlive/rungs.tlu \
			scripts/texlive/texconfig-dialog.sh \
			scripts/texlive/texconfig-sys.sh scripts/texlive/tlmgr.pl \
			scripts/texlive/texconfig.sh scripts/texlive/texlinks.sh \
			scripts/texliveonfly/texliveonfly.py \
			scripts/crossrefware/bbl2bib.pl \
			scripts/crossrefware/bibmradd.pl \
			scripts/crossrefware/biburl2doi.pl \
			${TEXLIVE_BASE_PLIST}
TEXLIVE_BASE_PLIST!=	grep TEXMFDISTDIR ${.CURDIR}/../texlive-base/pkg-plist | sed 's|%%TEXMFDISTDIR%%/||g'
EXTRACT_AFTER_ARGS=	| ${TAR} xf - \
			${EXCLUDE_FILES:S,^,--exclude ${DISTNAME_TEXMF}/texmf-dist/,}

_maintainer-fetch:
	@${MKDIR} ${DISTDIR}/${DIST_SUBDIR}
	${FETCH_CMD} ${MASTER_SITES}/${DISTNAME_TEXMF}${EXTRACT_SUFX} \
		-o ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME_TEXMF}${EXTRACT_SUFX}

_maintainer-extract: _maintainer-fetch
	${MAKE} clean
	${MKDIR} ${WRKSRC}
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME_TEXMF}${EXTRACT_SUFX} \
		${EXTRACT_AFTER_ARGS} -C ${WRKSRC}$ \
		--strip-components 1 --no-same-permission --no-same-owner

_maintainer-patch: _maintainer-extract
	${MKDIR} ${WRKSRC}/texmf-dist/tex/latex/base
	${REINPLACE_CMD} -i '' \
		's/\\def\\magyar@sugg@ie@low#1#2#3/\\def\\magyar@sugg@ie@low\\protect #1#2#3/' \
		${WRKSRC}/texmf-dist/tex/generic/babel-hungarian/magyar.ldf
	${REINPLACE_CMD} -i '' \
		'/liturgic/d' \
		${WRKSRC}/texmf-dist/tex/generic/config/language.dat \
		${WRKSRC}/texmf-dist/tex/generic/config/language.def
	${FIND} ${WRKSRC} -type f | \
		${XARGS} ${REINPLACE_CMD} -i '' -E -e '1s|/bin/bash|${bash_CMD}|; \
		1s|/usr/bin/perl|${perl_CMD}|; \
		1s|/usr/bin/env python[23]?|${python_CMD}|; \
		1s|/usr/bin/python|${python_CMD}|; \
		1s|/bin/python3|${python_CMD}|; \
		1s|/usr/bin/luatex|${LOCALBASE}/bin/luatex|'

_maintainer-dist: _maintainer-patch
	${TAR} --options xz:compression-level=9 -Jcvf \
		${WRKDIR}/texlive-${TEXLIVE_VERSION}-texmf-freebsd.tar.xz \
		-C ${WRKDIR} ${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}
	scp ${WRKDIR}/texlive-${TEXLIVE_VERSION}-texmf-freebsd.tar.xz \
		bofh@freefall.freebsd.org://home/tex/public_distfiles/

.endif

.include <bsd.port.mk>
