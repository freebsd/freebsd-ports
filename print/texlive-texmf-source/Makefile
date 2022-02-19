PORTNAME=	texlive
PORTVERSION=	${TEXLIVE_VERSION}
CATEGORIES=	print
MASTER_SITES=	TEX_CTAN/systems/texlive/${TEXLIVEVEYEAR}/
PKGNAMESUFFIX=	-texmf-source
DISTNAME=	${PORTNAME}-${PORTVERSION}-texmf
DIST_SUBDIR=	TeX

MAINTAINER=	tex@FreeBSD.org
COMMENT=	TeX Live Typesetting System, texmf Tree (source)

USES=		cpe perl5 python:build tar:xz
CPE_VENDOR=	tug
USE_PERL5=	build
USE_TEX=	texmf>=${PORTVERSION}

CONFLICTS_INSTALL=	texlive-base-202[0-9]*

EXTRACT_AFTER_ARGS=	| ${TAR} xf - \
			${INCLUDE_FILES:S,^,--include ${DISTNAME}/,} \
			${EXCLUDE_FILES:S,^,--exclude ${DISTNAME}/,}
NO_BUILD=	yes

INCLUDE_FILES=	texmf-dist/source
EXCLUDE_FILES=	texmf-dist/source/fonts/japanese-otf \
		texmf-dist/source/fonts/japanese-otf-uptex \
		texmf-dist/source/fonts/uptex texmf-dist/source/jadetex \
		texmf-dist/source/lambda texmf-dist/source/lualatex \
		texmf-dist/source/luatex texmf-dist/source/platex \
		texmf-dist/source/uplatex texmf-dist/source/xelatex \
		texmf-dist/source/xmltex

TEXHASHDIRS=	${TEXMFDISTDIR}

do-extract:
	@${MKDIR} ${WRKDIR}

do-install:
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} \
		${EXTRACT_AFTER_ARGS} -C ${STAGEDIR}${PREFIX}/share \
		--strip-components 1 --no-same-permission --no-same-owner
	${REINPLACE_CMD} -i '' -e 's|/bin/bash|${PREFIX}/bin/bash|g' \
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/fonts/ae/clean \
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/fonts/ae/install \
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/latex/fifinddo-info/makevars/bashvars.sh \
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/latex/fifinddo-info/makevars/texvars.sh \
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/latex/stex/bin/installFonts.sh \
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/latex/avremu/test-suite/test-suite
	${REINPLACE_CMD} -i '' -e 's|/usr/bin/env python|${PYTHON_CMD}|g' \
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/fonts/gentium-tug/type1/kerncorrection.py \
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/fonts/gentium-tug/type1/afmcreator.py \
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/fonts/gentium-tug/type1/greekcorrection.py
	${REINPLACE_CMD} -i '' -e 's|/usr/bin/perl|${PERL}|g' \
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/generic/hyph-utf8/contributed/make-exhyph.pl \
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/generic/ruhyphen/sorthyph \
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/generic/ruhyphen/reduce-patt \
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/latex/stex/bin/sms \
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/latex/stex/bin/checksum \
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/latex/stex/bin/filedate \
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/latex/proposal/bin/checksum \
		${STAGEDIR}${PREFIX}/share/texmf-dist/source/latex/proposal/bin/filedate
	${FIND} -s ${STAGEDIR}${PREFIX}/share/texmf-dist -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	${FIND} -s ${STAGEDIR}${PREFIX}/share/texmf-dist -type d -empty | ${SORT} -r | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/#@dir #' >> ${TMPPLIST}

.include <bsd.port.mk>
