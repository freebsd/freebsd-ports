PORTNAME=	texlive
PORTVERSION=	${TEXLIVE_VERSION}
CATEGORIES=	print
MASTER_SITES=	TEX_CTAN/systems/texlive/${TEXLIVE_YEAR}/
PKGNAMESUFFIX=	-texmf
DISTFILES=	${PORTNAME}-${PORTVERSION}${PKGNAMESUFFIX}${EXTRACT_SUFX}
DIST_SUBDIR=	TeX
EXTRACT_ONLY=

MAINTAINER=	tex@FreeBSD.org
COMMENT=	TeX Live Typesetting System, texmf Tree
WWW=		https://tug.org/texlive/

USES=		cpe python:run tar:xz tex
CPE_VENDOR=	tug
USE_TEX=	base basic:extract texhash tlmgr:run

EXTRACT_AFTER_ARGS=	| ${TAR} xf - \
			${EXCLUDE_FILES:S,^,--exclude ${PORTNAME}-${PORTVERSION}${PKGNAMESUFFIX}/,}

NO_ARCH=	yes
NO_BUILD=	yes

NO_WRKSUBDIR=	yes

EXCLUDE_FILES=		\*/doc/man texmf-dist/ls-R texmf-dist/doc \
			texmf-dist/dvipdfm texmf-dist/dvipdfmx texmf-dist/dvips \
			texmf-dist/fonts/cmap/dvipdfmx \
			texmf-dist/fonts/cmap/uptex texmf-dist/fonts/enc/dvips \
			texmf-dist/fonts/map/dvipdfm \
			texmf-dist/fonts/map/dvipdfmx \
			texmf-dist/fonts/map/dvips texmf-dist/fonts/map/luatex \
			texmf-dist/fonts/misc/xetex \
			texmf-dist/fonts/ofm/public/japanese-otf \
			texmf-dist/fonts/ovp/public/japanese-otf-uptex \
			texmf-dist/fonts/source/ptex texmf-dist/fonts/tfm/ptex \
			texmf-dist/fonts/tfm/public/japanese-otf \
			texmf-dist/fonts/tfm/public/japanese-otf-uptex \
			texmf-dist/fonts/tfm/uptex texmf-dist/fonts/type1/ptex \
			texmf-dist/fonts/vf/ptex \
			texmf-dist/fonts/vf/public/japanese-otf \
			texmf-dist/fonts/vf/public/japanese-otf-uptex \
			texmf-dist/fonts/vf/uptex texmf-dist/scripts/xetex \
			texmf-dist/source \
			texmf-dist/tex/generic/config/luatex-unicode-letters.tex \
			texmf-dist/tex/generic/config/luatexiniconfig.tex \
			texmf-dist/tex/generic/context/luatex \
			texmf-dist/tex/generic/dvips \
			texmf-dist/tex/generic/hyph-utf8/patterns/ptex \
			texmf-dist/tex/generic/xetexconfig \
			texmf-dist/tex/jadetex texmf-dist/tex/lambda \
			texmf-dist/tex/latex/base \
			texmf-dist/tex/latex/latexconfig/dvilualatex.ini \
			texmf-dist/tex/latex/latexconfig/lualatex-patch-kernel.tex \
			texmf-dist/tex/latex/latexconfig/lualatex-reset-codes.tex \
			texmf-dist/tex/latex/latexconfig/lualatex.ini \
			texmf-dist/tex/latex/latexconfig/lualatexiniconfig.tex \
			texmf-dist/tex/latex/latexconfig/lualatexquotejobname.tex \
			texmf-dist/tex/latex/latexconfig/xelatex.ini \
			texmf-dist/tex/lualatex texmf-dist/tex/luatex \
			texmf-dist/tex/plain/config/aleph.ini \
			texmf-dist/tex/plain/config/dviluatex.ini \
			texmf-dist/tex/plain/config/luatex.ini \
			texmf-dist/tex/plain/config/xetex.ini \
			texmf-dist/tex/platex texmf-dist/tex/ptex \
			texmf-dist/tex/uplatex texmf-dist/tex/uptex \
			texmf-dist/tex/xelatex texmf-dist/tex/xetex \
			texmf-dist/tex/xmltex texmf-dist/web2c/fmtutil-hdr.cnf \
			texmf-dist/tex/cslatex texmf-dist/web2c/texmf.cnf \
			texmf-dist/web2c/updmap-hdr.cfg \
			texmf-dist/web2c/updmap.cfg texmf-dist/xdvi \
			texmf-dist/scripts/context/stubs/unix/context \
			texmf-dist/scripts/context/stubs/unix/contextjit \
			texmf-dist/scripts/context/stubs/unix/luatools \
			texmf-dist/scripts/context/stubs/unix/mtxrun \
			texmf-dist/scripts/context/stubs/unix/mtxrunjit \
			texmf-dist/scripts/context/stubs/unix/texexec \
			texmf-dist/scripts/context/stubs/unix/texmfstart \
			texmf-dist/scripts/context/lua \
			texmf-dist/scripts/jfontmaps/kanji-config-updmap-sys.sh \
			texmf-dist/scripts/jfontmaps/kanji-config-updmap.pl \
			texmf-dist/scripts/jfontmaps/kanji-fontmap-creator.pl \
			texmf-dist/scripts/lua2dox/lua2dox_filter \
			texmf-dist/scripts/pdfjam/pdf180 \
			texmf-dist/scripts/pdfjam/pdf270 \
			texmf-dist/scripts/pdfjam/pdf90 \
			texmf-dist/scripts/pdfjam/pdfbook \
			texmf-dist/scripts/pdfjam/pdfflip \
			texmf-dist/scripts/pdfjam/pdfjam-pocketmod \
			texmf-dist/scripts/pdfjam/pdfjam-slides3up \
			texmf-dist/scripts/pdfjam/pdfjam-slides6up \
			texmf-dist/scripts/pdfjam/pdfjoin \
			texmf-dist/scripts/pdfjam/pdfnup \
			texmf-dist/scripts/pdfjam/pdfpun \
			texmf-dist/scripts/pmx/pmx2pdf.lua \
			texmf-dist/scripts/texlive/allcm.sh \
			texmf-dist/scripts/texlive/allneeded.sh \
			texmf-dist/scripts/texlive/dvi2fax.sh \
			texmf-dist/scripts/texlive/dvired.sh \
			texmf-dist/scripts/texlive/e2pall.pl \
			texmf-dist/scripts/texlive/fontinst.sh \
			texmf-dist/scripts/texlive/kpsetool.sh \
			texmf-dist/scripts/texlive/kpsewhere.sh \
			texmf-dist/scripts/texlive/ps2frag.sh \
			texmf-dist/scripts/texlive/pslatex.sh \
			texmf-dist/scripts/texlive/rubibtex.sh \
			texmf-dist/scripts/texlive/rumakeindex.sh \
			texmf-dist/scripts/texlive/rungs.tlu \
			texmf-dist/scripts/texlive/texconfig-dialog.sh \
			texmf-dist/scripts/texlive/texconfig-sys.sh \
			texmf-dist/scripts/texlive/texconfig.sh \
			texmf-dist/scripts/texlive/texlinks.sh \
			texmf-dist/scripts/texlive/tlmgr.pl \
			texmf-dist/scripts/texliveonfly/texliveonfly.py \
			texmf-dist/scripts/crossrefware/bbl2bib.pl \
			texmf-dist/scripts/crossrefware/bibmradd.pl \
			texmf-dist/scripts/crossrefware/biburl2doi.pl \
			${TEXLIVE_BASE_PLIST}
TEXLIVE_BASE_PLIST!=	grep TEXMFDISTDIR ${.CURDIR}/../texlive-base/pkg-plist | sed 's|%%TEXMFDISTDIR%%|texmf-dist|g'
PKG_CREATE_VERBOSE=	yes
TEXHASHDIRS=		${TEXMFDIR} ${TEXMFDISTDIR}

do-install:
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-${PORTVERSION}${PKGNAMESUFFIX}${EXTRACT_SUFX} \
		${EXTRACT_AFTER_ARGS} -C ${STAGEDIR}${PREFIX}/share \
		--strip-components 1 --no-same-permission --no-same-owner
	${MKDIR} ${STAGEDIR}${PREFIX}/${TEXMFDISTDIR}/tex/latex/base
	${REINPLACE_CMD} -i '' 's/\\def\\magyar@sugg@ie@low#1#2#3/\\def\\magyar@sugg@ie@low\\protect #1#2#3/' ${STAGEDIR}${PREFIX}/share/texmf-dist/tex/generic/babel-hungarian/magyar.ldf
	${FIND} -s ${STAGEDIR}${PREFIX}/share/texmf-dist -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	${FIND} -s ${STAGEDIR}${PREFIX}/share/texmf-dist -type d -empty | ${SORT} -r | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/#@dir #' >> ${TMPPLIST}

post-install:
	@${REINPLACE_CMD} -i '' -e '1s|/bin/bash|${bash_CMD}|' \
		${STAGEDIR}${PREFIX}/share/texmf-dist/scripts/logicpuzzle/createlpsudoku \
		${STAGEDIR}${PREFIX}/share/texmf-dist/scripts/logicpuzzle/lpsmag
	@${REINPLACE_CMD} -i '' -e '1s|/usr/bin/perl|${perl_CMD}|' \
		${STAGEDIR}${PREFIX}/share/texmf-dist/scripts/mycv/mycv_split_contents.pl
	@${REINPLACE_CMD} -i '' -E -e '1s|/usr/bin/env python[23]?|${python_CMD}|; \
		1s|/usr/bin/python|${python_CMD}|;' \
		${STAGEDIR}${PREFIX}/share/texmf-dist/asymptote/GUI/*.py \
		${STAGEDIR}${PREFIX}/share/texmf-dist/scripts/webquiz/webquiz \
		${STAGEDIR}${PREFIX}/share/texmf-dist/scripts/*/*.py \
		${STAGEDIR}${PREFIX}/share/texmf-dist/tex/latex/wargame/*.py
	@${REINPLACE_CMD} -i '' -E -e '/ec\.tex/d' \
		${STAGEDIR}${PREFIX}/share/texmf-dist/tex/generic/hyph-utf8/loadhyph/loadhyph-zh-latn-pinyin.tex \
		${STAGEDIR}${PREFIX}/share/texmf-dist/tex/generic/hyph-utf8/loadhyph/loadhyph-la-x-liturgic.tex
	@${REINPLACE_CMD} -i '' -e '1s|/usr/bin/luatex|${LOCALBASE}/bin/luatex|' \
		${STAGEDIR}${PREFIX}/share/texmf-dist/tex/generic/pgfplots/lua/*.lua

.include <bsd.port.mk>
