PORTNAME=	xmltex
PORTVERSION=	1.9
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2015/
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-20150523-texmf
DIST_SUBDIR=	TeX
EXTRACT_ONLY=

MAINTAINER=	freebsd-tex@FreeBSD.org
COMMENT=	Non-validating XML parser, written in TeX

USES=		tar:xz
USE_TEX=	texmf pdftex fmtutil
TEXHASHDIRS=	${TEXMFDISTDIR}
EXTRACT_AFTER_ARGS=| ${TAR} -xf - -C ${STAGEDIR}${PREFIX}/share \
		--strip-components 1 --no-same-permission --no-same-owner \
		${EXTRACT_FILES:S,^,${DISTNAME}/,}
EXTRACT_FILES= \
	texmf-dist/tex/xmltex \
	texmf-dist/doc/otherformats/xmltex
NO_ARCH=	yes
NO_BUILD=	yes
TEX_FORMATS=	xmltex

do-install:
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} \
	    ${EXTRACT_AFTER_ARGS}

.include <bsd.port.mk>
