PORTNAME=	qxfun
DISTVERSIONPREFIX=v
DISTVERSION=	01
CATEGORIES=	math
MASTER_SITES=	https://www.davidhbailey.com/dhbsoftware/

MAINTAINER=	fortran@FreeBSD.org
COMMENT=	Quad precision package with special functions
WWW=		https://crd-legacy.lbl.gov/~dhbailey/mpdist

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/DISCLAIMER.txt

USES=		fortran

BINARY_ALIAS=	gfortran=${FC}
FFLAGS+=	-O3
BUILD_WRKSRC=	${WRKSRC}/fortran

OPTIONS_DEFINE=	DOCS EXAMPLES

pre-configure:
.for f in gnu-complib-qx.scr gnu-complink-qx.scr
	${REINPLACE_CMD} -e 's|-O3|${FFLAGS}|' ${BUILD_WRKSRC}/${f}
.endfor

do-build:
	cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ./gnu-complib-qx.scr

do-build-EXAMPLES-on:
	cd ${BUILD_WRKSRC} &&	\
		${SETENV} ${MAKE_ENV} ./gnu-complink-qx.scr tpslqm1qx

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include
	cd ${BUILD_WRKSRC} &&	\
	${INSTALL_DATA} *.mod ${STAGEDIR}${PREFIX}/include

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${BUILD_WRKSRC} &&	\
	${INSTALL_PROGRAM} tpslqm1qx ${STAGEDIR}${EXAMPLESDIR}	&&	\
	${INSTALL_DATA} tpslqm1qx.f90 ${STAGEDIR}${EXAMPLESDIR}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README-qxfun.txt ${STAGEDIR}${DOCSDIR}
	cd ${BUILD_WRKSRC} &&	\
	${INSTALL_DATA} *.ref.txt ${STAGEDIR}${DOCSDIR}

do-test:
	cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ./gnu-qxfun-tests.scr

.include <bsd.port.mk>
