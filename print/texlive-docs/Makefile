PORTNAME=	texlive
DISTVERSION=	${TEXLIVE_VERSION}
CATEGORIES=	print
MASTER_SITES=	TEX_CTAN/systems/texlive/${TEXLIVE_YEAR}/
PKGNAMESUFFIX=	-docs
DISTNAME=	${PORTNAME}-${PORTVERSION}-texmf
DIST_SUBDIR=	TeX

MAINTAINER=	tex@FreeBSD.org
COMMENT=	TeX Live Typesetting System, documentation
WWW=		https://tug.org/texlive/

USES=		perl5 python:env tar:xz tex

EXTRACT_AFTER_ARGS=	| ${TAR} xf - \
			${EXCLUDE_FILES:S,^,--exclude ${DISTNAME}/,}
NO_BUILD=	yes

EXCLUDE_FILES=	\*/doc/man texmf-dist/doc/aleph texmf-dist/doc/lualatex \
		texmf-dist/doc/luatex texmf-dist/doc/xelatex \
		texmf-dist/doc/xetex texmf-dist/doc/otherformats/jadetex \
		texmf-dist/doc/otherformats/xmltex texmf-dist/doc/ptex \
		texmf-dist/doc/platex texmf-dist/doc/uptex \
		texmf-dist/doc/uplatex texmf-dist/doc/fonts/japanese-otf \
		texmf-dist/doc/fonts/japanese-otf-uptex \
		texmf-dist/doc/fonts/jfontmaps texmf-dist/doc/dvips \
		texmf-dist/doc/dvipdfmx

NO_ARCH=	yes

do-extract:
	@${MKDIR} ${WRKDIR}

do-install:
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} \
	    ${EXTRACT_AFTER_ARGS} -C ${STAGEDIR}${PREFIX}/share \
	    --strip-components 1 --no-same-permission --no-same-owner \
	    ${DISTNAME}/texmf-dist/doc
	${FIND} -s ${STAGEDIR}${PREFIX}/share/texmf-dist -type f | \
		${XARGS} ${REINPLACE_CMD} -i '' -E -e \
		's|/usr/bin/fontforge|${PREFIX}/bin/fontforge|g; \
		s|/bin/bash|${PREFIX}/bin/bash|g; \
		s|/usr/bin/perl|${PERL}|g; \
		s|/usr/bin/texlua|${PREFIX}/bin/texlua|g; \
		s|/usr/bin/[env |python3?]+[python3?]?|${PYTHON_CMD}|'
	${FIND} -s ${STAGEDIR}${PREFIX}/share/texmf-dist -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	${FIND} -s ${STAGEDIR}${PREFIX}/share/texmf-dist -type d -empty | ${SORT} -r | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/#@dir #' >> ${TMPPLIST}

.include <bsd.port.mk>
