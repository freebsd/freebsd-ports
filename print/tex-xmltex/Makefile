PORTNAME=	xmltex
DISTVERSION=	${TEXLIVE_VERSION}
CATEGORIES=	print
MASTER_SITES=	LOCAL/tex
PKGNAMEPREFIX=	tex-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${TEXLIVE_VERSION}-freebsd
DIST_SUBDIR=	TeX
EXTRACT_ONLY=

MAINTAINER=	tex@FreeBSD.org
COMMENT=	Non-validating XML parser, written in TeX

USES=		tar:xz tex
USE_TEX=	pdftex fmtutil

NO_ARCH=	yes
NO_BUILD=	yes

TEX_FORMATS=	xmltex
TEXHASHDIRS=	${TEXMFDISTDIR}

do-install:
	${TAR} -Jxf ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} \
		-C ${STAGEDIR}${PREFIX}/share \
		--strip-components 1 --no-same-permission --no-same-owner

.if defined(MAINTAINER_MODE)
_EXTRACT_FILES= \
	texmf-dist/tex/xmltex \
	texmf-dist/doc/otherformats/xmltex
_WRKSRC=	${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME}-${TEXLIVE_VERSION}

_maintainer-extract:
	${MAKE} clean
	${MKDIR} ${_WRKSRC}
	${TAR} -xf ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME_TEXMF}${EXTRACT_SUFX} \
		-C ${_WRKSRC}$ \
		--strip-components 1 --no-same-permission --no-same-owner \
		${_EXTRACT_FILES:S,^,${DISTNAME_TEXMF}/,}

_maintainer-dist: _maintainer-extract
	${TAR} --options xz:compression-level=9 -Jcvf \
		${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME}-${TEXLIVE_VERSION}-freebsd.tar.xz \
		-C ${WRKDIR} ${PKGNAMEPREFIX}${PORTNAME}-${TEXLIVE_VERSION}
	scp ${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME}-${TEXLIVE_VERSION}-freebsd.tar.xz \
		bofh@freefall.freebsd.org://home/tex/public_distfiles/

.endif

.include <bsd.port.mk>
