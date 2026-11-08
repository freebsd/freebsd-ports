PORTNAME=	cdf3
DISTVERSION=	3.9.2
CATEGORIES=	science
MASTER_SITES=	https://spdf.gsfc.nasa.gov/pub/software/cdf/dist/cdf${VER}/unix/
DISTNAME=	cdf${VER}-dist-cdf

MAINTAINER=	alven@FreeBSD.org
COMMENT=	NASA Common Data Format (CDF) library for scientific data management
WWW=		https://cdf.gsfc.nasa.gov/

LICENSE=	NASA-G
LICENSE_NAME=	NASA/Goddard Space Flight Center
LICENSE_FILE=	${WRKSRC}/CDF_copyright.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cmake:testing fortran ncurses
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_STATIC_CDF

SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/cdf${VER}-dist-main

PLIST_SUB=	SOVERSION=${DISTVERSION}
PORTDOCS=	CDF_copyright.txt CHANGES.txt README_cdf_tools.txt \
		Release_notes.txt Welcome.txt
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

VER=		${DISTVERSION:S/.//:S/./_/}

.include <bsd.port.pre.mk>

.if ${FORTRAN_DEFAULT} != flang
FFLAGS=		-std=legacy
.endif

post-patch:
	${REINPLACE_CMD} -e 's|<path>|${PREFIX}|' \
		${WRKSRC}/src/definitions/definitions.*

post-install:
	cd ${STAGEDIR}${PREFIX} && ${RM} ${PORTDOCS} CDFLeapSeconds.txt HOWTO*

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/samples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>
