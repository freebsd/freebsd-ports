# Created by: Thierry Thomas <thierry@pompo.net>

PORTNAME=	cdf3
PORTVERSION=	3.8.0
CATEGORIES=	science
MASTER_SITES=	https://spdf.gsfc.nasa.gov/pub/software/cdf/dist/cdf38_0/
DISTNAME=	cdf${VER}-dist-cdf
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Device independent view of the CDF data model

LICENSE=	NASA-G
LICENSE_NAME=	NASA/Goddard Space Flight Center
LICENSE_FILE=	${WRKSRC}/CDF_copyright.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	bash:shells/bash

USES=		fortran ncurses gmake

USE_LDCONFIG=	yes
MAKE_FLAGS=	INSTALLDIR=${STAGEDIR}${PREFIX} OS=freebsd ENV=gnu \
		FORTRAN=yes FC_freebsd=${F77}
MAKE_JOBS_UNSAFE=	yes
TEST_TARGET=	test  # XXX: test segfaults
FFLAGS+=	-std=legacy

WRKSRC=		${WRKDIR}/cdf${VER}-dist
SUB_FILES=	pkg-message

VER=		${PORTVERSION:S/.//:S/./_/}
DEFS=		B C K

PORTDOCS=	CDF_copyright.txt CHANGES.txt Release.notes Welcome.txt

OPTIONS_DEFINE=	DOCS EXAMPLES

MAKE_ARGS+=	OS=freebsd ENV=gnu all

post-patch:
.for def in ${DEFS}
	@${REINPLACE_CMD} -e 's|<path>|${PREFIX}|' \
		 ${WRKSRC}/src/definitions/definitions.${def}
.endfor

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/* ${STAGEDIR}${EXAMPLESDIR}
	${SED} -i '' 's,${STAGEDIR},,g' ${STAGEDIR}${PREFIX}/bin/definitions.?
	${RM} -f ${STAGEDIR}${PREFIX}/CDFLeapSeconds.txt

.include <bsd.port.mk>
