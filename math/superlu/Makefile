# Created by: Pedro Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	superlu
PORTVERSION=	5.2.2
CATEGORIES=	math
MASTER_SITES=	https://portal.nersc.gov/project/sparse/superlu/ \
		https://portal.nersc.gov/project/sparse/xiaoye-web/:doc
DISTNAME=	${PORTNAME}_${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	robert.ayrapetyan@gmail.com
COMMENT=	Library of routines for performing sparse factorization

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/License.txt

USES=		cmake fortran pkgconfig
USE_LDCONFIG=	yes

CMAKE_ON=	USE_XSDK_DEFAULTS
CMAKE_OFF=	enable_tests

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=		DOCS EXAMPLES
OPTIONS_SINGLE=		BLAS
OPTIONS_SINGLE_BLAS=	ATLAS GOTOBLAS OPENBLAS REFERENCE
OPTIONS_DEFAULT=	REFERENCE

ATLAS_USES=		blaslapack:atlas
ATLAS_CMAKE_ON=		-DBLA_VENDOR:STRING="ATLAS"
DOCS_DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			${SLU_DOCS:S/$/:doc/}
DOCS_EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
GOTOBLAS_DESC=		GotoBLAS blas implementation
GOTOBLAS_USES=		blaslapack:gotoblas
GOTOBLAS_CMAKE_ON=	-DBLA_VENDOR:STRING="Goto"
OPENBLAS_USES=		blaslapack:openblas
OPENBLAS_CMAKE_ON=	-DBLA_VENDOR:STRING="OpenBLAS"
REFERENCE_DESC=		Reference blas implementation
REFERENCE_USES=		blaslapack
REFERENCE_CMAKE_ON=	-DBLA_VENDOR:STRING="Generic"

SLU_DOCS=	SLU_general.ps.gz slu_ilu.pdf simax-29176.pdf

post-patch:
	@${REINPLACE_CMD} -e \
		'/CMAKE_C_FLAGS_RELEASE/s|^|#|' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e \
		'/FFLAGS/s|FATAL_ERROR|WARNING|' ${WRKSRC}/cmake/XSDKDefaults.cmake

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${SLU_DOCS} \
		${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/DOC && ${COPYTREE_SHARE} "html ug.pdf" \
		${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/EXAMPLE && ${INSTALL_DATA} * ${STAGEDIR}${EXAMPLESDIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/FORTRAN
	(cd ${WRKSRC}/FORTRAN && ${INSTALL_DATA} * ${STAGEDIR}${EXAMPLESDIR}/FORTRAN)

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -Denable_tests:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
