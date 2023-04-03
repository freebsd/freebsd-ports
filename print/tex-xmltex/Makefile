PORTNAME=	xmltex
PORTVERSION=	1.9
PORTREVISION=	4
CATEGORIES=	print
MASTER_SITES=	TEX_CTAN/systems/texlive/${TEXLIVE_YEAR}/
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-${TEXLIVE_VERSION}-texmf
DIST_SUBDIR=	TeX
EXTRACT_ONLY=

MAINTAINER=	tex@FreeBSD.org
COMMENT=	Non-validating XML parser, written in TeX

USES=		tar:xz tex
USE_TEX=	pdftex fmtutil

EXTRACT_AFTER_ARGS=| ${TAR} -xf - -C ${STAGEDIR}${PREFIX}/share \
		--strip-components 1 --no-same-permission --no-same-owner \
		${EXTRACT_FILES:S,^,${DISTNAME}/,}
EXTRACT_FILES= \
	texmf-dist/tex/xmltex \
	texmf-dist/doc/otherformats/xmltex
NO_ARCH=	yes
NO_BUILD=	yes

TEX_FORMATS=	xmltex
TEXHASHDIRS=	${TEXMFDISTDIR}

do-install:
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} \
	    ${EXTRACT_AFTER_ARGS}

.include <bsd.port.mk>
