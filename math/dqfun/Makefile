PORTNAME=	dqfun
DISTVERSIONPREFIX=v
DISTVERSION=	03
CATEGORIES=	math
MASTER_SITES=	https://www.davidhbailey.com/dhbsoftware/

MAINTAINER=	fortran@FreeBSD.org
COMMENT=	Double-quad precision package with special functions
WWW=		https://crd-legacy.lbl.gov/~dhbailey/mpdist

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/DISCLAIMER.txt

USES=		fortran

BINARY_ALIAS=	gfortran=${FC}
FFLAGS+=	-O3
BUILD_WRKSRC=	${WRKSRC}/fortran

OPTIONS_DEFINE=	DOCS EXAMPLES

pre-configure:
.for f in gnu-complib-dq.scr gnu-complink-dq.scr
	${REINPLACE_CMD} -e 's|-O3|${FFLAGS}|' ${BUILD_WRKSRC}/${f}
.endfor

do-build:
	cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ./gnu-complib-dq.scr

do-build-EXAMPLES-on:
	cd ${BUILD_WRKSRC} &&	\
		${SETENV} ${MAKE_ENV} ./gnu-complink-dq.scr tpslqm1dq

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include
	cd ${BUILD_WRKSRC} &&	\
	${INSTALL_DATA} *.mod ${STAGEDIR}${PREFIX}/include

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${BUILD_WRKSRC} &&	\
	${INSTALL_PROGRAM} tpslqm1dq ${STAGEDIR}${EXAMPLESDIR}	&&	\
	${INSTALL_DATA} tpslqm1dq.f90 ${STAGEDIR}${EXAMPLESDIR}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README-dqfun.txt ${STAGEDIR}${DOCSDIR}
	cd ${BUILD_WRKSRC} &&	\
	${INSTALL_DATA} *.ref.txt ${STAGEDIR}${DOCSDIR}

do-test:
	cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ./gnu-dqfun-tests.scr

.include <bsd.port.mk>
