# $FreeBSD$

PORTNAME=	xmltex
PORTVERSION=	1.9
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2012/
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-20120701-texmf
EXTRACT_ONLY=

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Non-validating XML parser, written in TeX

USE_XZ=		yes
USE_TEX=	texmf pdftex fmtutil
TEXHASHDIRS=	${TEXMFDISTDIR}
EXTRACT_AFTER_ARGS=| ${TAR} -xf - -C ${PREFIX}/share \
		--strip-components 1 --no-same-permission --no-same-owner \
		${EXTRACT_FILES:S,^,${DISTNAME}/,}
EXTRACT_FILES= \
	texmf-dist/source/xmltex \
	texmf-dist/tex/xmltex \
	texmf-dist/doc/otherformats/xmltex
NO_WRKSRC=	yes
NO_BUILD=	yes
TEX_FORMATS=	xmltex

do-install:
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} \
		${EXTRACT_AFTER_ARGS}

.include <bsd.port.mk>
