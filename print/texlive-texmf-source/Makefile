PORTNAME=	texlive
DISTVERSION=	${TEXLIVE_VERSION}
CATEGORIES=	print
MASTER_SITES=	LOCAL/tex
PKGNAMESUFFIX=	-texmf-source
DISTNAME=	${PORTNAME}-${DISTVERSION}${PKGNAMESUFFIX}-freebsd
DIST_SUBDIR=	TeX

MAINTAINER=	tex@FreeBSD.org
COMMENT=	TeX Live Typesetting System, texmf Tree (source)
WWW=		https://tug.org/texlive/

USES=		cpe perl5 python:build tar:xz tex
CPE_VENDOR=	tug
USE_PERL5=	build

CONFLICTS_INSTALL=	texlive-base-202[0-9]*

NO_BUILD=	yes

TEXHASHDIRS=	${TEXMFDISTDIR}

do-extract:
	@${MKDIR} ${WRKDIR}

do-install:
	${TAR} -Jxf ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} \
		-C ${STAGEDIR}${PREFIX}/share \
		--strip-components 1 --no-same-permission --no-same-owner
	${FIND} -s ${STAGEDIR}${PREFIX}/share/texmf-dist -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	${FIND} -s ${STAGEDIR}${PREFIX}/share/texmf-dist -type d -empty | ${SORT} -r | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/#@dir #' >> ${TMPPLIST}

.if defined(MAINTAINER_MODE)
_INCLUDE_FILES=	source
_EXCLUDE_FILES=	source/fonts/japanese-otf source/luatex source/platex \
		source/fonts/japanese-otf-uptex source/xmltex \
		source/fonts/uptex source/jadetex \
		source/lambda source/lualatex source/uplatex source/xelatex
_WRKSRC=	${WRKDIR}/${PORTNAME}-${DISTVERSION}${PKGNAMESUFFIX}

_maintainer-extract:
	${MAKE} clean
	${MKDIR} ${_WRKSRC}
	${TAR} xf ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME_TEXMF}${EXTRACT_SUFX} \
		-C ${_WRKSRC}$ \
		--strip-components 1 --no-same-permission --no-same-owner \
		${_INCLUDE_FILES:S,^,--include ${DISTNAME_TEXMF}/texmf-dist/,} \
		${_EXCLUDE_FILES:S,^,--exclude ${DISTNAME_TEXMF}/texmf-dist/,}

_maintainer-patch: _maintainer-extract
	${REINPLACE_CMD} -i '' -e 's|/bin/bash|${PREFIX}/bin/bash|g' \
		${_WRKSRC}/texmf-dist/source/fonts/ae/clean \
		${_WRKSRC}/texmf-dist/source/fonts/ae/install \
		${_WRKSRC}/texmf-dist/source/latex/avremu/test-suite/test-suite \
		${_WRKSRC}/texmf-dist/source/latex/fifinddo-info/makevars/bashvars.sh \
		${_WRKSRC}/texmf-dist/source/latex/fifinddo-info/makevars/texvars.sh \
		${_WRKSRC}/texmf-dist/source/latex/nwafuthesis/build.sh \
		${_WRKSRC}/texmf-dist/source/support/optexcount/install.sh
	${REINPLACE_CMD} -i '' -E -e '1s|/usr/bin/env python[23]?|${python_CMD}|' \
		${_WRKSRC}/texmf-dist/source/fonts/gentium-tug/type1/kerncorrection.py \
		${_WRKSRC}/texmf-dist/source/fonts/gentium-tug/type1/afmcreator.py \
		${_WRKSRC}/texmf-dist/source/fonts/gentium-tug/type1/greekcorrection.py \
		${_WRKSRC}/texmf-dist/source/latex/wargame/utils/wgexport.py \
		${_WRKSRC}/texmf-dist/source/latex/wargame/utils/wgsvg2tikz.py \
		${_WRKSRC}/texmf-dist/source/support/optexcount/optexcount.py
	${REINPLACE_CMD} -i '' -e 's|/usr/bin/perl|${PERL}|g' \
		${_WRKSRC}/texmf-dist/source/generic/hyph-utf8/contributed/make-exhyph.pl \
		${_WRKSRC}/texmf-dist/source/generic/ruhyphen/sorthyph \
		${_WRKSRC}/texmf-dist/source/generic/ruhyphen/reduce-patt \
		${_WRKSRC}/texmf-dist/source/latex/proposal/bin/checksum \
		${_WRKSRC}/texmf-dist/source/latex/proposal/bin/filedate

_maintainer-dist: _maintainer-patch
	${TAR} --options xz:compression-level=9 -Jcvf \
		${WRKDIR}/${DISTFILES} \
		-C ${WRKDIR} ${PORTNAME}-${DISTVERSION}${PKGNAMESUFFIX}
	scp ${WRKDIR}/${DISTFILES} \
		bofh@freefall.freebsd.org://home/tex/public_distfiles/

.endif

.include <bsd.port.mk>
