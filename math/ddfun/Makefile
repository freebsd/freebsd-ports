PORTNAME=	ddfun
DISTVERSIONPREFIX=v
DISTVERSION=	03
CATEGORIES=	math
MASTER_SITES=	https://www.davidhbailey.com/dhbsoftware/

MAINTAINER=	fortran@FreeBSD.org
COMMENT=	Double-double package with special functions
WWW=		https://crd-legacy.lbl.gov/~dhbailey/mpdist

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/DISCLAIMER.txt

USES=		fortran

BINARY_ALIAS=	gfortran=${FC}
FFLAGS+=	-O3
BUILD_WRKSRC=	${WRKSRC}/fortran

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.pre.mk>

pre-configure:
.for f in gnu-complib-dd.scr gnu-complink-dd.scr
	${REINPLACE_CMD} -e 's|-O3|${FFLAGS}|' ${BUILD_WRKSRC}/${f}
.endfor
.if ${FORTRAN_DEFAULT} == flang
# https://github.com/llvm/llvm-project/issues/158436
	${REINPLACE_CMD} -e 's|-fno-expensive-optimizations||g' ${BUILD_WRKSRC}/gnu-complib-dd.scr
.endif

do-build:
	cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ./gnu-complib-dd.scr

do-build-EXAMPLES-on:
	cd ${BUILD_WRKSRC} &&	\
		${SETENV} ${MAKE_ENV} ./gnu-complink-dd.scr tpslqm1dd

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include
	cd ${BUILD_WRKSRC} &&	\
	${INSTALL_DATA} *.mod ${STAGEDIR}${PREFIX}/include

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${BUILD_WRKSRC} &&	\
	${INSTALL_PROGRAM} tpslqm1dd ${STAGEDIR}${EXAMPLESDIR}	&&	\
	${INSTALL_DATA} tpslqm1dd.f90 ${STAGEDIR}${EXAMPLESDIR}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README-ddfun.txt ${STAGEDIR}${DOCSDIR}
	cd ${BUILD_WRKSRC} &&	\
	${INSTALL_DATA} *.ref.txt ${STAGEDIR}${DOCSDIR}

do-test:
	cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ./gnu-ddfun-tests.scr

.include <bsd.port.post.mk>
